#include <stdint.h>
#ifndef IDT_H
#define IDT_H
#define IDT_SIZE 256
struct IDTDescriptor{
  uint32_t offset;
  uint32_t size;
}__attribute__((packed));

struct GateDescriptor{
  uint16_t offset_1;
  uint16_t segment_selector;
  uint8_t reserved;
  uint8_t flags;
  uint16_t offset_2;
}__attribute__((packed));

void init_idt();
void c_handler();
#endif
