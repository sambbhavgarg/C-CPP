#include<iostream>
using namespace std;
class base{//abstract class
public:
virtual void show()=0;//pure virtual function
};
class derived : public base{
virtual void show(){
cout<<"Derived class\n";
}
};
int main(){
base *b;
derived d;
b=&d;
b->show();

}
