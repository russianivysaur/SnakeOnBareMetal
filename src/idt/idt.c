//
// Created by bulbasaur on 25/1/25.
//

#include "idt.h"
extern void load_idt(struct IDTDescriptor*);
extern void handler();

struct GateDescriptor idt_descriptors[IDT_SIZE];
struct IDTDescriptor idt_descriptor;

struct GateDescriptor make_interrupt_descriptor(
    uint32_t offset,
    uint16_t segment_selector
){
  struct GateDescriptor descriptor;
  descriptor.offset_1 = (offset & 0x0000ffff);
  descriptor.offset_2 = (offset & 0xffff0000);
  descriptor.reserved = 0;
  descriptor.segment_selector = segment_selector;
  descriptor.flags = (0xE) | (1 << 7);
  return descriptor;
}


void init_idt() {
  idt_descriptors[0] = make_interrupt_descriptor((uint32_t) handler,0x08);
  idt_descriptor.size = sizeof(idt_descriptors) - 1;
  idt_descriptor.offset = (uint32_t) &idt_descriptors;
  load_idt(&idt_descriptor);
}

void c_handler() {

}