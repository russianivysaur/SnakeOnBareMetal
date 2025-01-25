global load_gdt
CODE_SEG equ 0x08
DATA_SEG equ 0x10

load_gdt:
       mov eax,[esp+4]
       lgdt[eax]
       mov eax,0
       mov eax,DATA_SEG
       mov ss,ax
       mov es,ax
       mov fs,ax
       mov gs,ax
       mov ds,ax
       jmp CODE_SEG:jump

jump:
    ret