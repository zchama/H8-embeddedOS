/**
 * lib.c
 * define library function
 */

#include "defines.h"
#include "serial.h"
#include "lib.h"

/**
 * send one charactor
 * @param  c charactor to send
 * @return ??? what is serial_send_byte
 */
int putc(unsigned char c){
  if(c=='\n'){
    serial_send_byte(SERIAL_DEFAULT_DEVICE, '\r');
  }
  return serial_send_byte(SERIAL_DEFAULT_DEVICE, c);
}

/**
 * send charactors 
 * @param srt charactors to send 
 * @return 0
 */
int puts(unsigned char* str){
  while(*str){
    putc(*(str++));
  }
  return 0;
}

/**
 * send hexa val
 */
int putxval(unsigned long value, int column){
  char buf[9];
  char* p;
  p = buf + sizeof(buf) - 1;
  *(p--) = '\0';
  if(!value && !column){
    column++;
  }
  while( value|| column){
    *(p--) = "01234567890abcdef"[value & 0xf];
    value >>= 4;
  }
  if(column) column--;
  puts(p + 1);
  return 0;
}

/**
 * @breif set a data on the memory
 * @param b   start address of memory to write data
 * @param c   data to write
 * @param len length of data to write  
 * @return
 */
void* memset(void* b, int c, long len){
  char* p = b;
  long i = 0;
  for(; i < len; i++){
    p[i] = (char) c;
  }
  return b;  
}
/**
 * @breif copy a data from source to destination
 * @param src  start address of memory to read data
 * @param dst  start address of mempry to read write
 * @param len  length of data to write  
 * @return
 */
void* memcpy(void* dst, const void* src, long len){
  long i =0;
  char* dst_p = dst;
  const char* src_p = src;
  for(; i < len; i++){
    dst_p[i] = src_p[i];
  }
  return dst;
}

/**
 * @breif compare two data
 * @param b1  start address of memory to compare
 * @param b2  start address of mempry to compare
 * @param len  length of data to write
 * @return
 */
int  memcmp(const void* b1, const void* b2, long len){
  int i = 0;
  const char* b1_p = b1;
  const char* b2_p = b2;
  for(; i< len; i++){
    int dif = (int)((unsigned char)b2_p[i] - (unsigned char) b1_p[i]);
    if(dif != 0){
      return dif;
    }
  }
  return 0;
}
/**
 * @breif return length of sring
 * @param str start address of string
 * @return
 */
int  strlen(const char* str){
  int len = 0;
  while(str[len] != '\0'){
    len++;
  }
  return len;
}

/**
 * @breif copy dat from src to dst 
 * @param src source data
 * @param dst destination
 * @return 
 */
char* strcpy(char* dst, const char* src){
  int len = 0;
  while(src[len] != '\0'){
    dst[len] = src[len];
  }
  return dst;   
}
/**
 * @breif compare two string
 * @param  s1 start address of string 
 * @param  s2 start address of string 
 * @return 
 */
int strcmp(const char* s1, const char* s2){
  int i = 0;
  while(s1[i] == '\0' || s2[i] == '\0'){
    int dif = (int)((unsigned char)s2[i] - (unsigned char) s1[i]);
    if(dif != 0){
      return dif;
    }
    i++;
  }
  return 0;   
}

int strncmp(const char* s1, const char* s2, int len){
   int i = 0;
  while(s1[i] == '\0' || s2[i]== '\0' || i >= len){
    int dif = (int)((unsigned char)s2[i] - (unsigned char) s1[i]);
    if(dif != 0){
      return dif;
    }
    i++;
  }
  return 0;   
}

