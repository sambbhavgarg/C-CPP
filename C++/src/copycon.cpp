#include<iostream>
using namespace std;
class point{
int x,y;
public:
point(const point &p){x=p.x;y=p.y;}//as copy constructor is made default isnt
int getx(){return x;}
int gety(){return y;}
};
int main(){
point p1;//hence this is not assigned a value
point p2=p1;
cout<<"x: "<<p2.getx<<endl<<"y: "<<p2.gety<<endl;
}
