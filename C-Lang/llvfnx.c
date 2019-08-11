#include<stdio.h>
#include<stdlib.h>
struct stack
{
char name[10];
int salary;
struct stack *nxt;
};
struct stack *head=NULL;
void insertbeg()
{
int d;
char name[10];
printf("Enter name: ");
scanf("%s",name);
printf("enter salary: ");
scanf("%d",&d);
struct stack *new=(struct stack *)malloc(sizeof(struct stack));
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
void delbeg()
{struct stack *temp=head;
if(head=NULL)
printf("List Empty!");
else
{
head=head->nxt;
free(temp);
}
}
void dis()
{
struct stack *temp;
if(head==NULL)
printf("list empty!");
else
{
  temp=head;
while(temp->nxt!=NULL)
{
temp=temp->nxt;
puts(temp->name);
printf("%d",temp->salary);
}
}
}
void con()
{int count=0;
struct stack *temp=head;
if(head==NULL)
printf("list empty!");
else
{
while(temp!=NULL)
{
temp=temp->nxt;
count++;
}
}
printf("Number of elements in linked list is: %d",count);
}
void rev()
{
struct stack *temp=head;
struct stack *prev=NULL;
struct stack *nxt;
while(temp!=NULL)
{
  nxt=temp->nxt;
  temp->nxt=prev;
  prev=temp;
  temp=nxt;
}
head=prev;
}
int main()
{
int d;
do{
printf("1. insert, 2. delete, 3. display, 4.count, 5. reverse, 6.exit\n");
scanf("%d",&d);
switch(d)
{
  case 1: insertbeg();break;
  case 2: delbeg();break;
  case 3: dis();break;
  case 4: con();break;
  case 5: rev();break;
}
}while(d!=6);
return 0;
}
