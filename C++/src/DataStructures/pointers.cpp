#include<iostream>
using namespace std;

void squareR(int * n){
  *n *= *n;
}
void squareV(int n){
  n *= n;
}


int main(){
  int n = 99;
  int & refN = n;
  cout<<refN<<" "<<n<<endl;
  n = 55;
  cout<<refN<<" "<<n<<endl;
  refN = 89;
  cout<<refN<<" "<<n<<endl;
  squareV(n);
  cout<<"Remains 89, call by value "<<n<<endl;
  squareR(&n);
  cout<<n<<endl;
}
