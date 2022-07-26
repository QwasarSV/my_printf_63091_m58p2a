#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int my_printf(char * restrict format, ...)/*format is the [fixed] argument (variadic function needs at least 1 argument, otherwise, whats the point)
                                            ...elipses indicate to the compiler that any number of arguments may be passed through funciton
                                            ... format will give a clue on how the funciton should be run. for example, it may be the number
                                                of arguments that the funciton should utilize before terminating
                                                ...in this case, format provides the type of the argument(s) that should be written to the standard output,
                                                    as well as any strings that should be printed adjacent the rest of the arguments*/
{
    va_list arg_param;/*va list varible (args) indicates the arguments passed into function
                  ... va_start and va_end act as markers (cursor) of where program is in va_list (kind of like fseek/ftell)*/
    
    va_start(arg_param, format);/*the beggining of variable argument list (va_list -> args)
                                  ...va_start is a macro, similar to a funciton, allows us to access arguments one at a time
                                  ...arg_param represents the individual arguements, and format is the last argument before the
                                     list pf variable arguments*/
    
    int arg_count = 0;
    int length = strlen(format);
    for(int i = 0;i < length;i++){
        if(format[i] == '%') arg_count++;//counts the number of % signs, which will act as a proxy for the number of arguments
    }
    if(arg_count == 0)//if no '%' are counted, the input is just a bare string, and we need only to write format(the only argument) to stdout
    {
        // write(1,va_arg(arg_param,const void *),length); 
        write(1,format,length); 
        return 0;
    }

    char *format_chars = calloc(sizeof(char), arg_count);/*holds the order of format characters, to inform how to alter arguments to strings
                                                            since write() can only write strings to the stdout???????*/
    int cursor = 0;
    for(int i = 0;i < length;i++){
        if(format[i] == '%'){
            format_chars[cursor] = format[i+1];//saving the format characters as a sequence of characters
            cursor++;
        }
    }
    //still need to account for when strings are adjacent to single/multiple format strings in format
    for(int i = 0;i < arg_count;i++){
        char format_char = format_chars[i];
        const char *buff = va_arg(arg_param,const char*);

        switch(format_char){
            case 's':
                write(1,buff,strlen(buff));
                putchar('\n');
                break;
            case 'c':
                write(1,va_arg(arg_param,const char*),sizeof(arg_param));
                
                break; 
            case 'p':
                write(1,va_arg(arg_param,const void*),sizeof(arg_param));
                break;       
        }
    }    
    free(format_chars);
    va_end(arg_param);//the end of variable argument list (va_list -> args)

    return 0;

}

int main(){
    my_printf("hello world\n");
    my_printf("%s\n", "hello");
    // my_printf("%d\n", 18);
    // my_printf("%s -- %d\n", "hello", 18);

    return 0;
}

