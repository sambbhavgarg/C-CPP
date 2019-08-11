#include<stdio.h>
int changer(int *);
int nochange(int);
int main()
{
 int num=5;
 printf("%d\n",num);
 changer(&num);
 printf("%d\n",num);
 changer(&num);
 printf("%d\n",num);
 nochange(&num);
 printf("%d\n",num);
 nochange(&num);
 printf("%d",num);
 return 0;
}
int changer(int *x)
{
(*x)++;
}
int nochange(int x)
{
x++;
}
//in changer() the function is called by reference, has value of num changes.
//while in nochange() value of num remains constant since we're calling it by value 
