#include<stdio.h>
int main()
{
int p[5],i,pos=0;
for(i=0;i<5;i++)
{
printf("enter value %d: ",i+1);
scanf("%d",&p[i]);
}
int max=p[0];
for(i=0;i<5;i++)
{
  if(max<p[i])
  {
  max=p[i];
  pos=i;
  }
}
printf("max value is %d at %d\n",max,pos+1);
return 0;
}
