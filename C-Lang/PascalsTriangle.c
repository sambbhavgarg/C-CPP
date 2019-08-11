#include<stdio.h>
int main()
{
 int row,col,space,back,n;
  printf("Enter number of lines: ");
  scanf("%d",&n);
  for(row=1;row<=n;row++){
    for(space=n-row-1;space>=0;space--)
    {
      printf(" ");
    }
    for(col=1;col<=row;col++)
    {
      printf("%d",col);
    }
    for(col=row-1;col>0;col--)
    {
      printf("%d",col);
    }
    printf("\n");
  }
}
