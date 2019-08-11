#include<iostream>
using namespace std;
int main(){
   int a=5,b=0;
   double c;
   cout<<"Before try\n";
   try{
     cout<<"before throw inside try\n";
     if(b==0)
     throw "Division by 0 is not possible\n";
     c=a/b;
     cout<<"c is: "<<c<<" After throw\n";
   }
   catch(const char*exc){
   cerr<<exc;//cerr is an object of class ostream that represents the standard error stream oriented to narrow characters (of type char).
             //It corresponds to the C stream stderr.
             //The standard error stream is a destination of characters determined by the environment.
             //This destination may be shared by more than one standard object (such as cout or clog).
   }
   cout<<"after catch\n";
}

/*
std::exception is parent class of all c++ exceptions
when an object is created inside a try block destructor
 for an object is called before control is passed to the catch block
*/
