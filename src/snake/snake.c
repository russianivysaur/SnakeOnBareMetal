//
// Created by bulbasaur on 27/1/25.
//
#include <stddef.h>
#include "snake.h"


struct Snake NewSnake(uint32_t length){
  struct Snake snake;
  snake.current_direction = UP;

  snake.length = 1;

  //head
  snake.pieces[0].current_pos = 0;
  snake.pieces[0].next = -1;
  snake.pieces[0].prev = -1;


  //rest of the body
  for(uint32_t i=1;i<=length-1;i++){
    snake.pieces[i].current_pos = 0;
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
  for(uint32_t i=1;i<=snake.length-1;i++){
    snake.pieces[i].current_pos = snake.pieces[i-1].current_pos;
  }
  snake.pieces[0].current_pos += 2;
  return snake;
}


struct Snake change_direction(enum Directions direction,struct Snake snake) {
  snake.current_direction = direction;
  return snake;
}


bool is_running(struct Snake snake){
  return snake.is_running;
}