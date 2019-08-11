#include<iostream>
#include<vector>

using namespace std;
int main(){
vector <int> vec;
vector <int>::iterator i;
vector <int>::reverse_iterator ir;

for(int i=0;i<5;i++){
vec.push_back(i);
}
for(i=vec.begin();i!=vec.end();++i){
cout<<*i<<" ";
}
cout<<endl;
for(ir=vec.rbegin();ir!=vec.rend();++ir){
cout<<*ir<<" ";}
cout<<endl;
}
