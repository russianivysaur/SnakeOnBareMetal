//
// Created by bulbasaur on 27/1/25.
//
#include <stddef.h>
#include "snake.h"


struct Snake NewSnake(uint32_t length){
  struct Snake snake;
  snake.direction = RIGHT;

  snake.length = 1;

  //head
  snake.pieces[0].row = 0;
  snake.pieces[0].col = 0;
  snake.pieces[0].next = -1;
  snake.pieces[0].prev = -1;


  //rest of the body
  for(uint32_t i=1;i<=length-1;i++){
    snake.pieces[i].row = 0;
    snake.pieces[i].col = 0;
    snake.pieces[i].next = -1;
    //make prev point to previous entry
    snake.pieces[i].prev = i-1;
    //make next pointer to this
    snake.pieces[i-1].next = i;
    snake.length++;
  }

  return snake;
}


struct Snake move(struct Snake snake){
  uint32_t prev_row = snake.pieces[0].row;
  uint32_t prev_col = snake.pieces[0].col;
  uint32_t temp_row = 0;
  uint32_t temp_col = 0;
  for(uint32_t i=1;i<=snake.length-1;i++){
    temp_row = snake.pieces[i].row;
    temp_col = snake.pieces[i].col;
    snake.pieces[i].row = prev_row;
    snake.pieces[i].col = prev_col;
    prev_row = temp_row;
    prev_col = temp_col;
  }
  switch(snake.direction){
    case UP:
      snake.pieces[0].row = (snake.pieces[0].row - 1)%HEIGHT;
      break;
    case DOWN:
      snake.pieces[0].row = (snake.pieces[0].row + 1)%HEIGHT;
      break;
    case LEFT:
      snake.pieces[1].col = (snake.pieces[0].col - 1)%WIDTH;
      break;
    case RIGHT:
      snake.pieces[1].col = (snake.pieces[0].col + 1)%WIDTH;
      break;
  }
  return snake;
}


struct Snake change_direction(enum Directions direction,struct Snake snake) {
  if(direction==UP && (snake.direction==RIGHT || snake.direction==LEFT)){

  }else if (direction==RIGHT && (snake.direction==UP || snake.direction==DOWN)){

  }else if(direction==LEFT && (snake.direction==UP || snake.direction==DOWN)){

  }else if(direction==DOWN && (snake.direction==RIGHT || snake.direction==LEFT)){
     snake.direction = direction;
  }
  return snake;
}


bool is_running(struct Snake snake){
  return snake.is_running;
}