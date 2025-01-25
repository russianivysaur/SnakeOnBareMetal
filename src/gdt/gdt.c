#include "gdt.h"

extern void load_gdt(struct GDTDescriptor*);
struct SegmentDescriptor gdt_descriptors[GDT_SIZE];
struct GDTDescriptor gdt_descriptor;
struct SegmentDescriptor make_descriptor(uint32_t base,
                                         uint32_t limit,
                                         uint8_t access_byte,
                                         uint8_t flags) {
  struct SegmentDescriptor descriptor;
  descriptor.limit_1 = (limit & 0x0000ffff);
  descriptor.base_1 = (base &   0x0000ffff);
  descriptor.base_2 = (base &   0x00ff0000);
  descriptor.access_byte = access_byte;
  descriptor.limit_2_and_flags = (limit & 0x000f0000) | (flags << 4);
  descriptor.base_3 = (base &   0xff000000);
  return descriptor;
}


void init_gdt(){
  gdt_descriptors[0] = make_descriptor(0,0,0,0);
  // kernel code segment
  gdt_descriptors[1] = make_descriptor(0,0xFFFFFFFF,0x9A,0xC);

  //kernel data seg
  gdt_descriptors[2] = make_descriptor(0,0xFFFFFFFF,0x92,0xC);


  gdt_descriptor.size = sizeof(gdt_descriptors) - 1;
  gdt_descriptor.offset = (uint32_t) &gdt_descriptors[0];
  load_gdt(&gdt_descriptor);
}