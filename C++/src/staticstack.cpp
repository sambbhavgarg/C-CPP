#include<iostream>
#define MAX 100
using namespace std;
class stack{
public:
  int st[MAX];
  int top;
  stack(){
    top=-1;
  }
  void push(){
    int data;
    cout<<"Enter data: ";
    cin>>data;
    if(top==MAX)
     cout<<"Overflow!\n";
    else{
      top++;
     st[top]=data;
  }
}
  void pop(){
    if(top==-1)
    {
      cout<<"underflow\n";
    }
    else
    cout<<st[top]<<"...deleted\n";
    top--;
  }
  void display(){
    if(top==-1)
    cout<<"Empty!\n";
    else{
      for(int i=top;i>=0;i--){
        cout<<st[i]<<endl;
      }
    }
  }
};
int main(){
  int ch;
  stack s1;
  do{
    cout<<"1. push, 2.pop, 3.display,4.exit";
    cin>>ch;
    switch(ch){
      case 1: s1.push();break;
      case 2: s1.pop();break;
      case 3: s1.display();break;
    }
  }while(ch!=4);
}
