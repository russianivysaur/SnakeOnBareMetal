#include <stdint.h>
#include "../pic/pic.h"
#include "../snake/snake.h"
#include "../framebuffer/framebuffer.h"

static char c = '0';
extern struct Snake snake;

uint32_t ticks = 0;
uint32_t target = 400;
void c_pit_handler() {
    ticks++;
    if(ticks == target){
      ticks = 0;
      ((char*)0xB8000)[0] = c;
      snake = move(snake);
      update_display(snake);
    }
    pic_ack();
}



void c_keyboard_handler() {
    char* memory = (char*)0xB8000;
    uint8_t key = read_keyboard_data();
    switch(key){
        case 72: //up
            memory[0] = 'u';
        break;
        case 75: //left
            memory[0] = 'l';
        break;
        case 77: //right
            memory[0] = 'r';
        break;
        case 80: //down
            memory[0] = 'd';
        break;
    }
    pic_ack();
}