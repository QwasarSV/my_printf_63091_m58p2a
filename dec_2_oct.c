#include "my_printf.h"

char* dec_2_oct_to_a(int num){
    char* string = malloc(sizeof(num)/sizeof(int));

    int i = 0;
    while(num != 0){
        string[i] = '0' + num % 8;
        num /= 8;
        i++;
    }
    return string;
}