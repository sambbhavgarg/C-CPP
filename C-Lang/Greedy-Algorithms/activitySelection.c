#include<stdio.h>

struct activity{
  int start,finish;
};

struct t{
  int start, finish;
}temp;


void printMA(int a, int b){
  printf("(%d,%d) ",a,b);
}

int insertsort(struct activity arr[], int l)
{
 int i,j;
 for(i=1;i<l;i++){
   temp.start=arr[i].start;
   temp.finish=arr[i].finish;
   for(j=i;j>0 && temp.finish<arr[j-1].finish;j--){
     arr[j].start=arr[j-1].start;
     arr[j].finish=arr[j-1].finish;
   }
   arr[j].start=temp.start;
   arr[j].finish=temp.finish;
 }
  /*
 for(i=0;i<l;i++)
 {
  printf("%d ",arr[i].finish);
 }
 printf("\n");
  */
}

void MaxActivities(struct activity a[], int n){
  int i=0, k, j;
  insertsort(a,n);
  /*for(k=0;k<n;k++)
  {
   printf("%d ",a[k].finish);
  }
  printf("\n");
  */
  printMA(a[i].start,a[i].finish);
  for(j=1;j<n;j++){
    if(a[j].start>=a[i].finish){
      printMA(a[j].start,a[j].finish);
      i=j;
    }
  }
}
int main(){
  struct activity arr[] = {{5, 9}, {1, 2}, {3, 4}, {0, 6},{5, 7}, {8, 9}};
  printf("Activities are as follows:\n{5, 9}, {1, 2}, {3, 4}, {0, 6},{5, 7}, {8, 9}\n");
  printf("Selected Activities are: ");
  MaxActivities(arr, 6);
  return 0;
}
