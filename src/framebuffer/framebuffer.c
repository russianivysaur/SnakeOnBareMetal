//
// Created by bulbasaur on 27/1/25.
//

#include "framebuffer.h"
#include "../snake/snake.h"

char* memory = (char*) 0xB8000;
void cls(){
  int index = 0;
  for(int row=0;row<HEIGHT;row++){
    for(int col=0;col<WIDTH;col++){
      memory[index] = ' ';
      index += 2;
    }
  }
}



void update_display(struct Snake snake){
  cls();

  for(uint32_t i=0;i<snake.length;i++){
    memory[snake.pieces[i].current_pos] = 'a';
  }
}