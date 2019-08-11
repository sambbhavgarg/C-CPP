#include<iostream>
using namespace std;
void organizer(int *a,int n){
  int i,j,k;
  int arr[n]=0;
  for(i=0;i<n*3;i++){
    for(j=0;j<3;j++){
      arr[i]+=a[i][j];
    }
  }
  do{
    for(k=0;k<n;k++){
      sum+=arr[i];
    }
  }
}
int main(){
  int i,j;
  cin>>n;
  int array[n*3][3];
  for(i=0;i<n*3;i++){
    for(j=0;j<3;j++){
    cin>>array[i][j];
    }
  }
  organizer(&array,n);
  return 0;
}
