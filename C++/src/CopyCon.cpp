#include<iostream>
using namespace std;
class Point {
 public:
  Point(){cout<<"Normal con call\n";}
  Point(Point &t){cout<<"copy con called\n";}//Address is passed as argument
};
int main(){
Point *t1,*t2;
t1= new Point();
t2=new Point(*t1);
Point t3=*t1;//object is constructed based on another object
Point t4;
t4=t3;
}
//if we create a copy constructor compiler does not create default and parameterized constructor
//it is not true otherwise
//if default and param are made compiler still makes copy constructor
#include<iostream>
using namespace std;
class Point{

}
