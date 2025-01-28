#include <stdint.h>
#include "../pic/pic.h"
#include "../snake/snake.h"
#include "../framebuffer/framebuffer.h"
extern struct Snake snake;

uint32_t ticks = 0;
uint32_t target = 400;
void c_pit_handler() {
    ticks++;
    if(ticks == target){
      ticks = 0;
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
            snake = change_direction(UP,snake);
        break;
        case 75: //left
            memory[0] = 'l';
            snake = change_direction(LEFT,snake);
        break;
        case 77: //right
            memory[0] = 'r';
            snake = change_direction(RIGHT,snake);
        break;
        case 80: //down
            memory[0] = 'd';
            snake = change_direction(DOWN,snake);
        break;
    }
    update_display(snake);
    pic_ack();
}