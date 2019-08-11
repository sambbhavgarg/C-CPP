#include<stdio.h>
#include<stdlib.h>
int q[10];
int f=-1,r=-1;
struct queue
{
int data;
struct queue *nxt;
};

struct queue *head=NULL;

void insertlq()
{
struct queue *temp=head;
int d;
printf("enter data: ");
scanf("%d",&d);
struct queue *new;
new=(struct queue *)malloc(sizeof(struct queue));
new->data=d;
if(head=NULL)
printf("queue empty\n");
else
{
 while(temp->nxt!=NULL)
 temp=temp->nxt;
 temp->nxt=new;
 new->nxt=NULL;
}
}
void deletelq()
{
 struct queue *temp;
 if(head==NULL)
 printf("List Empty!\n");
 else
 {
 temp=head;
 head=head->nxt;
 printf("%d is deleted!\n",temp->data);
 free(temp);
 }
}


void displaylq()
{
 struct queue *temp=head;
 while(temp!=NULL)
 {
  printf("%d\n",temp->data);
  temp=temp->nxt;
 }
}
void insertq()
{
int d;
printf("enter element: ");
scanf("%d",&d);
if(f==-1)
{
f=r=0;
q[r]=d;
}
else if(r==9)
{
r=(r+1)%10;
q[r]=d;
}
else
{r++;
q[r]=d;
}
}

void deleteq()
{
 int t;
 if(f==-1)
 printf("underflow!\n");
 else if(f==r)
 {
 t=q[f];
 f=-1;

 printf("%d is deleted!\n",t);
 }
else if(f==9)
  {
  t=q[f];
  f=(f+1)%10;
  printf("%d is deleted!\n",t);
  }
 else
 {
   t=q[f];
   f++;
   printf("%d is deleted!",t);
 }
}

void displayq()
{
if(r==-1)
printf("List Empty!\n");
else
{
 for(int i=0;i<10;i++)
  {
   printf("%d\n",q[i]);
  }
}

}
int main()
{
int ch,ch1;
do
{
printf("1.circular queue with array, 2.queue with LL, 3.exit\n");
scanf("%d",&ch);
switch(ch)
 {
 case 1: do
         {
          printf("1. insert, 2.delete, 3. display, 4.exit\n");
          scanf("%d",&ch1);
          switch(ch1)
          {
           case 1: insertq();break;
           case 2: deleteq();break;
           case 3: displayq();break;
          }

         }
         while(ch1!=4);
         break;

 case 2: do
         {
          printf("1. insert, 2.delete, 3. display, 4.exit\n");
          scanf("%d",&ch1);
          switch(ch1)
          {
           case 1: insertlq();break;
           case 2: deletelq();break;
           case 3: displaylq();break;
          }

         }
         while(ch1!=4);
         break;
 }
}
while(ch!=3);
}
