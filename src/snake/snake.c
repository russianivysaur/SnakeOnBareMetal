//
// Created by bulbasaur on 27/1/25.
//
#include <stddef.h>
#include "snake.h"


struct Snake NewSnake(){
  struct Snake snake;
  snake.max_length = 20;
  snake.current_length = 1;
  snake.current_direction = UP;

  //current head
  struct SnakePiece head;
  head.current_pos = 0;
  head.next = -1;
  head.prev = -1;

  snake.pieces[0] = head;
  return snake;
}


struct Snake move(struct Snake snake){
  return snake;
}


struct Snake change_direction(enum Directions direction,struct Snake snake) {
  snake.current_direction = direction;
  return snake;
}


bool is_running(struct Snake snake){
  return snake.is_running;
}