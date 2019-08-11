#include<stdio.h>
int main()
{
    char *str="i know c .";
    while(*str)
    {
         putc(*str,stdout);
         putchar(*str);
         printf("%c",*str);
         str++;
    }
    return 0;
}
