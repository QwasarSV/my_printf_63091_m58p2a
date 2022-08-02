#include "my_printf.h"

int my_printf(char * restrict format, ...)
{
    va_list ap;

    va_start(ap,format);

    int format_length = strlen(format);
    int length = 0;
    int i = 0;
    while(i < format_length){
        if(format[i] == '%'){
            char format_char = format[i+1];
            switch(format_char)
            {
                case 's':
                {
                    char *buff = va_arg(ap,char*);
                    length += write(1,buff,strlen(buff));
                    i++;//increment i twice when format strings are involved so the format character (s,d,c,etc.) are not written to stdput
                    break;
                }
                case 'c':
                {
                    int buff = va_arg(ap,int);
                    printf("%c",(char)buff);
                    // write(1,buff,1);
                    
                    length++;
                    i++;
                    break;
                }
                case 'd':
                case 'u':
                {   
                    int buff = va_arg(ap,int);
                    char* string = reverse_string(itoa(buff));
                    length += write(1,string,strlen(string));
                    i++;
                    break;
                }
                case 'o':
                {
                    int buff = va_arg(ap,int);
                    char* string = reverse_string(dec_2_oct_to_a(buff));
                    length += write(1,string,strlen(string));
                    i++;
                    break;
                }
                case 'x':
                {
                    char* hex = "0x10";
                    int buff = va_arg(ap,int);
                    char* string = reverse_string(dec_2_hex_to_a(buff));
                    length += write(1,hex,strlen(hex));
                    length += write(1,string,strlen(string));
                    i++;
                    break;
                }
                case 'p':
                {   
                    void* input = va_arg(ap,void*);
                    int* i = (int*)&input;

                    char* hex = "0x10";
                    if(*i < 0){
                        *i *= -1;
                    }

                    char* mem_string = reverse_string(dec_2_hex_to_a(*i));
                    length += write(1,hex,strlen(hex));
                    length += write(1,mem_string,strlen(mem_string));
                    i++;
                    break;
                }
                
            }
        }
        else if(format[i] != '%' && format[i -1] != '%'){
        
        char* single_char = &format[i];
        length += write(1,single_char,1);
        }
        i++;

    }
    
    va_end(ap);
    return length;
}

