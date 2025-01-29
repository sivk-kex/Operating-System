echo Now assembling, compiling and linking kernel 
nasm -f aout -o start.o start.asm
rem This is a reminder to add 

ld -T link.ld -o kernel.bin start.o 
echo done 
pause 