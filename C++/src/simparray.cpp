#include<iostream>
using namespace std;


class Collab{
  public:
  static int m,n;

  Collab(){
    cout<<"Enter rows and columns of array: ";
    cin>>m>>n;
  }
  int A[m][n];
  void setA(){

    input();
  }

  void input()
  {
    // int m=5,n=5;
    for(int i=0;i<m;i++)
    {
      for(int j=0;j<n;j++)
      {
        cin>>A[i][j];
      }
      cout<<endl;
    }
  }

  void display()
  {
    // int m=5,n=5;
    for(int i=0;i<m;i++)
    {
      for(int j=0;j<n;j++)
      {
        cout<<A[i][j]<<" ";
      }
      cout<<endl;
    }
  }
};

main(){
  Collab c1;
  c1.setA();
}
