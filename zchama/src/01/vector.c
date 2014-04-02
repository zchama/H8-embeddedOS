/**
 * vector.c
 * define interupt vectors
 */

#include "defines.h"
/**
 * extern functions;
 */
extern void start(void);


/**
 * set interupt vectros
 */
void(*vectors[])(void) = {
 start, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
 NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL,
 NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL,
 NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL,
 NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL,
 NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL,
 NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL,
}; 

