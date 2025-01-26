global outb
global inb
global outw
global inw

outb:
    mov al,[esp+8]
    mov dx,[esp+4]
    out dx,al
    ret

inb:
    mov eax,0
    mov dx,[esp+4]
    in al,dx
    ret


outw:
   mov ax,[esp+8]
   mov dx,[esp+4]
   out dx,ax
   ret


inw:
   mov eax,0
   mov dx,[esp+4]
   in ax,dx
   ret