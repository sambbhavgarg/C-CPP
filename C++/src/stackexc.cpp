#include<iostream>
using namespace std;
class stack{
private:
  int *s;
  int max;
  int top;
public:
  class full{};
  class empty{};
  stack(int);
  void push(int);
  int pop();
  void display();
};
stack::stack(int m){
  s=new int[m];
  top=-1;
  max=m;
}
void stack::push(int item){
  if(top<max-1)
    s[++top]=item;
  else
    throw full();
}
int stack::pop(){
  if(top>=0)
    return s[top--];
  else
    throw empty();
}
void stack::display(){
  if(top>=0){
  for(int i=top;i>0;i++){
    cout<<"data: "<<s[i]<<endl;
  }
}
  else
    throw empty();
}
int main(){
  int item, size;
  int ch=1;
  cout<<"Enter size: ";
  cin>>size;
  stack s1(size);
  cout<<"Menu\n 1. push, 2. pull, 3. display, 4. exit\n";
  cin>>ch;
  do{
    switch(ch){
      case 1: cout<<"Enter data: ";
              cin>>item;
              try{
                s1.push(item);
              }
              catch(stack::full){
                cout<<"Stack Overflow\n";
              }break;
      case 2: try {
                cout<<"Popped out element is: "<<s1.pop();
              }
              catch(stack::empty){
                cout<<"Stack empty\n";
              }break;
      case 3: cout<<"DataSet: \n";
              try{
                s1.display();
              }
              catch(stack::empty){
                cout<<"Stack empty\n";
              }break;
    }
  }while(ch!=4);
  return 0;
}
