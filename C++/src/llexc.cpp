#include<iostream>
using namespace std;
struct node{
  int data;
  node *ptr;
}*top;
class llist {
public:
  llist(){
    node*top=NULL;
  }
  void insertbeg();
  void insertend();
  void deletebeg();
  void deleteend();
  void display();
  //~llist();
};
void llist::insertend(){
  node *temp=new node;
  cout<<"Enter element: ";
  cin>>temp->data;
  if(top==NULL){
    top=temp;
    temp->ptr=NULL;
  }
  else{
    while(temp!=NULL){
      temp=temp->ptr;
    }
    temp->ptr=top;
    temp->ptr=NULL;
  }
}
void llist::insertbeg(){
  node *temp=new node;
  cout<<"Enter element: ";
  cin>>temp->data;
  if(top==NULL){
    top=temp;
    top->ptr=NULL;
  }
  else{
    temp->ptr=top;
    top=temp;
  }
}
void llist::deletebeg(){
node *temp=new node;
try{
  if(top==NULL)
    throw 'x';
  else{
    temp=top;
    top=top->ptr;
    cout<<temp->data<<"...Deleted\n";
    delete temp;
  }
}
catch(char x){
  cout<<"List Empty!\n";
  }
}
void llist::deleteend(){
  node *temp=new node;
  try{
    if(top==NULL)
      throw 'x';
    else if(top->ptr=NULL){
      temp=top;
      delete temp;
    }
    else{
      temp=top;
      while(temp->ptr->ptr!=NULL){
        temp=temp->ptr;
      }
      delete temp->ptr;
    }
  }
  catch(char x){
    cout<<"List Already Empty\n!";
  }
}
void llist::display(){
  node *temp=top;
  if(top==NULL){
    cout<<"List Empty\n";
  }
  else{
    int a=1;
    while(temp!=NULL){
      cout<<"node "<<a<<":\t"<<temp->data<<endl;
      temp=temp->ptr;
      a++;
    }
  }
}
int main(){
  llist l1;
  int ch, d;
  do{
    cout<<"1. Insert at beginning, 2. Insert at end, 3. Delete at beginning , 4. Delete at end, 5. Display, 6. Exit\n";
    cin>>ch;
    switch(ch){
      case 1: l1.insertbeg();break;
      case 2: l1.insertend();break;
      case 3: l1.deletebeg();break;
      case 4: l1.deleteend();break;
      case 5: l1.display();break;
    }
  }while(ch!=4);
  return 0;
}
