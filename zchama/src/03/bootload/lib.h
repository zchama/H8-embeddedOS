/**
 * lib.h
 */
#ifndef _LIB_H_
#define _LIB_H_
int putc(unsigned char c);    /** send one charactor */   
int puts(unsigned char* str); /** send charactors */

void* memset(void* b, int c, long len); /** void   */
void* memcpy(void* dst, const void* src, long len);
int  memcmp(const void* b1, const void* b2, long len);

int  strlen(const char* str);
char* strcpy(char* dst, const char* src);
int strcmp(const char* s1, const char* s2);
int strncmp(const char* s1, const char* s2, int len);

int puxval(unsigned long value, int column); /** purint hexa value*/

#endif // _LIB_H_
