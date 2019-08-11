#include<stdio.h>
int insertsort(int arr[], int l)
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
 printf("\n");
}
int main(){
  int i,n;
  printf("Enter size of array: ");
  scanf("%d",&n);
  int A[n];
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  insertsort(A[n],n);
  for(i=0;i<n;i++)
  {
   printf("%d ",a[i]);
  }
}
