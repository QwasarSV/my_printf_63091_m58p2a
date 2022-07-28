#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

char* dec_2_hex_to_a(int dec){

char* string = calloc(sizeof(char), 3);

int i = 0;
while(dec != 0){
    if((dec % 16) >= 10 && (dec % 16) <= 15){
        string[i] = (dec % 16) + 55;
        dec /= 16;
    }else{
        string[i] = '0' + dec % 16;
        dec /= 16;
    }
    i++;
}
return string;
}

char* reverse_string(char* string){
    char temp;
    int length = strlen(string);
    int midpoint = length/2;
    for(int i = 0;i < midpoint;i++){
        temp = string[i];
        string[i] = string[length - 1 - i];
        string[length - 1 - i] = temp;
    }
    return string;
}

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

char* itoa(int num){
    char* string = malloc(sizeof(num)/sizeof(int));

    //since an integer does not hold numbers after the decimal, and does not round, dividing by 10 "peels off" the last number
    int i = 0;
    while(num != 0){
        string[i] = '0' + num % 10;
        num /= 10;
        i++;
    }
    return string;
}

int my_printf(char * restrict format, ...)
{
    va_list ap;

    va_start(ap,format);

    int format_length = strlen(format);

    int i = 0;
    while(i < format_length){
        if(format[i] == '%'){
            char format_char = format[i+1];
            switch(format_char){
                case 's':
                {
                    const char *buff = va_arg(ap,const char*);
                    write(1,buff,strlen(buff));
                    i++;//increment i twice when format strings are involved so the format character (s,d,c,etc.) are not written to stdput
                    break;
                }
                case 'c':
                {
                    const char *buff = va_arg(ap,const char*);
                    write(1,buff,strlen(buff));
                    i++;
                    break;
                }
                case 'd':
                case 'u':
                {
                    int buff = va_arg(ap,int);
                    char* string = reverse_string(itoa(buff));
                    write(1,string,strlen(string));
                    i++;
                    break;
                }
                case 'o':
                {
                    int buff = va_arg(ap,int);
                    char* string = reverse_string(dec_2_oct_to_a(buff));
                    write(1,string,strlen(string));
                    i++;
                    break;
                }
                case 'x':
                {
                    int buff = va_arg(ap,int);
                    char* string = reverse_string(dec_2_hex_to_a(buff));
                    write(1,string,strlen(string));
                    i++;
                    break;
                }
            }
        }else{
            const char* single_char = &format[i];
            write(1,single_char,1);//will only print out characters, which are 1 byte in size
        }
    i++;
    }
    va_end(ap);
    return EXIT_SUCCESS;
}

int main(){
    my_printf("hello world\n");
    my_printf("%s\n", "hello");
    my_printf("%s -- %d\n", "hello", 18);
    my_printf("%d\n", 18);
    my_printf("%o\n", 9);
    my_printf("%u\n", 18);
    my_printf("%x -- %s\n",2147483647,"yessirr");
    


    return 0;
}

