#include "common.h"

unsigned char *memcpy(unsigned char *dest, unsigned char *src, int count){ 
    unsigned char *d = (unsigned char*) dest  ; 
    const unsigned char *s = (const unsigned char * )src;
    while(count--){
        *d++=*s++; 
    } 
    return dest; 

}
unsigned char *memset(unsigned char *dest, unsigned char val, int count){ 
            unsigned char *d = (unsigned char*)dest; 
            const unsigned char v = (const unsigned char)val;
            while(count--){ 
                *d++=v; 
            }
            return dest; 
}

unsigned short *memsetw(unsigned short *dest, unsigned short val, int count){ 
            unsigned short *d = (unsigned short *)dest; 
            const unsigned short v = (const unsigned short )val ; 
            while(count--){ 
                *d++=v; 
            }
            return dest; 
}

int strlen(const char *str){ 
        int count =0 ; 
        while(*str !='\0'){ 
            ++count;++str; 
        }
        return count; 
}


unsigned char inportb(unsigned short _port){ 

    unsigned char rv; 
    __asm __volatile("inb %1, %0":"=a" (rv): "dN" (_port) ); 
    return rv; 
}

void outportb(unsigned short _port, unsigned char _data){ 
    __asm __volatile("outb %1, %0": :"dN" (_port) , "a" (_data)); 
}
int main(){ 
    init_video(); 
    puts((unsigned char *)"hello world");
    //for(;;); //inf loop
    return 0; 
}
