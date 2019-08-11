#include<stdio.h>

void minHeapify(int a[], int n, int i){
  int l=2*i, r=2*i+1, min;
  if(l<=n && a[l]<a[i])
    min=l;
  else
    min=i;
  if(r<=n && a[r]<a[min])
    min=r;
  if (min!=i){
    int temp=a[i];
    a[i]=a[min];
    a[min]=temp;
    minHeapify(a,n,min);
  }
}

void buildMH(int a[], int n){
  int i;
  for(i=n/2;i>=1;i--){
    minHeapify(a,n,i);
  }
}


int main(){
  int i,A[]={0,10, 8, 9, 7, 6, 5, 4};
  buildMH(A,8);
  for(i=1;i<8;i++){
    printf("%d ",A[i]);
  }
  printf("\n");
  return 0;
}
