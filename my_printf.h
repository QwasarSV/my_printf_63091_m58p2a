#ifndef MY_PRINTF_H
#define MY_PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

int my_printf(char * restrict format, ...);

char* itoa(int num);

char* reverse_string(char* string);

char* dec_2_oct_to_a(int num);

char* dec_2_hex_to_a(int dec);

char* ltoa(long num);

#endif
