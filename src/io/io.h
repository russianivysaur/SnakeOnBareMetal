//
// Created by bulbasaur on 26/1/25.
//
#include <stdint.h>
#ifndef IO_H
#define IO_H
extern uint8_t inb(uint16_t port);
extern uint16_t inw(uint16_t port);
extern void outb(uint8_t value,uint16_t port);
extern void outw(uint16_t value,uint16_t port);
#endif //IO_H
