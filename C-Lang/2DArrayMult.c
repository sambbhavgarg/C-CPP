#include<stdio.h>
//int matmult()
//int matadd()

<<<<<<< HEAD
int main(){
  int i,j,m,n;
  printf("Enter size of 2D Array A: ");
  scanf("%d",&m);
  printf("Enter size of 2D Array B: ");
  scanf("%d",&n);
  int a[m][m],b[n][n];
=======
int  

int main(){

  int i,j,m,n;

  printf("Enter size of 2D Array A: ");
  scanf("%d",&m);

  printf("Enter size of 2D Array B: ");
  scanf("%d",&n);

  int a[m][m],b[n][n];

>>>>>>> 4b343061aa3a8ef2de89b47f56e2aa800f250cb4
  printf("Input For 2D Array A --\n");
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      printf("Element %d.%d: ", i+1,j+1);
      scanf("%d", &a[i][j]);
    }
  }
  printf("%d\n",a[0][1]);
<<<<<<< HEAD
=======

>>>>>>> 4b343061aa3a8ef2de89b47f56e2aa800f250cb4
  printf("Input For 2D Array B --\n");
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      printf("Element %d.%d: ", i+1,j+1);
      scanf("%d",&b[i][j]);

    }
  }

  printf("%d\n",b[1][1]);
<<<<<<< HEAD
=======

>>>>>>> 4b343061aa3a8ef2de89b47f56e2aa800f250cb4
  i=0;
  j=0;
  printf("2D Array A --\n");
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      printf("%d ", a[i][j]);
    }
    printf("\n");
  }

  printf("2D Array B --\n");
    for(i=0;i<n;i++){
      for(j=0;j<n;j++){
        printf("%d ", b[i][j]);
      }
      printf("\n");
    }
<<<<<<< HEAD
    //call multiply function which returns the two 2D array's product.
=======

    //call multiply function which returns the two 2D array's product.

>>>>>>> 4b343061aa3a8ef2de89b47f56e2aa800f250cb4
}
