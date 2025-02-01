#!/bin/bash
echo "Compiling main.c to main.o"
gcc -m32 -c main.c -o main.o
echo "Linking object files to create kernel.bin"
ld -m elf_i386 -T link.ld -o kernel.bin main.o
echo "Done"
read -p "Press enter to continue"