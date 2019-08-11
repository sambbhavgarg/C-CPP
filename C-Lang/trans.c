#include<stdio.h>
int main()
{
int i,j,m,n;
printf("enter rows and columns: ");
scanf("%d%d",&m,&n);
int arr[m][n];
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
{
printf("enter elements of matrix: ");
scanf("%d",&arr[i][j]);
}
}
printf("\n");
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
{
printf("%d",arr[i][j]);
}
printf("\n");
}
printf("\n");
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
{
printf("%d",arr[j][i]);
}
printf("\n");
}
}
