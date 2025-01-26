DEBUG = ./build/debug.o

all: ./build/snake.os


./build/snake.os: ./build/boot.o ./build/kernel.o ./build/gdt.o ./build/gdt_asm.o ./build/idt.o ./build/idt_asm.o
	i686-elf-ld -g -T linker.ld -o $(DEBUG) $^
	i686-elf-gcc -g -T linker.ld -o $@ -ffreestanding -O0 -nostdlib $^ -lgcc


./build/boot.o: ./src/boot/boot.asm
	nasm -f elf -o $@ $<

./build/kernel.o: ./src/kernel/kernel.c
	i686-elf-gcc -g -c $< -o $@ -std=gnu99 -ffreestanding -O2 -Wall -Wextra


./build/gdt_asm.o: ./src/gdt/gdt.asm
	nasm -f elf -o $@ $<

./build/gdt.o: ./src/gdt/gdt.c
	i686-elf-gcc -g -c $< -o $@ -std=gnu99 -ffreestanding -O2 -Wall -Wextra


./build/idt_asm.o: ./src/idt/idt.asm
	nasm -g -f elf -o $@ $<

./build/idt.o: ./src/idt/idt.c
	i686-elf-gcc -g -c $< -o $@ -std=gnu99 -ffreestanding -O2 -Wall -Wextra


clean:
	rm -rf build/*