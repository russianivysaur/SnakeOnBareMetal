global init
extern kernel_main


MAGIC equ 0x1BADB002
FLAGS equ 0x0
CHECKSUM equ -MAGIC

section .bss
align 4
kernel_stack:
     resb 4096


section .text
align 4
dd MAGIC
dd FLAGS
dd CHECKSUM



init:
    mov esp,kernel_stack+4096
    call kernel_main

.loop:
    jmp $