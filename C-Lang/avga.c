/*average to find average of all elements in array  using functions
#include<stdio.h>
float avg(int *);// can be int a[], int arr[], int *a too; flexibility, pass by reference 
int main()
{
 int ar[10],i;

  printf("Enter 10 values: ");
  for(i=0;i<10;i++)
  {
   scanf("%d",&ar[i]);
  }
printf("Average is: %f\n", avg(ar));
return 0;
}
float avg(int arr[10])//can be ar too
{  float av=0.0,sum=0.0;
   int i;
   for(i=0;i<10;i++)
{ 
sum+=arr[i];
}
av=sum/10;
return av;
}



//count positive values in an integer array
*/

#include<stdio.h>
#include<stdlib.h>
int counter(int *, int);
int main()
{ int *ar,c,n;
//int ar[];

printf("enter number of elements to be checked:  ");
scanf("%d",&n);
c=counter(ar,n);
 printf("number of positive values: %d",c);
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



