l//searching : linear(freq of every element: 1), binary;n-1 comparisons in an array of n elements IF ELEMENT IS PRESENT
#include<stdio.h>
int main()
{
int pos,n,a,ar[10];
printf("enter element to be searched: ");
scanf("%d",&n);
do
{
printf("1.Linear search, 2.Binary Search, 3.Exit\n");
scanf("%d",&a);
switch(a)
{
 case 1: lsearch(&ar,n);break;
 case 2: bsearc(&ar,n);break;
}
}while(a!=3);
return 0;
}
void lsearch(int *ar,int n)
{
int i;
for(i=0;i<10;i++)
{
if(ar[i]==n)
 {
   printf("Element found at position %d\n",i);
   continue;
 }
}
if(i==10)
printf("element not found!\n");
}
//binary search only works if array is sorted
void bsearch(int ar[10],int n)
{
int i,k=9,m;
for(i=0;i<=k;)
{
m=(i+k)/2;
if(ar[m]==n)
print found here
else if(arr[m]<n)
i=m+1;
else
k=m-1;
}
}
