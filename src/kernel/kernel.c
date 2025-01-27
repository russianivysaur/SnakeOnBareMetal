//
// Created by bulbasaur on 25/1/25.
//

#include "../gdt/gdt.h"
#include "../idt/idt.h"
#include "../snake/snake.h"

struct Snake snake;

void kernel_main(){
  init_gdt();
  init_idt();
}
