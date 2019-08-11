#include<stdio.h>
#include<stdlib.h>
int st[10];
int q[10];
int top=-1,front=-1,rear=-1;


struct stack
{
 int data;
 struct stack *nxt;
};


struct queue
{
int data;
struct queue *nxt;
};


struct stack *headst=NULL;
struct queue *headq=NULL;


void insertlst()
{
 struct stack *new;
 int a;
 printf("enter data: ");
 scanf("%d",&a);
 new=(struct stack *)malloc(sizeof(struct stack));
 new->data=a;
 if(headst==NULL)
 {
  headst=new;
  new->nxt=NULL;
 }
 else
 {
 new->nxt=headst;
 headst=new;
 }
}


void deletelst()
{
 struct stack *temp;
 if(headst==NULL)
 printf("List Empty!\n");
 else
 {
 temp=headst;
 headst=headst->nxt;
 printf("%d is deleted!\n",temp->data);
 free(temp);
 }
}


void displaylst()
{
 struct stack *temp=headst;
 while(temp!=NULL)
 {
  printf("%d\n",temp->data);
  temp=temp->nxt;
 }
}


void insertlq()
{
struct queue *temp=headq;
int a;
printf("enter data: ");
scanf("%d",&a);
struct queue *new=(struct queue *)malloc(sizeof(struct queue));
new->data=a;
if(headq==NULL)
{
  headq=new;
  new->nxt=NULL;
}
else
{
 while(temp->nxt!=NULL)
 {
 temp=temp->nxt;
 }
 temp->nxt=new;
 new->nxt=NULL;
}
}


void deletelq()
{
 struct queue *temp;
 if(headq==NULL)
 printf("List Empty!\n");
 else
 {
 temp=headq;
 headq=headq->nxt;
 printf("%d is deleted!\n",temp->data);
 free(temp);
 }
}


void displaylq()
{
 struct queue *temp=headq;
 while(temp!=NULL)
 {
  printf("%d\n",temp->data);
  temp=temp->nxt;
 }
}


void insertq()
{
int a;
printf("enter element: ");
scanf("%d",&a);
if((front==0 && rear==9) || rear==front-1){
  printf("Overflow\n");
}
else if(front==-1 ){
  front=rear=0;
  st[rear]=a;
}
else if(rear==9 && front!=0){
  rear=0;
  st[rear]=a;
}
else {
  rear++;
  st[rear]=a;
}
}


void deleteq(){
  int a;
  if(front==-1){
    printf("Underflow\n");
  }
  a=q[front];
  q[front]=-1;
  if(front==rear){
    a=q[front];
    printf("%d is deleted!\n",a);
    front=rear=-1;
  }
  else if(front==9){
    a=q[front];
    printf("%d is deleted!\n",a);
    front=0;
  }
  else{
    a=q[front];
    printf("%d is deleted!\n",a);
    front++;
  }
}


void displayq()
{
if(rear==-1)
printf("List Empty!\n");
else
 {
 for(int i=0;i<10;i++)
  {
   printf("%d\n",q[i]);
  }
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
printf("1.stack with array, 2.stack with LL, 3. Circular queue with array, 4.Queue with LL, 5.exit\n");
scanf("%d",&ch);
switch(ch)
 {
 case 1: do
         {
          printf("1. insert, 2.delete, 3. display, 4.exit\n");
          scanf("%d",&ch1);
          switch(ch1)
          {
           case 1: insertst();break;
           case 2: deletest();break;
           case 3: displayst();break;
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
           case 1: insertlst();break;
           case 2: deletelst();break;
           case 3: displaylst();break;
          }

         }
         while(ch1!=4);
         break;
case 3: do
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
  case 4: do
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
while(ch!=5);
}
