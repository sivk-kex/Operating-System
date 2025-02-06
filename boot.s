BITS 32 

global start 
extern kmain 

;GRUB Boot Signs 
SECTION .text 
    ALIGN 4 
    DD 0x1BADB002
    DD 0x00000000
    DD (0x1BADB002 + 0x00000000) 


start : 
    CLI 
    MOV esp, _sys_stack 
    CALL kmain 
    HLT 


halt : 
    CLI 
    HLT 
    JMP halt


SECTION .bss 
    RESB 8192

_sys_stack: 