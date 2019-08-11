#include<stdio.h>
int stack[10];
int queue[10];
int top=-1,f=-1,r=-1;
struct nodelst{
  int data;
  struct nodelst *nxt;
};
struct nodelq{
  int data;
  struct nodelq *fr;
  struct nodelq *rr;
};
nodelst *head=NULL;
nodelq *head=NULL;
void insertlst(){
  int d;
  printf("insert: ");
  scanf("%d",&d);
  struct nodelst *new;
  new=(struct nodelst *)malloc(sizeof(struct nodelst));
  new->data=d;
  if(head==NULL){
    head=new;
    new->nxt=NULL;
  }
  else{
    new->nxt=head;
    head=new;
  }
}
void insertst(){
  int d;
  printf("Enter: ");
  scanf("%d",&d);
  if(top==9)
   printf("Overflow\n");
  else{
    top++;
    stack[top]=d;
  }
}
void insertq(){

}
void insertlq(){
  int d;
  struct nodelq *temp=head;
  printf("Enter data: ");
  scanf("%d",&d);
  struct nodelq *new;
  new=(struct nodelq *)malloc(sizeof(struct nodelq));
  new->data=d;
  if(head==NULL){
    head=new;
    new->nxt=NULL;
  }
  else{
    while(temp!=NULL){
      temp=temp->nxt;
    }
    temp=new;
    new->nxt=NULL;
  }
}
void deleteq(){
  int d;
  printf("Enter: ");
  scanf("%d",&d);
  if(r==-1)
}
void deletelq(){

}
void deletestO(){

}
void deletelst(){

}
main(){
int ch,ch1;
do{
  printf("1. Static stack, 2. Static Queue, 3. Dynamic Stack, 4. Dynamic Queue, 4. Exit\n");
  scanf("%d",&ch);
  Switch(ch){
    case 1: do{
              printf("1. Insert, 2. Delete, 3. Display, 4. Exit");
              scanf1("%d",&ch1);
              Switch(ch1){
                case 1: insertst();break;
                case 2: deletest();break;
                case 3: displayst();break;
              }
            }while(ch1!=4);
    case 2: do{
              printf("1. Insert, 2. Delete, 3. Display, 4. Exit");
              scanf1("%d",&ch1);
              Switch(ch1){
                case 1: insertq();break;
                case 2: deleteq();break;
                case 3: displayq();break;
              }
            }while(ch1!=4);
    case 3:do{
              printf("1. Insert, 2. Delete, 3. Display, 4. Exit");
              scanf1("%d",&ch1);
              Switch(ch1){
                case 1: insertlst();break;
                case 2: deletelst();break;
                case 3: displaylst();break;
              }
            }while(ch1!=4);
    case 4: do{
              printf("1. Insert, 2. Delete, 3. Display, 4. Exit");
              scanf1("%d",&ch1);
              Switch(ch1){
                case 1: insertlq();break;
                case 2: deletelq();break;
                case 3: displaylq();break;
              }
            }while(ch1!=4);
  }
}while(ch!=4);
}
