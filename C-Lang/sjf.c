#include<stdio.h>
int bubblesort(int *a, int l)
{
  int i,j,B[l],temp;
  for(i=0;i<l;i++)
  {
   for(j=0;j<l-i;j++)
   {
    if(a[j]>a[j+1])
    {
     temp=a[j];
     a[j]=a[j+1];
     a[j+1]=temp;
    }
  }
  B[l-1-i]=temp;
 }

 int sum=0,suma=0,avg;

 for(i=0;i<l;i++){
   printf("Burst time for process %d: %d milliseconds\n.",B[i],a[i]);
   sum+=a[i-1];
   printf("Waiting time for process %d: %d milliseconds.\n\n",B[i],sum);
   suma+=sum;
 }
 avg=suma/l;
 printf("Average waiting time is: %d\n",avg);
}

int main(){
  int i,n;
  printf("Enter size of array: ");
  scanf("%d",&n);
  int A[n],B[n];
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
    B[i]=i+1;
  }
  bubblesort(&A,n);
}
