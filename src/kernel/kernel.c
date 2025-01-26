//
// Created by bulbasaur on 25/1/25.
//

#include "../gdt/gdt.h"
#include "../idt/idt.h"

void kernel_main(){
  init_gdt();
  init_idt();
}
