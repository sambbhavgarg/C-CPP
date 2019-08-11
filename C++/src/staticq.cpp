#include<iostream>
using namespace std;
#define MAX 100;
int q[MAX];
class queue{
public:
  int front,rear;
  queue(){
    front=rear=-1;
  }
};
void queue::insert(){
    int data;
    cout<<"Enter data: ";
    cin>>data;
    if((f==0 && r==MAX-1) || 
    cout<<"underflow!\n";
    else if(r==MAX-1 && f>0){
      r=0;
      q[r]=data;
      r++;
    }
    else{
      q[r]=data;
      r++;
}
void queue::delete(){
  if(f==-1){

  }
}
