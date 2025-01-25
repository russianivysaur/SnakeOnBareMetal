make clean
make all
mkdir -p ./build/grub/boot/grub
cp ./build/snake.os ./build/grub/boot/snake.os
cp grub.cfg ./build/grub/boot/grub/grub.cfg
grub-mkrescue -o ./build/snake.os ./build/grub
