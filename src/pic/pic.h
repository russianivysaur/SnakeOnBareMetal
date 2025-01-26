//
// Created by bulbasaur on 26/1/25.
//
#include <stdint.h>
#ifndef PIC_H
#define PIC_H
void init_pic();
void pic_ack();
uint8_t read_keyboard_data();

#endif //PIC_H
