//binary search using functions, call by reference (array passed to a function), fundamental arrays
#include<stdio.h>
int binsearch(int,int,int *);
int main()
{
int n,i,find,size;
printf("enter size of array: ");
scanf("%d",&size);
int arr[size];
printf("Enter array: ");
for(i=0;i<size;i++)
{
scanf("%d",&arr[i]);
}
printf("enter element to be searched: ");
scanf("%d",&find);
binsearch(find,size,&arr);
return 0;
}

int binsearch(int f,int s, int *a)
{
  int i,k=s,m,flag;
  for(i=0;i<s-1;i++)
  {
    if(a[i]<a[i+1])
    flag++;
  }
  if(flag==s)
  {
  for(i=0;i<=k;)
  {
    m=(i+k)/2;
    if(a[m]==f)
    printf("item found at %d",m+1);
    else if(a[m]<f)
    i=m+1;
    else if(a[m]>f)
    k=m-1;
    }
  }
  else
  printf("Array Unsorted, Cant run binary search!\n");

}
