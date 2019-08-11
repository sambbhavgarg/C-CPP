#include<stdio.h>
int main()
{
int i,j,k,n;
printf("enter size: ");
scanf("%d",&n);
for(i=0;i<n;i++)
{
for(k=0;k<i;k++)
{
printf("*");
}

for(j=n-i;j>0;j--)
{
  printf("x");
}
for(int l=n-i;l>1;l--)
{
  printf("x");
}
printf("\n");

}

return 0;
}
