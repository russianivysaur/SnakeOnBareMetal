//
// Created by bulbasaur on 25/1/25.
//

#include "idt.h"




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
  memory[0] = 'a';
}

extern void load_idt(struct IDTDescriptor*);

void init_idt() {
  idt_descriptor.size = sizeof(idt_descriptors) - 1;
  idt_descriptor.offset = (uint32_t) &idt_descriptors;
  load_idt(&idt_descriptor);
}