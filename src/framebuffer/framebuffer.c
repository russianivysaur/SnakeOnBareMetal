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
    uint32_t prev_rows = snake.pieces[i].row;
    uint32_t prev_col = snake.pieces[i].col;
    uint32_t prev_blocks = prev_rows * WIDTH + prev_col;
    memory[prev_blocks*2] = '*';
  }
}