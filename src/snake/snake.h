//
// Created by bulbasaur on 27/1/25.
//
#include <stdint.h>
#include <stdbool.h>
#ifndef SNAKE_H
#define SNAKE_H

enum Directions{
  UP,DOWN,LEFT,RIGHT
};

struct SnakePiece{
  uint32_t current_pos;
  uint32_t next_pos;
  int32_t next;
  int32_t prev;
};


struct Snake{
  enum Directions current_direction;
  uint32_t current_length;
  uint32_t max_length;
  bool is_running;
  struct SnakePiece pieces[20];
};

struct Snake move(struct Snake);

#endif //SNAKE_H
