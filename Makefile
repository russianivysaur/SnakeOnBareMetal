DEBUG = ./build/debug.o

all: ./build/snake.os


./build/snake.os: ./build/boot.o ./build/kernel.o
	i686-elf-ld -g -T linker.ld -o $(DEBUG) $^
	i686-elf-gcc -g -T linker.ld -o $@ -ffreestanding -O2 -nostdlib $^ -lgcc


./build/boot.o: ./src/boot/boot.asm
	nasm -f elf -o $@ $<

./build/kernel.o: ./src/kernel/kernel.c
	i686-elf-gcc -g -c $< -o $@ -std=gnu99 -ffreestanding -O2 -Wall -Wextra


clean:
	rm -rf build/*