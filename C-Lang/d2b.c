#include<stdio.h>
#include<math.h>
int main()
{
 int a,i,temp;;
 printf("enter a number: ");
 scanf("%d",&a);
 printf("binary: ");
 temp=a;
 for(i=15;i>=0;i--)
 {
  if(a>=pow(2,i))
  {
   printf("1");
   a=a-pow(2,i);
  }
  else
  printf("0");
 }
}
