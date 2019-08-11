#include<stdio.h>
int main()
{
int i,arr[10],temp,j;
 printf("enter an array of 10 elements: ");
 for(i=0;i<10;i++)
 { 
  scanf("%d",&arr[i]);
 }
 for(i=0;i<10-1;i++)
 { 
 for(j=0;j<10-i-1;j++)
 {
  if(arr[j+1]>arr[j])
  {
   temp=arr[j+1];
   arr[j+1]=arr[j];
   arr[j]=temp;
  }
 }
 }
  printf("sorted array is: ");
 for(i=0;i<10;i++)
 {
  printf("%d ",arr[i]);
 }
  
}


 

