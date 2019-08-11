#include<iostream>
#include<math.h>
using namespace std;
int checkprime(int checko){
  double sq=sqrt(checko);
  int count=0;
  for(int i=2;i<sq;i++){
    if(checko%i==0)
      count++;
  }
  if(count)
   return 1;
  else
   return 0;
}
using namespace std;
int main(){
  int times=0, i=0, j=0;
  int a,sum=0;
  cin>>a;
  int in[a][3][3];
  for(times=0;times<a;times++){
    for(i=0;i<3;i++){
      for(j=0;j<3;j++){
        cin>>in[times][i][j];
      }
     }
     cout<<endl<<endl;
    }
  for(times=0;times<a;times++){
    for(i=0;i<3;i++){
      for(j=0;j<3;j++){
        if((i+1)!=3 && (j+1)!=3){
          sum=in[times][i][j]+in[times][i+1][j+1];
          int ch=checkprime(sum);
          if(ch){
            in[times][i][j]=in[times][i][j]^in[times][i+1][j+1];
            in[times][i+1][j+1]=in[times][i+1][j+1]^in[times][i][j];
            in[times][i][j]=in[times][i][j]^in[times][i+1][j+1];
          }
          else
            continue;
          }
        }
      }
  }
  for(times=0;times<a;times++){
    for(i=0;i<3;i++){
      for(j=0;j<3;j++){
        cout<<in[times][i][j]<<" ";
      }
      cout<<endl;
     }
     cout<<endl<<endl;
    }
}
