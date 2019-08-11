#include<stdio.h>
int partition(int a[], int p, int r){
  int x=a[p],i=p,j,temp;
  for(j=p+1;j<=r;j++){
    if(a[j]<=x){
      i=i+1;
      temp=a[i];
      a[i]=a[j];
      a[j]=temp;
    }
  }
  temp=a[p];
  a[p]=a[i];
  a[i]=temp;
  return i;
}

void quicksort(int a[],int p,int r){
  int q;
  if(p<r){
    q=partition(a,p,r);
    printf("%d\n",q);
    quicksort(a,p,q-1);
    quicksort(a,q+1,r);
  }
}

int main(){
  int i,n;
  printf("Enter size of array: ");
  scanf("%d",&n);
  int A[n];
  printf("Enter Array elements: ");
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  printf("Unsorted Array: \n");
  for(i=0;i<n;i++){
    printf("%d ",A[i]);
  }
  printf("\n");
  quicksort(A,0,n-1);
  printf("Sorted Array: \n");
  for(i=0;i<n;i++){
    printf("%d ",A[i]);
  }
  printf("\n");
  return 0;
}
