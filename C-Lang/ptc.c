#include<stdio.h>
int main()
{
int i,j,k,n,t=0;
printf("enter: ");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
for(k=t;k<n;k++)
{
printf(" ");
}
for(j=0;j<i;j++)
{
printf(" * ");
t=t+1;
}
printf("\n");
}
return 0;
}
