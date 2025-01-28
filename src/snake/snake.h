//
// Created by bulbasaur on 27/1/25.
//
#include <stdint.h>
#include <stdbool.h>
#ifndef SNAKE_H
#define SNAKE_H
#define MAX_LENGTH 20
#define HEIGHT 25
#define WIDTH 80
enum Directions{
  UP,DOWN,LEFT,RIGHT
};

struct SnakePiece{
  uint32_t row;
  uint32_t col;
};


struct Snake{
  enum Directions direction;
  uint32_t length;
  bool is_running;
  struct SnakePiece pieces[20];
};

struct Snake move(struct Snake);
struct Snake NewSnake(uint32_t);
struct Snake change_direction(enum Directions,struct Snake);

#endif //SNAKE_H
