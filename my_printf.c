#include "my_printf.h"

int my_printf(char * restrict format, ...)
{
    va_list ap;

    va_start(ap,format);

    int format_length = strlen(format);

    int i = 0;
    while(i < format_length){
        if(format[i] == '%'){
            char format_char = format[i+1];
            switch(format_char)
            {
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
                {   
                    int buff = va_arg(ap,int);
                    char* string = reverse_string(itoa(buff));
                    write(1,string,strlen(string));
                    i++;
                    break;
                }
                case 'u':
                {   /////need to make another itoa function to take in type long
                    int unsined_input = va_arg(ap,int);
                    if(unsined_input < 0)
                    {
                        long unsind_int = (long)(UINT_MAX + unsined_input + 1);
                        char* unsind_int_string = reverse_string(ltoa(unsind_int));
                        write(1,unsind_int_string,strlen(unsind_int_string));
                        i++;
                        break;
                    }                    
                    char* string = reverse_string(itoa(unsined_input));
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
                    char* hex = "0x10";
                    int buff = va_arg(ap,int);
                    char* string = reverse_string(dec_2_hex_to_a(buff));
                    write(1,hex,strlen(hex));
                    write(1,string,strlen(string));
                    i++;
                    break;
                }
                case 'p':
                {   
                    void* input = va_arg(ap,void*);
                    int* i = (int*)&input;

                    if(*i < 0){
                        *i *= -1;
                    }
                    char* hex = "0x10";
                    char* mem_string = reverse_string(dec_2_hex_to_a(*i));
                    write(1,hex,strlen(hex));
                    write(1,mem_string,strlen(mem_string));
                    i++;
                    break;
                }
                
            }
        }

        else if(format[i] != 'p')//may printf p simply because it is the last case statement. check later to see if putting the action below in a default statement works better
        {
            char* single_char = &format[i];
            write(1,single_char,1);//will only print out characters, which are 1 byte in size
        }
        i++;
    }
    va_end(ap);
    return EXIT_SUCCESS;
}

