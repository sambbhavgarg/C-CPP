#include<stdio.h>
#include<stdlib.h>
int main()
{
  int n;
  printf("Enter number of elements in array\n");
  scanf("%d", &n);

  int i;
  printf("Enter %d integer\n", n);

  int * ptr = (int*)calloc(n,sizeof(int));
  for (i=0; i<n; i++)
    scanf("%d",ptr[i]);

  int search;
  printf("Enter a number to search\n");
  scanf("%d", &search);

  int low, high, mid, x,  y;
  low = 0;
  high = n-1;
  mid = (low+high)/2;
  x = mid-1;
  y = mid;

  while((low <= x) && (high >= y))
  {
   if(ptr[y] == search){
     printf("Number found");
     break;
   }
   else if( ( (ptr[low] == search) || (ptr[x] == search) ) && ( (ptr[y] == search) || (ptr[high] == search) ) ){
     printf("%d is found",search);
     break;
   }
   else{
     low = low+1;
     x = x-1;
     y = y+1;
     high = high-1;
   }
   mid = (low+high)/2;
  }
  if(low > high)
   printf("%d isn't present in the array", search);
}
