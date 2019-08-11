
#include<stdio.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node *nxt;
};
struct node *head=NULL;
void insertbeg()
{
 int a;
 struct node *new;
 new=(struct node *)malloc(sizeof(struct node));
 printf("enter data: ");
 scanf("%d",&a);
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
void display()
{
 struct node *temp=head;
 while(temp!=NULL)
 {
  printf("%d\n",temp->data);
  temp=temp->nxt;
 }
 
}
int main()
{
//insert@beg, display,exit.
int ch,d;
do{
printf("1.enter at beg,2.display,3.exit \n");
scanf("%d",&ch);
switch(ch)
{
 case 1: insertbeg();break;
 case 2: display();break;
 
}

}
while(ch!=3);
return 0;
}
