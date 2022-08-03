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
                    i+=2;//increment i twice when format strings are involved so the format character (s,d,c,etc.) are not written to stdput
                    break;
                }
                case 'c':
                {
                    char single_c = va_arg(ap,int);
                    // printf("%c",single_c);
                    write(1,&single_c,1);
                    length++;
                    i+=2;
                    break;
                }
                case 'd':
                case 'u':
                {   
                    int unsined_input = va_arg(ap,int);
                    if(unsined_input < 0)
                    {
                        long unsind_int = (long)(UINT_MAX + unsined_input + 1);
                        char* unsind_int_string = reverse_string(ltoa(unsind_int));
                        length += write(1,unsind_int_string,strlen(unsind_int_string));
                        i+=2;
                        break;
                    }                    
                    char* string = reverse_string(itoa(unsined_input));
                    length += write(1,string,strlen(string));
                    i+=2;
                    break;
                }
                case 'o':
                {
                    int buff = va_arg(ap,int);
                    char* string = reverse_string(dec_2_oct_to_a(buff));
                    length += write(1,string,strlen(string));
                    i+=2;
                    break;
                }
                case 'x':
                {
                    int buff = va_arg(ap,int);
                    char* string = reverse_string(dec_2_hex_to_a(buff));
                    length += write(1,string,strlen(string));
                    i+=2;
                    break;
                }
                case 'p':
                {   
                    void* input = va_arg(ap,void*);
                    int* inp = (int*)&input;

                    char* hex = "0x10";
                    if(*inp < 0){
                        *inp *= -1;
                    }

                    char* mem_string = reverse_string(dec_2_hex_to_a(*inp));
                    length += write(1,hex,strlen(hex));
                    length += write(1,mem_string,strlen(mem_string));
                    i+=2;
                    break;
                }
                
            }
        }
        
        if(format[i] != '%' && format[i-1] != '%'){
        char* single_char = &format[i];
        length += write(1,single_char,1);
        i++;
        }

    }
    
    va_end(ap);
    return length;
}

