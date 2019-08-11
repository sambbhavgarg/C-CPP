#include<stdio.h>
#include<stdlib.h> //malloc and free

void merge (int *, int, int, int);
void printArray(int *, int);

void mergeSort(int * array, int start, int end){
  if(start>=end){
    return;
  }
  int mid = (start+end)/2;
  mergeSort(array, start, mid);
  mergeSort(array, mid+1, end);
  merge(array, start, mid, end);
}

void merge(int * array, int start, int mid, int end){
  int *temp_array = (int *)malloc(sizeof(int)*(end-start+1));
  int start_cache = start;
  // int i = start;
  int k = 0;
  int j = mid+1;
  while(start <= mid && j <= end){
    if(array[start] <= array[j]){
      temp_array[k] = array[start];
      start++;
    }
    else{
      temp_array[k] = array[j];
      j++;
    }
    k++;
  }
  if(start > mid){
    while(j <= end){
      temp_array[k] = array[j];
      j++;
      k++;
    }
  }

  else if(j > end){
    while(start <= mid){
      temp_array[k] = array[start];
      start++;
      k++;
    }
  }
  for(int i=start_cache; i<=end; i++){
    array[i] = temp_array[i-start_cache];
  }
  free(temp_array);
}

void printArray(int * array, int size) {
  for(int i=0; i<size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

int main(){
  int n;
  printf("Enter number of elements: ");
  scanf("%d",&n);
  int * array = (int *)malloc(sizeof(int)*n);
  printf("Enter %d numbers: ", n);
  for(int i=0; i<n; i++){
    scanf("%d", array+i);
  }
  mergeSort(array, 0, n-1);
  printf("Sorted: ");
  printArray(array, n);
}
