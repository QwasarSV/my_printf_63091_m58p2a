#include "my_printf.h"
char* reverse_string(char* string){
    char temp;
    int length = strlen(string);
    int midpoint = length/2;
    int i = 0;
    if(string[0] == '-'){
        i = 1;
        length +=1;//needed to offest the -1 in below loop
        midpoint+=1;//midpoint shifted one to the right
    }
    for(;i < midpoint;i++){
        temp = string[i];
        string[i] = string[length - 1 - i];//length -1 to account for zero indexing
        string[length - 1 - i] = temp;
    }
    return string;
}