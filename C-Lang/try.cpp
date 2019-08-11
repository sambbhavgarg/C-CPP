#include<iostream>
using namespace std;
class _try{
  int a,b;
public:
 int tried(int a,int b, int c=5){
  int sum;
  this->a=a;
  this->b=b;
  return a+b+c;
}
};
int main(){
_try t;
cout<<t.tried(1,2);

}
//default parameter
