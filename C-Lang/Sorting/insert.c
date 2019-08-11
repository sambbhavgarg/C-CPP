#include<stdio.h>
int main()
{
 int i,k,j,item,n=7,m;
 int la[]={1,2,4,5,6,8,9};
printf("1 2 4 5 6 8 9");
label:
j=n;
printf("enter missing number and position: ");
scanf("%d%d",&item,&k);
while(j>=k)
{
 la[j+1]=la[j];
 j-=1;
}
la[k]=item;
n++;
for(i=0;i<=7;i++)
 {
   printf("%d",la[i]);
 }
 printf("more?(1/0)");
 scanf("%d",&m);
 switch(m)
 {
 case 1: goto label; break;
 case 0: printf("press any key");break;
 }
  return 0;
}
//complete code
