#include<stdio.h>
#include<string.h>
//int counter();
int main()
{ 
 int i,j,count=0;
 char string1[20];
 printf("Enter a string(max 20 characters): ");
 gets(string1);
 for(i=0;string1[i]!='\0';i++)
 { 
  for(j=0,count=0;string1[j]!='\0';j++)
  {
   if(string1[i]==string1[j])
    count++;
  //  if(count>1)
   // {
    // string1[j]==string1[j+1];
    //}
  }
   printf("'%c' : %d\n",string1[i],count);
 }
 return 0;
}
