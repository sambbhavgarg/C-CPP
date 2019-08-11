#include<iostream>
using namespace std;
class Hello{
public:
Hello(){cout<<"cons for hello\n";}
~Hello(){cout<<"Dest for hello\n";}
};
int main(){
Hello h1;
try {
Hello h2;
throw 10;
}
catch(int i){
cout<<"caught "<<i<<endl;
}
return 0;
}
