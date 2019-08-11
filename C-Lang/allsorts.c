#include<stdio.h>
int insertsort(int *arr, int l)
{
 int i,temp,j;
 for(i=1;i<l;i++)
 {
  temp=arr[i];
  j=i-1;
  while(temp<arr[j] && j>=0)
  {
   arr[j+1]=arr[j];
   j--;
  }
  arr[j+1]=temp;
 }
 for(i=0;i<l;i++)
 {
  printf("%d ",arr[i]);
 }
}
int selectsort(int *arr,int l)
{int i,j,temp;
 for(i=0;i<l;i++)
 {
 temp=i;
 for(j=i+1;j<l;j++)
 {
  if(arr[temp]>arr[j])
  temp=i;
  if(temp!=i)
  {
   arr[i]=arr[i]^arr[temp];
   arr[temp]=arr[temp]^arr[i];
   arr[i]=arr[i]^arr[temp];
  }
 }
 }
 for(i=0;i<l;i++)
 {
  printf("%d ",arr[i]);
 }
}
int bubblesort(int *arr,int l)
{int i,j;
 for(i=0;i<l-1;i++)
 {
   for(j=0;j<l-1-i;j++)
   {
  if(arr[j]>arr[j+1])
  {
   arr[j]=arr[j]^arr[j+1];
   arr[j+1]=arr[j+1]^arr[j];
   arr[j]=arr[j]^arr[j+1];

  }
}
 }
 for(i=0;i<l;i++)
 {
  printf("%d ",arr[i]);
 }
}

int main()
{
 int arr[10],n,i;
 printf("enter array of 10 elements: ");
 for(i=0;i<10;i++)
 {
  scanf("%d",&arr[i]);
 }
 do{
  printf("1. insertiom, 2.selection, 3.bubble,4. exit ");
  scanf("%d",&n);
  switch(n)
  {
   case 1: insertsort(&arr,10);break;
   case 2: selectsort(&arr,10);break;
   case 3: bubblesort(&arr,10);break;
  }
 }while(n!=4);
}
