/*1. transpose of a matrix
2. input integer array size and dynamically allocate its members and display it
3. user defined fn to find length of a given string
4. user defined function to find reverse of a string

#include<stdio.h>
int main()
{
int i,j,arr[5][5];
printf("Enter 25 values: ");
for(i=0;i<5;i++)
{for(j=0;j<5;j++)
{ scanf("%d",&arr[i][j]);
}
}
for(i=0;i<5;i++)
{for(j=0;j<5;j++)
{printf("%d",arr[i][j]);
}
printf("\n");
}

for(i=0;i<5;i++)
{for(j=0;j<5;j++)
{printf("%d",arr[j][i]);
}
printf("\n");
}

}
*/
#include<stdio.h>
#include<stdlib.h>
int main()
{ int i,j,n,;
//int ar[];
printf("enter number of elements to be entered:  ");
scanf("%d",&n);
a=(int *)malloc(sizeof(int)*n);
 int arr[a];
 for(i=0;i<n;i++)
{ 
 scanf("%d",&arr[i]);
}
return 0;
}

int counter(int *a,int n)
{
 int i,count=0;
a=(int *)malloc(sizeof(int)*n);
printf("Enter positive and negative values: ");
for(i=0;i<n;i++)
{
 scanf("%d",a+i);
}

 for(i=0;i<n;i++)
 {
if(*(a+i)>0)
  count++;
}
 return count;
}



