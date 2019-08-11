#include<iostream>
using namespace std;
struct doubly{
  int data;
  doubly *nxt;
  doubly *prv;
};
int biggest(int a, int b){
  if(a>b)
    return 1;
}
doubly *top;
class dll {
public:
  dll(){doubly *top=NULL;}
  void insertbeg();
  void insertend();
  //void deletebeg();
//  void deleteend();
  //void insertafter();
  void display();
  //void search();
};
void dll::insertbeg(){
  int d;
  doubly *temp=new doubly;
  cout<<"Enter data: ";
  cin>>d;
  temp->data=d;
  if(top==NULL){
    top=temp;
    tp->prv=NULL;
    tp->nxt=NULL;
  }
  else{
    temp->nxt=top;
    top->prv=temp;
    temp->prv=NULL;
  }
}
void dll::insertend(){
  int d;
  doubly *temp=new doubly;
  cout<<"Enter data: ";
  cin>>d;
  temp->data=d;
  if(top==NULL){
    top=temp->prv;
    temp->prv=NULL;
    temp->nxt=NULL;
  }
  else if(top->nxt==NULL){
    top->nxt=temp;
    temp->prv=NULL;
    temp->nxt=NULL;
  }
  else{
    doubly *temp1=new doubly;
    temp1=top;
    while(temp1->nxt->nxt!=NULL)
      temp1=temp1->nxt;
    temp1->nxt->nxt=temp->prv;
    temp->prv->nxt=temp->prv;
    temp->nxt=NULL;
  }
}
void dll::display(){
  doubly *temp=new doubly;
  if(top==NULL)
    cout<<"List empty\n";
  else{
    while(temp!=NULL){
      cout<<temp->data<<endl;
      temp=temp->nxt;
    }
  }
}
int main(){
  int ch;
  dll d1;
  do{
    cout<<"1. insert at beginning, 2. insert at end, 3. delete at beginning, 4. delete at end,\n 5. insertafter, 6. search, 7. display, 8. Exit\n";
    cin>>ch;
    switch (ch) {
      case 1: d1.insertbeg();break;
      case 2: d1.insertend();break;
    //  case 3: d1.deletebeg();break;
    //  case 4: d1.deleteend();break;
    //  case 5: d1.insertafter();break;
    //  case 6: d1.search();break;
     case 7: d1.display();break;
    }
  }while(ch!=8);
return 0;
}
