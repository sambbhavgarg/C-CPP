#include<stdio.h>
void insertsort(int *a,int n){
  int i,j,key;
  for(i=1;i<n;i++){
    key=a[i];//first element of unsorted array
    j=i-1;
    while(j>=0 && key<a[j]){
      a[j+1]=a[j];//dont confuse j+1 with i. j+1!=i since when the sorted array size increases i!=j+1.
      j--;
    }
    a[j+1]=key;//second half of swap, after incrementing j which was decremented to exit loop.
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
  insertsort(&A,n);
  for(i=0;i<n;i++)
    printf(" %d ", A[i]);
  return 0;
}
