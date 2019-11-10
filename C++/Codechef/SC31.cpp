#include<iostream>
#include<string>
using namespace std;

int toBinary(int n){
  int count = 0;
  while (n) {
      if (n & 1)
        count++;
      n >>= 1;
  }
  return count;
}

int main(){
  int t, n, i, j, temp, temp2, final;
  string s;
  cin>>t;
  for(i=0; i<t; i++){
    cin>>n;
    for(j=0; j<n; j++){
      cin>>s;
      if(j == 0){
        temp = stoi(s, nullptr, 2);
        continue;
      }
      temp2 = stoi(s, nullptr, 2);
      temp = temp ^ temp2;
    }
    // cout<<temp<<endl;
    final = toBinary(temp);
    cout<<final<<endl;
  }
  return 0;
}
