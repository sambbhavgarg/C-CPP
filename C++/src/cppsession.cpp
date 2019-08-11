/*
double vs. float
strings
early binding: compilation time
late binding: run-time
#inline functions
reduces compilation time if used but increases lines of code
basically function definition is replaced with call(early binding time)
no macros in c++
this operator(function below)
static variable cant -
constant variables cant be used with functions and can be modified.
friend functions can access member functions. application?
---------------------------------------------------------------------------------
#include<iostream>
using namespace std;
class shape{
int area=0;
public:
void fn(int l){
int area=l*l;
cout<<area<<endl;
cout<<this->area<<endl;
}
};
-----------------------------------------------------------------------
#include<iostream>
using namespace std;
class box{
  int width;
public:
  void setwidth(int w);
  friend void getwidth(box b);
};
void box::setwidth(int w){//cant use SRO as friend functions arent member functions
  width=w;
}
void getwidth(box b){//cant use SRO as friend functions arent member functions
  cout<<b.width;//cant use 'this' keyword too, here.
}
int main(){
box b;
getwidth(b);
b.setwidth(10);
return 0;
}
constructors are CRAP: same name as class, no return type, automatic execution, always public.
-----------------------------------------------------------------------
#include<iostream>
using namespace std;
class shape{
  int a;
public:
  int output(int l){
    cout<<l;
  }
  shape();
  ~shape();
};
shape::shape(){
  cout<<"ABC";
}
shape::~shape(){
  cout<<"DEF";
}
int main(){
  int a=5;
  shape s;
  s.output(5);
}
------------------------------
#include<iostream>
using namespace std;
int main(){
  int *l=NULL;//*l=0 also works
  l=new int;//creating address space so no '*'
  *l=99;
  cout<<l<<endl;//address print
  cout<<*l;//value print
  delete l;
}

-----------------------------------------------------

#include<iostream>
using namespace std;
class shape{
protected:
  int length, width;
public:
  int setlength(int l){length=l;}
  int setwidth(int w){width=w;}
};
class xyz{
public:
  int output(){
    cout<<"KUCH BHI\n";
  }
};
class rectangle: public shape,public xyz{//inheritance is early binding
  public:
    int area(){
  cout<<width*length<<endl;
 }
};
int main(){
   rectangle r;
   r.setlength(5);
   r.setwidth(10);
   r.area();
   r.output();
   return 0;
}
-------------------------------------------------------------
*/
#include<iostream>
using namespace std;
class shape{
  int l,w;
public:
  int area(){
    return l*w;
  }
  int setlen(int l){
    this->l=l;
  }
  int setwid(int w){
    this->w=w;
  }
};
shape operator + (shape const &shape s){
  shape s;
}
