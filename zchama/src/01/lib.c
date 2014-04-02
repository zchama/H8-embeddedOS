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


