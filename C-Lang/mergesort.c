#include<stdio.h>

void printArray(int a[], int size) {
  for(int i = 0; i < size; i++){
    printf("%d", a[i]);
  }
  printf("\n");

}

void merge(int a[], int p, int q, int r){
  printf("Merge function called\n");
  printArray(a,r+1);
  int i,j,k;
  int n1 = q-p+1, n2 = r-q;
  int L[n1], R[n2];
  printf("Left array filling ahead\n");
  printArray(a,r+1);
  for(i=0;i<n1;i++)
    L[i]=a[p+i];
  printf("Right array filling ahead\n");
  printArray(a,r+1);
  for(j=0;j<n2;j++)
    R[j]=a[q+1+j];
  i=0;
  j=0;
  k=q;
  while(i<n1 && j<n2){
    if(L[i]<=R[j]){
      a[k]=L[i];
      i++;
    }
    else{
      a[k]=R[j];
      j++;
    }
    k++;
  }
  while (i < n1)
  {
      a[k] = L[i];
      i++;
      k++;

  }

  /* Copy the remaining elements of R[], if there
     are any */
  while (j < n2)
  {
      a[k] = R[j];
      j++;
      k++;
  }
printf("Merge function concludes\n");
}

void mergeSort(int a[],int p,int r){
 printf("MergeSort function begins\n");
  printArray(a,r+1);
  if(p<r){
    int q = (r+p)/2;//avoids overflow for large values
    printf("Merge sort recursion called ahead\n");
    mergeSort(a,p,q);
    printArray(a,r+1);
    mergeSort(a,q+1,r);
    printArray(a,r+1);
    printf("Merge call ahead\n");
    merge(a,p,q,r);
    printArray(a,r+1);
  }
  printf("MergeSort function concludes\n");

}

int main(){
  int i,n;
  printf("Enter size of Array: ");
  scanf("%d",&n);
  int A[n];
  printf("Enter array elements: ");
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  for(i=0;i<n;i++){
    printf("%d ", A[i]);
  }
  printf("\nMerge Sort called for the first time ahead\n");
  printArray(A,n);
  mergeSort(A,0,n-1);
  printf("Code Compiled Successfully\nPrinting Ahead\n");
  for(i=0;i<n;i++){
    printf("%d ", A[i]);
  }
  printf("\n");
}
