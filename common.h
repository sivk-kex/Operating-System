#ifndef __COMMON_H
#define __COMMON_H

extern unsigned char *memcpy(unsigned char *dest, unsigned char *src, int count);
extern unsigned char *memcpy(unsigned char *dest, unsigned char *src, int count);
extern unsigned short *memsetw(unsigned short *dest, unsigned short val, int count); 
extern int strlen(const char *str); 
extern unsigned char inportb(unsigned short _port);
extern void outportb(unsigned short _port, unsigned char _data); 

#endif
