#include<iostream>
#include<map>
#include<iterator>

#define currentYear 2020
#define currentMonth 2
#define currentDay 20

using namespace std;

int findLeap(int start, int end){
  for(int i=start; i<=end; i++){

  }
}

int checkLeapCovered(int date, int month){

}

void createMonthHashTable(map<int, int> months){

  months.insert({1,31});
  months.insert({2,28});
  months.insert({3,31});
  months.insert({4,30});s
  months.insert({5,31});
  months.insert({6,30});
  months.insert({7,31});
  months.insert({8,31});
  months.insert({9,30});
  months.insert({10,31});
  months.insert({11,30});
  months.insert({12,31});
}

int main(){
  int d, m, y, daysBetween = 0;
  map<int, int> months;
  map<int, int>::iterator i;
  createMonthHashTable(months);
  // cout<<"Enter your birthdate seperated by '-'\nExample: 02-01-1999";
  cout<<"Enter your birth year: ";
  cin>>y;
  cout<<"Enter your birth month: ";
  cin>>m;
  cout<<"Enter the day you were born: ";
  cin>>d;

  int years = currentYear - y;
  int daysToBeAddedForLeapYears = findLeap(y, currentYear);

  years = years*365 + daysToBeAddedForLeapYears;

  it = mp.find(m);
  int daysInBirthMonth = it->second - d;
  for(int i = m+1; i<currentMonth; i++){
    it = mp.find(i);
    daysBetween += it->second;
  }
  daysBetween = daysBetween + daysInBirthMonth + currentDay + years;
  if(!checkLeapCovered)
    daysBetween -= 1;
  cout<<"You are: "<<daysBetween<<" days old on "
    <<currentDay<<"/"
    <<currentMonth<<"/"
    <<currentYear<<"/\n";
}
