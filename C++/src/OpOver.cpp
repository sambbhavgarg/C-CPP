#include<iostream>
using namespace std;
class comp{
int real, complex;
public:
comp(int r,int c){
real=r;
complex=c;
}
// friend comp operator/(comp op,comp op1);
comp operator / (comp op1){
comp temp;
temp.real=op.real+op1.real;
temp.complex=op.complex+op1.complex;
return temp;
}
void show(){
cout<<"Complex value is: "<<real<<"+"<<complex<<"i\n";
}
};

int main(){
comp c(10,12), c1(20,40);
c=c / c1;

c.show();
}
