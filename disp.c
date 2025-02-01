#include "common.h" 

unsigned short* textptr;
int attrib=0x0F,csr_y=0,csr_x=0; 

void scroll(void){ 

    unsigned short blank, temp;
    blank = 0x20 | (attrib << 8);  
    if(csr_y>=25){ 
        temp = csr_y-25+1; 
        memcpy(textptr, textptr + temp * 80, (25-temp)*80 * 2);
        memsetw(textptr + (temp -25 )*80, blank , 80); 
        csr_y = 25-1; 
    }
}

void move_csr(void){ 

    unsigned temp; 
    temp = csr_y*80+csr_x; 

    //from vga docs  by bran 
     outportb(0x3D4, 14);
    outportb(0x3D5, temp >> 8);
    outportb(0x3D4, 15);
    outportb(0x3D5, temp);
}

void cls (void){ 

    unsigned blank ; 
    int i; 
    blank = 0x20 | (attrib << 8); 

    for(i=0;i<25;++i){
        memsetw(textptr + i *80, blank,80); 
    } 
    csr_x=0;csr_y=0; 
    move_csr();
}

//read it from bran's kernel dev 
void putch(unsigned char c){ 

    unsigned short *where; 
    unsigned att = attrib << 8; 
    if(c==0x08){ 
        if(csr_x)csr_x--;
        else if (c==0x09){
            csr_x=(csr_x+8)&~(8-1);
        }
        else if (c=='\r'){
            csr_x=0;
        }
        else if (c=='\n'){
            csr_x=0;++csr_y;
        }
        else if ( c>=' '){ 
            where = textptr + (csr_y*80 + csr_x);
        }
        move_csr();
    }
}
    void puts(unsigned char *text){
        for(int i=0;i<strlen(text);++i){
            putch(text[i]); 
        }
    }

    void settextcolor(unsigned char foreground, unsigned char background){ 
        attrib =  (background << 4) | (foreground & 0x0F);

    }
    void init_video (void){ 
        textptr = (unsigned short*)0xB8000;
        cls();
    }


