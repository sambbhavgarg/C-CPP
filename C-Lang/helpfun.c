//functions
#include<stdio.h>
void funcs(int,int); //note: function declaration, main ko batata hai ki aage aisa ek function ayega
//note: first int is return type, next two ints are data types of values passed to function
int main()
{int a,b,c;
printf("enter two values: ");
scanf("%d%d",&a,&b);
funcs(a,b);//call by value; note: passing values a and b in function funcs and storing value returned in c
return 0;
}
void funcs(int e,int f)//note: function definition, values passed in this can have any name since they are a part of only this functions
//e and f are local values declared in this function only
{
int g=e+f;
printf("sum is %d",g);
return 0;
}
