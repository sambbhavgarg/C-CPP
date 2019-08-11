//1. implement stack using arrays and linked list
//2. implement circular queue using array, and queue using linked list
#include<stdio.h>
#include<stdlib.h>
int st[10],top=-1;
struct stack
{
 int data;
 struct stack *nxt;
};

struct stack *head=NULL;

void insertlst()
{
 struct stack *new;
 int a;
 printf("enter data: ");
 scanf("%d",&a);
 new=(struct stack *)malloc(sizeof(struct stack));
 new->data=a;
 if(head==NULL)
 {
  head=new;
  new->nxt=NULL;
 }
 else
 {
 new->nxt=head;
 head=new;
 }
}

void deletelst()
{
 struct stack *temp;
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

void displaylst()
{
 struct stack *temp=head;
 while(temp!=NULL)
 {
  printf("%d\n",temp->data);
  temp=temp->nxt;
 }
}

void insertst()
{
 int d;
 printf("Enter element: ");
 scanf("%d",&d);
 if(top==9)
 printf("overflow\n");
 else
 {
  top++;
  st[top]=d;
 }
}

void deletest()
{
 int t;
 if(top==-1)
 printf("Underflow\n");
 else
 {
  t=st[top];
  top--;
  printf("%d is deleted!\n",t);
 }
}

void displayst()
{
if(top==-1)
printf("stack empty!");
else
{
 for(int i=top;i>=0;i--)
 {
  printf("%d\n",st[i]);
 }
 }
}

int main()
{
int ch,ch1;
do
{
printf("1.stack with array, 2.stack with LL, 3.exit\n");
scanf("%d",&ch);
switch(ch)
 {
 case 1: do
         {
          printf("1. insert, 2.delete, 3. display, 4.exit\n");
          scanf("%d",&ch1);
          switch(ch1)
          {
           case 1: insert();break;
           case 2: delete();break;
           case 3: display();break;
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
           case 1: insertl();break;
           case 2: deletel();break;
           case 3: displayl();break;
          }
          
         }
         while(ch1!=4);
         break;
 }
 
 
}
while(ch!=3);
}
