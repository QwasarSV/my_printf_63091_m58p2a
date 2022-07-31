#include "my_printf.h"

char* dec_2_hex_to_a(int dec){

char* string = calloc(sizeof(char), 3);

int i = 0;
while(dec != 0){
    if((dec % 16) >= 10 && (dec % 16) <= 15){
        string[i] = (dec % 16) + 87;
        dec /= 16;
        // printf("%c",string[i]);
    }else{
        string[i] = '0' + dec % 16;
        dec /= 16;
        // printf("%c",string[i]);
    }
    i++;
}
return string;
}