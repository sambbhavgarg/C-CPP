/*
ADS
date: 24/1/18
-protected access-
::- scope resolution operator; allows us to refer to parts of a class or structure
classname refvar=refvar.memfun(); works just fine??
#types of member functions:
-simple: dont have any spcl keyword like static as prefix.
-static: static member fns hold their positions. can be used with data members as well as member
functions. static makes memory allocation constant.
-const: value becomes constant not memory space
-inline: member functions defined inside class are inline. compiler does not call function, code of
          function is used instead in place of call.
1)inline fns dont have overhead of other fns.(independent execution)
2)accessing/changing fields of class instance is fast
3)not all inline fns are honoured eg: complex functions etc
inline void fname(arguments);//now no matter where the fn def is compiler will directly execute code.
no call.
-friend
static classes dont need objects to call other static classes.
we need objects to call static data from non static locations.
functions can be called by class name: X::f();
Dynamic memory allocation: to formulate memory at runtime to avoid memory requirment ambiguity.
      this memory is stored in heap
default arguments: when you put 0 in one of the arguments to default the value.
once default value is used for an arg, all subsequent arguments must have a default value.
Operator overloading
*/
#include<iostream>
using namespace std;
class try{
void tried(int a,int b, int c=5){
int sum=a+b+c;
}
void show(){
cout<<"sum: "<<sum<<"\n";
}
};
int main(){
try t;
t.tried(1,2);
t.show();
}
