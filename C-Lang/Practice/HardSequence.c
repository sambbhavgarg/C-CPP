#include<stdio.h>
int main(){
  int n, N;
  scanf("%d%d", &n, &N);
  int a[N];
  a[0] = 0;
  for(int i=0; i<N; i++){
    if(i==0 || findCount(a, N, a[i]))
  }
}

int findLast(int a[], int n, int key){
  int i;
  for(i=n-1, i>=0; i--){
    if(a[i] == key)
      return i;
  }
  return 0;
}
int findCount(int a[], int n, int key){
  int count = 0, start = -1, end, i;
  for(i=0; i<n; i++){
    if(a[i] == key){
      start = i;
      break;
    }
  }
  
  end = start;

  for(i=n-1; i>=start; i--){
    if(a[i] == key){
      end = i;
      break;
    }
  }
  for(i=start; i<=end; i++){
    if(a[i] == key){
      count++;
    }
  }
  return count;
}
