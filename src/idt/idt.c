//
// Created by bulbasaur on 25/1/25.
//

#include "idt.h"
#include "../pic/pic.h"
struct GateDescriptor idt_descriptors[IDT_SIZE];
struct IDTDescriptor idt_descriptor;

extern void handler();

struct GateDescriptor make_interrupt_descriptor(
    uint32_t offset,
    uint16_t segment_selector
){
  struct GateDescriptor descriptor;
   descriptor.offset_1 = (offset & 0x0000ffff);
   descriptor.offset_2 = offset >> 16;
   descriptor.reserved = 0;
   descriptor.segment_selector = segment_selector;
   descriptor.flags = 0x8E;
   return descriptor;
}

void c_handler() {
  char* memory = (char*)0xB8000;
  uint8_t key = read_keyboard_data();
   switch(key){
     case 72: //up
       memory[0] = 'u';
       break;
     case 75: //left
       memory[0] = 'l';
       break;
     case 77: //right
      memory[0] = 'r';
       break;
     case 80: //down
       memory[0] = 'd';
       break;
   }
  pic_ack();
}

extern void load_idt(struct IDTDescriptor*);

void init_idt() {
  idt_descriptors[33] = make_interrupt_descriptor((uint32_t) handler,KERNEL_CODE_SEG);
  idt_descriptor.size = sizeof(idt_descriptors) - 1;
  idt_descriptor.offset = (uint32_t) &idt_descriptors;
  load_idt(&idt_descriptor);
  init_pic();
}