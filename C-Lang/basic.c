#include<stdio.h>
int main()
{
 char arr[5][20];
int i,j;
 for(i=0;i<5;i++)
 {
printf("enter subject!");

  for(j=0;j<20;j++)
   {

     scanf("%c",&arr[i][j]);
 }
printf("\n");
}
for(i=0;i<5;i++)
{
   for(j=0;j<20;j++)

printf("%c",arr[i][j]);
printf("\n");
}
}
