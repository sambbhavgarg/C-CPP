#include<stdio.h>
#include<stdlib.h>
<<<<<<< HEAD

int main(){
  int m,i;
  printf("Enter no. of strings: ");
  scanf("%d",&m);
  char *arr=(char *)malloc(sizeof(char)*20*m);
  for(i=0;i<m;i++){
    for(int j=0;j<20;j++){
      scanf(" %[^\n]s",*(arr+i*20+j));
    }
  }
  for(i=0;i<m;i++){
    for(int j=0;*arr!='\0';j++){
      printf("%c ",*arr);
    }
    printf("\n");
  }
  return 0;
=======
int main(){
int m,i;
printf("Enter no. of strings: ");
scanf("%d",&m);
char *arr=(char *)malloc(sizeof(char)*20*m);
for(i=0;i<m;i++){
  for(int j=0;j<20;j++){
scanf(" %[^\n]s",*(arr+i*20+j));
}
}
for(i=0;i<m;i++){
  for(int j=0;*arr!='\0';j++){
printf("%c ",*arr);
}
printf("\n");
}
return 0;
>>>>>>> 4b343061aa3a8ef2de89b47f56e2aa800f250cb4
}
