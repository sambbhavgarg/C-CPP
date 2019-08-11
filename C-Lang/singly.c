#include<stdio.h>
#include<stdlib.h>

struct singly
{
 int data;
 struct singly *nxt;
};

struct singly *head=NULL;

void insbeg()
{
 int a;
 struct singly *new;
 new=(struct singly *)malloc(sizeof(struct singly));
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

void insend()
{
 int a;
 struct singly *new;
 new=(struct singly*)malloc(sizeof(struct singly));
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
 struct singly *temp=head;
 while(temp->nxt->nxt!=NULL)//why cant i use temp->nxt(because dont wanna lose temp->nxt?);
 {
  temp=temp->nxt;
 }
 temp->nxt->nxt=new;
 new->nxt= NULL;
 }
}

void insaft()
{
 int a;
 printf("enter data(10-100): ");
 scanf("%d",&a);
 struct singly *temp,*new;
 while(temp->nxt->data<a)
 {
  temp=temp->nxt;
 }
 new->nxt=temp->nxt;
 temp->nxt=new;
}

void delbeg()
{
 struct singly *temp;
 if(head==NULL)
 printf("List empty");
 else if(head->nxt==NULL)
 {
 free(head);
 head=NULL;
 }
 else
  {
   temp=head;
   head=head->nxt;
   free(temp);
  }
}

void delend()
{ 
 struct singly *temp=head;
 if(head==NULL)
 printf("List Empty");
 else if(head->nxt==NULL)
 {
  free(head);
  head=NULL;
  }
 else
 {
  while(temp->nxt->nxt!=NULL)
  {
  temp=temp->nxt;
  }
  free(temp->nxt);
  temp->nxt=NULL;
 }
}

void delspec()
{
 int a;
 struct singly *temp,*temp2;
 printf("Enter Element to be deleted: ");
 scanf("%d",&a);
 while(temp->nxt->data!=a)
 {
  temp=temp->nxt;
 }
 temp2=temp->nxt;
 temp->nxt=temp2->nxt;
 free(temp2);
 //or temp->nxt=temp->nxt->nxt; to bond prev w nxt. 
}
/*
void search()
{
 int a, count=0;
 printf("Enter element to be searched: ");
 scanf("%d",&a);
 if(head==NULL)
 printf("List Empty");
 else
 {
  while(temp->nxt->data!=a)
  {
   temp->temp->nxt;
   count++;
  }
  
}
}
*/
void display()
{
 struct singly*temp=head;
 while(temp!=NULL)
 
 {
  printf("%d\n",temp->data);
  temp=temp->nxt;
 }
}
int main()
{
int ch,d;
do{
printf("1.Insert at beginning, 2.Insert at end, 3.Insert after, 4.Delete beginning, 5.Delete End, 6.Delete Specific, 7.Search, 8.display,9.exit \n");
scanf("%d",&ch);
switch(ch)
 {
 case 1: insbeg();break;
 case 2: insend();break;
 case 3: insaft();break;
 case 4: delbeg();break;
 case 5: delend();break;
 case 6: delspec();break;
 //case 7: search();break;
 case 8: display();break;
 }
}while(ch!=9);
return 0;
}

