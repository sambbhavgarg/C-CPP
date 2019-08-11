#include<stdio.h>
using namespace std;
class parent{
    string profession;
  protected:
    int id;
  public:
    int rank;
    void getid(){return id;}
    void getprof(){return profession;}
    void tester(){
      if(rank>=5){
        cout<<"Legal\n";
      }
      else
      cout<<"Illegal\n";
    }
    void getdata(){
      cout<<"Enter profession: ";
      cin>>profession;
      cout<<"Enter rank: ";
      cin>>rank;
      cout<<"Enter id: ";
      cin>>id;
    }
};
class child1 : public parent{
  void 
  void ranker(){cout<<rank; }
};
class child2 : protected parent{

};
class child3 : private parent{
}
int main(){
}
