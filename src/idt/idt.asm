global load_idt
global keyboard_handler
global pit_handler
extern c_keyboard_handler
extern c_pit_handler


keyboard_handler:
    pusha
    call c_keyboard_handler
    popa
    iret

pit_handler:
    pusha
    call c_pit_handler
    popa
    iret

load_idt:
      mov ebx,[esp+4]
      lidt[ebx]
      ret