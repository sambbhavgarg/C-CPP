#include<stdio.h>
void swap(int* a,int* b){
  int temp=0;
  temp=*a;
  *a=*b;
  *b=temp;
}
void selecsort(int *a, int n){
  int i,j,temp;
  for(i=0;i<n-1;i++){
    temp=i;
    for(j=i+1;j<n;j++)
      if(a[j]<a[temp])
        temp=j;
    swap(&a[temp],&a[i]);
  }
}

int main(){
  int i,n;
  printf("Enter size of array: ");
  scanf("%d",&n);
  int A[n];
  for(i=0;i<n;i++){
    printf("Enter %d elements: ",n);
    scanf("%d",&A[i]);
  }
  selecsort(&A,n);
  for(i=0;i<n;i++)
    printf(" %d ", A[i]);
  return 0;
}
