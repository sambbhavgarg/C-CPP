/*
Name: Sambbhav Garg
SAP ID: 500061353
Roll Number: R103217092



//Question1

#include<iostream>
#include<string>
using namespace std;
class Account{
  public:
  string name;
  int accno;
  double balance=0.00f;
  Account(){
    cout<<"Enter name: ";
    cin>>name;
    cout<<"Enter Account Number: ";
    cin>>accno;
  }
  void deposit(int);
  void withdraw(int);
  void display();
};
void Account::deposit(int n){
  balance+=n;
  cout<<"Balance is: "<<balance<<endl;
}
void Account::withdraw(int n){
  if((balance-n)<0)
    cout<<"Sorry, inadequate balance.\nMaximum withdrawable amount= "<<balance<<endl;
  else if(balance>0){
    balance-=n;
    cout<<"Balance is: "<<balance<<endl;
  }
}
void Account::display(){
  cout<<"Name: "<<name<<endl<<"Account Number: "<<accno<<endl<<"Account Balance: "<<balance<<endl;
}
int main(){
  Account a;
  int T,n;
  do{
    cout<<"1. Withdraw, 2. Deposit, 3. Receipt, 4. Exit\n";
    cin>>n;
    switch(n){
      case 1: cout<<"Enter Amount: ";
              cin>>T;
              a.withdraw(T);
              break;
      case 2: cout<<"Enter Amount: ";
              cin>>T;
              a.deposit(T);
              break;
      case 3: a.display();break;
    }
  }while(n!=4);
  return 0;
}

//Question 2

#include<iostream>
using namespace std;
class Date{
  int date, month, year;
public:
  Date(int d=0, int m=0, int y=0){
    date=d;
    month=m;
    year=y;
  }
  void print(){
    cout<<"dd/mm/yyyy: "<<date<<"/"<<month<<"/"<<year<<endl;
  }
  friend Date operator +(Date const &, Date const &);
};
Date operator+(Date const &c,Date const &c1){
  return Date(c.date+c1.date,c.month+c1.month,c.year+c1.year);
}
int main(){
  Date d(2,1,1999),d1(12,12,1963);
  Date d2=d+d1;
  d2.print();
  return 0;
}
