//
// Created by bulbasaur on 27/1/25.
//
#include <stdint.h>
#include <stdbool.h>
#ifndef SNAKE_H
#define SNAKE_H
#define MAX_LENGTH 20
enum Directions{
  UP,DOWN,LEFT,RIGHT
};

struct SnakePiece{
  uint32_t current_pos;
  int32_t next;
  int32_t prev;
};


struct Snake{
  enum Directions current_direction;
  uint32_t length;
  bool is_running;
  struct SnakePiece pieces[20];
};

struct Snake move(struct Snake);
struct Snake NewSnake(uint32_t);

#endif //SNAKE_H
