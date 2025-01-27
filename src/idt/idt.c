//
// Created by bulbasaur on 25/1/25.
//

#include "idt.h"
#include "../pic/pic.h"
struct GateDescriptor idt_descriptors[IDT_SIZE];
struct IDTDescriptor idt_descriptor;
static char c = '0';

extern void keyboard_handler();
extern void pit_handler();

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

extern void load_idt(struct IDTDescriptor*);

void init_idt() {
  idt_descriptors[0x20] = make_interrupt_descriptor((uint32_t) pit_handler,KERNEL_CODE_SEG);
  idt_descriptors[0x21] = make_interrupt_descriptor((uint32_t) keyboard_handler,KERNEL_CODE_SEG);
  idt_descriptor.size = sizeof(idt_descriptors) - 1;
  idt_descriptor.offset = (uint32_t) &idt_descriptors;
  load_idt(&idt_descriptor);
  init_pic();
}