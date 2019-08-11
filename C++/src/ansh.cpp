#include<iostream>
using namespace std;

struct node
{
int data; node *next;
};
class stack{
  node *top;
  public:
    stack(){top=NULL;}
    void sinsert();
    void sdelete();
    void sdisplay();
};
void stack::sinsert(){
  node *temp;
  temp=new node;
  cout<<"Data: ";
  cin>>temp->data;
  temp->next=top;
  top=temp;
}
void stack::sdelete(){
  if(top!=NULL){
    node *temp=top;
    cout<<top->data<<" Deleted...\n";
    top=top->next;
    delete temp;
  }
  else
  cout<<"Stack Empty!\n";
}
void stack::sdisplay(){
  if(top==NULL)
  cout<<"EMPTY STACK\n";
  else{
  node *temp=top;
  while(temp!=NULL){
    cout<<temp->data<<endl;
    temp=temp->next;
  }
}
}
class queue
{
node *rear, *front;
public:
queue(){rear=NULL;front=NULL;}
void qinsert();
void qdelete();
void qdisplay();
};
void queue::qinsert()
{
node *temp;
temp=new node;
cout<<"data: ";
cin>>temp->data;
temp->next=NULL;
if (rear==NULL)
{
rear=temp;
front=temp;
}
else
{
rear->next=temp;
rear=temp;
}
}
void queue::qdelete()
{
if (front!=NULL)
{
node *temp=front;
cout<<front->data<<"Deleted \n";
front=front->next;
delete temp;

if (front==NULL)
rear=NULL;
}
else
cout<<"EMPTY QUEUE\n";
}

void queue::qdisplay()
{
  if(rear==NULL)
  cout<<"EMPTY STACK\n";
  else{
node *temp=front;
while(temp!=NULL)
{
cout<<temp->data<<endl;
temp=temp->next;
}
}
}
class addition
{
    int m,n;
    public:
    addition(int m,int n){
      this->m=m;
      this->n=n;
      int sum=m+n;
      cout<<"Sum: "<<sum<<endl;
    }
};

int main()
{
   int a,b;
   stack s;
   queue q;
   int m,n;
   do{
     cout<<"1. addition of two numbers, 2. queue, 3. stack, 4. exit\n";
     cin>>m;
     switch(m){
       case 1:cout<<"Enter numbers to be added: ";
              cin>>a>>b;
              addition(a,b);
              break;
       case 2:do{
         cout<<"1. Insert, 2. Delete, 3.Display, 4.Exit\n";
         cin>>n;
         switch(n){
           case 1: q.qinsert();break;
           case 2: q.qdelete();break;
           case 3: q.qdisplay();break;
         }
       }while(n!=4);
       break;
       case 3:do{
         cout<<"1. Insert, 2. Delete, 3.Display, 4.Exit\n";
         cin>>n;
         switch(n){
           case 1: s.sinsert();break;
           case 2: s.sdelete();break;
           case 3: s.sdisplay();break;
         }
       }while(n!=4);
     }


 }while(m!=4);
 return 0;
}
