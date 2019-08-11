#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct compute
{
 char model[10];
 float price;
 int rsize;
 struct compute *nxt;
};
struct compute *head=NULL;
void insert()
{
int r;float p;char m[10];
struct compute *new;
new=(struct compute*)malloc(sizeof(struct compute));
printf("Enter model, price, ram size: ");
scanf("%s%d%f",m,&r,&p);
strcpy(new->model,m);
new->price=p;
new->rsize=r;
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

void display()
{
float sum=0;
struct compute *temp=head;
if(head==NULL)
{
printf("List Empty!\n");
}
else
{
while(temp!=NULL)
{
temp=temp->nxt;
sum=sum+temp->price;
printf("%s\n%f\n%d\n",temp->model,temp->price,temp->rsize);
printf("price of all computers is: %f\n",sum);
}
}
}
int main()
{
  int ch;
  do{
  printf("1.Insert, 2.Display,3.Exit");
  scanf("%d",&ch);
  switch(ch)
  {
    case 1: insert();break;
    case 2: display();break;
  }
}while(ch!=3);
}
