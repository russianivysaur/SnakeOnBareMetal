global load_idt
global handler
extern c_handler


handler:
    pusha
    call c_handler
    popa
    iret

load_idt:
      mov ebx,[esp+4]
      lidt[ebx]
      ret