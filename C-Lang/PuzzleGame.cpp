#include<iostream>
using namespace std;
int main(){
  int n;
  cin>>n;
  int array[n*3][3];
  for(int i=0;i<n*3;i++){
    for(int j=0;j<3;j++){
    cin>>array[i][j];
    }
  }
  for(i=0;i<n*3;i++){
    for(j=0;j<3;j++){
      if(array[i][j]<array[i+1][j] && array[i][j]<array[i+2][j1]){
        int c++;
        if(c==3){
          if(array[i+1][j]<array[i+2][j]){
            cout<<"yes";
          }
          else
          cout<<"no";
        }
      }
      if(j==2)
       i+=3;
    }
  }
}
