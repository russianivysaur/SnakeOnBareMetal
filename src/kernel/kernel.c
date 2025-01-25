//
// Created by bulbasaur on 25/1/25.
//

#include "../gdt/gdt.h"
#include "../idt/idt.h"
void loop(){
  int a = 9;
  int c = (a / 9) - 1;
  int d = a/c;
  int e = d + 1;
  while(e){}
}
void kernel_main(){
  init_gdt();
  init_idt();
  loop();
}
