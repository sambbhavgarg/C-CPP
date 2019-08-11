/*
#include<stdio.h>
struct croom
{
char dept[20];
int cap,rno,bno;
};
int main()
{
 int i,max=0;
 struct croom c[5];
 for(i=0;i<5;i++)
 {
  printf("enter dept, capacity, room no., and bno for classroom %d",i+1);
  scanf("%s %d %d %d",c[i].dept,&c[i].cap,&c[i].rno,&c[i].bno);
 }
 for(i=0;i<5;i++)
 {
  if(c[i].cap>max)
   max=c[i].cap;
 }
 for(i=0;i<5;i++)
 {
 if(c[i].cap==max)
 {
 printf("details of class with maximum capacity is-");
 printf("Dept: %s\ncapacity: %d\nroom number: %d\nblock number: %d\n",c[i].dept,c[i].cap,c[i].rno,c[i].bno);
 }

}
}

#include<stdio.h>
union croom
{
char dept[20];
int cap,rno,bno;
};
int main()
{
 int i,max=0;
 union croom c1,c2,c3;

  printf("enter dept, capacity, room no., and bno for classroom 1");
  scanf("%s %d %d %d",c1.dept,&c1.cap,&c1.rno,&c1.bno);
  printf("enter dept, capacity, room no., and bno for classroom 2");
  scanf("%s %d %d %d",c2.dept,&c2.cap,&c2.rno,&c2.bno);
  printf("enter dept, capacity, room no., and bno for classroom 3");
  scanf("%s %d %d %d",c3.dept,&c3.cap,&c3.rno,&c3.bno);

int arr[3]={c1.cap,c2.cap,c3.cap};
 for(i=0;i<3;i++)
 {
  if(arr[i]>max)
   max=arr[i];
 }
 for(i=0;i<3;i++)
 {
 if(arr[i]==max)
 {
 printf("details of class with maximum capacity is-");
 printf("Dept: %s\ncapacity: %d\nroom number: %d\nblock number: %d\n",c[i].dept,c[i].cap,c[i].rno,c[i].bno);
 }

}
}
*/
