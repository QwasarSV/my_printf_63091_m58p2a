#include "my_printf.h"

char* ltoa(long num){
    char* string = malloc(sizeof(num)/sizeof(long));
    //since an integer does not hold numbers after the decimal, and does not round, dividing by 10 "peels off" the last number
    int i = 0;
    if(num < 0){
        string[i] = '-';
        num *= -1;
        i++;
    }
    while(num != 0){
        string[i] = '0' + num % 10;
        num /= 10;
        i++;
    }
    return string;
}