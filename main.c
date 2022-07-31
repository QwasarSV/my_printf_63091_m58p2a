#include "my_printf.h"

int main(){
    my_printf("hello world\n");
    my_printf("%s -- %d\n", "hello", 18);
    my_printf("%d\n", 18);
    my_printf("%d\n", -1867);
    my_printf("%o\n", 9);
    my_printf("%u\n", -187);
    my_printf("%x -- %s\n",2147483647,"yessirr");
    my_printf("%p\n","gg");
    my_printf("%u\n",-1);

    return 0;
}