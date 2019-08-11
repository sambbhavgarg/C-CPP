#include<stdio.h>
void fcfs(int *a,int n){
  int i,sum=0,suma=0,avg;
  printf("\nBurst time for process 1: %d milliseconds.\n",a[0]);
  printf("Waiting time for process 1: 0 milliseconds.\n\n");
  for(i=1;i<n;i++){
    printf("Burst time for process %d: %d milliseconds\n.",i+1,a[i]);
    sum+=a[i-1];
    printf("Waiting time for process %d: %d milliseconds.\n\n",i+1,sum);
    suma+=sum;
  }
  avg=suma/n;
  printf("Average waiting time is: %d\n",avg);
}

int main(){
  int i,n;
  printf("Enter size of array: ");
  scanf("%d",&n);
  int A[n];
  for(i=0;i<n;i++)
    scanf("%d",&A[i]);
  fcfs(&A,n);
  return 0;
}
