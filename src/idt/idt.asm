global load_idt
global handler
extern c_handler

handler:
      push eax
      push ebx
      push ecx
      push edx
      push esp
      push ebp
      call c_handler
      pop ebp
      pop esp
      pop edx
      pop ecx
      pop ebx
      pop eax
      add esp,8
      iret

load_idt:
      mov eax,[esp+4]
      lidt[eax]
      ret