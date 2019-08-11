#include<iostream>
using namespace std;

class student{
  public:
    student(){
      static int static_var=0;
      for(int i=0; i<3; ++i){
        makestat(static_var);
      }
    }
  void makestat(int static_var){
    int var=0;
    cout<<"static: "<<static_var<<"\nint: "<<var<<"\n";
    var++;
    static_var++;
    cout<<"static: "<<static_var<<"\nint: "<<var<<"\n";

  }
};

int main(){
  student s1;

}
