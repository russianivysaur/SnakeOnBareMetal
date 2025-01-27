DEBUG = ./build/debug.o

FILES = ./build/boot.o ./build/kernel.o ./build/gdt.o ./build/gdt_asm.o ./build/idt.o ./build/idt_asm.o ./build/io_asm.o ./build/handlers.o ./build/io.o ./build/pic.o ./build/snake.o ./build/framebuffer.o

CC = i686-elf-gcc
AS = nasm
LD = i686-elf-ld

all: ./build/snake.os

./build/snake.os: $(FILES)
	$(LD) -g -T linker.ld -o $(DEBUG) $^
	$(CC) -g -T linker.ld -o $@ -ffreestanding -O0 -nostdlib $^ -lgcc


./build/boot.o: ./src/boot/boot.asm
	$(AS) -f elf -o $@ $<

./build/kernel.o: ./src/kernel/kernel.c
	$(CC) -g -c $< -o $@ -std=gnu99 -ffreestanding -O2 -Wall -Wextra


./build/gdt_asm.o: ./src/gdt/gdt.asm
	$(AS) -f elf -o $@ $<

./build/gdt.o: ./src/gdt/gdt.c
	$(CC) -g -c $< -o $@ -std=gnu99 -ffreestanding -O2 -Wall -Wextra


./build/idt_asm.o: ./src/idt/idt.asm
	$(AS) -g -f elf -o $@ $<

./build/idt.o: ./src/idt/idt.c
	$(CC) -g -c $< -o $@ -std=gnu99 -ffreestanding -O2 -Wall -Wextra


./build/io_asm.o: ./src/io/io.asm
	$(AS) -g -f elf -o $@ $<

./build/io.o: ./src/io/io.c
	$(CC) -g -c $< -o $@ -std=gnu99 -ffreestanding -O2 -Wall -Wextra

./build/pic.o: ./src/pic/pic.c
	$(CC) -g -c $< -o $@ -std=gnu99 -ffreestanding -O2 -Wall -Wextra


./build/handlers.o: ./src/idt/handlers.c
	$(CC) -g -c $< -o $@ -std=gnu99 -ffreestanding -O2 -Wall -Wextra


./build/snake.o: ./src/snake/snake.c
	$(CC) -g -c $< -o $@ -std=gnu99 -ffreestanding -O2 -Wall -Wextra


./build/framebuffer.o: ./src/framebuffer/framebuffer.c
	$(CC) -g -c $< -o $@ -std=gnu99 -ffreestanding -O2 -Wall -Wextra

clean:
	rm -rf build/*