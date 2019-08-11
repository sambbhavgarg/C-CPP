#include<stdio.h>
#include<time.h>

int lsearch(int a[], int n, int e){
  clock_t start_t,end_t,total_t;
  int count=0,i=0;
  start_t=clock();
  for(i=0;i<n;i++)
    if(a[i]==e){
      end_t=clock();
      total_t = (double)(end_t-start_t)/CLOCKS_PER_SEC;
      printf("Total time taken: %f\n",total_t);
      return i;
    }
  return -1;
}

int binsearch(int a[],int lb, int n, int e)
{
  clock_t start_t,end_t,total_t;
  start_t=clock();
  int m;
  if (n>=lb)
  {
    m=lb+(n-lb)/2;
    if (a[m]==e){
      end_t=clock();
      total_t= (double)(end_t-start_t)/CLOCKS_PER_SEC;
      printf("Total time taken: %f\n",total_t);
      return m;
    }
    else if (a[m]>e)
       binsearch(a,lb,m-1,e);
    else
       binsearch(a,m+1,n,e);
  }

  return -1;
}

void choice(int ar[], int n, int e){
  int a,found;
  do
  {
  printf("1.Linear search, 2.Binary Search, 3.Exit\n");
  scanf("%d",&a);
  switch(a)
  {
   case 1: found=lsearch(ar,n,e);
           (found==-1)? printf("Element not Found\n")
                       :printf("Element found at %d\n",found);
            break;
   case 2: found=binsearch(ar,0,n-1,e);
           (found==-1)? printf("Element not Found\n")
                       :printf("Element found at %d\n",found);
           break;
  }
  }while(a!=3);
}

void elem(int a[], int n){
  int element;
  printf("Enter element to be searched: ");
  scanf("%d",&element);
  choice(a,n,element);
}

int main(){
  int i,n;
  printf("Enter a huge array value: ");
  scanf("%d",&n);
  int A[n];
  for (i = 0; i < n; i++) {
    A[i]=i+1;
  }
  elem(A,n);
  return 0;
}
