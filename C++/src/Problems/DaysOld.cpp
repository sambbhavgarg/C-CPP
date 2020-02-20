#include<iostream>
#include<map>
#include<iterator>

#define currentYear 2020
#define currentMonth 2
#define currentDay 20

using namespace std;

int daysBetweenBefore(map<int, int> mp, int birthDay, int birthMonth){
  auto it = mp.find(currentMonth);
  int daysBetween = 0;
  int daysInCurrentMonth = it->second - currentDay;
  for(int i = currentMonth+1; i<birthMonth; i++){
    it = mp.find(i);
    daysBetween += it->second;
  }
  daysBetween = daysBetween + daysInCurrentMonth + birthDay;
  return daysBetween;
}

int daysBetweenAfter(map<int, int> mp, int birthDay, int birthMonth){
  auto it = mp.find(birthMonth);
  int daysBetween = 0;
  int daysInBirthMonth = it->second - birthDay;
  for(int i = birthMonth+1; i<currentMonth; i++){
    it = mp.find(i);
    daysBetween += it->second;
  }
  daysBetween = daysBetween + daysInBirthMonth + currentDay;
  return daysBetween;
}

int currentDateBefore(int birthDate, int birthMonth){
  if(birthMonth > currentMonth)
    return 1;
  else if(birthMonth == currentMonth){
    if(birthDate > currentDay)
      return 1;
    else if(birthDate < currentDay)
      return 0;
  }
  return 0;
}

int isLeap(int year){
  if(((year%4 == 0) && (year%100 != 0)) || (year%400 == 0))
    return 1;
  return 0;
}

int findLeap(int start, int end){
  int flag=0;
  for(int i=start; i<=end; i++)
    flag += isLeap(i);
  return flag;
}

int checkLeapCovered(){
  if(isLeap(currentYear)){
    if(currentMonth>2)
      return 1;
    else if(currentMonth == 2){
      if(currentDay == 29)
        return 1;
      return 0;
    }
    return 0;
  }
}

void createMonthHashTable(map<int, int> months){
  months.insert({1,31});
  months.insert({2,28});
  months.insert({3,31});
  months.insert({4,30});
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
  int birthDay, birthMonth, birthYear;
  map<int, int> mp;
  createMonthHashTable(mp);
  // cout<<"Enter your birthdate seperated by '-'\nExample: 02-01-1999";
  cout<<"Enter your birth year: ";
  cin>>birthYear;
  cout<<"Enter your birth month: ";
  cin>>birthMonth;
  cout<<"Enter the day you were born: ";
  cin>>birthDay;

  int years = currentYear - birthYear;
  years = years*365;

  int currentLeap = checkLeapCovered();
  int addLeap = findLeap(birthYear, currentYear) + currentLeap;

  if(currentDay == birthDay && currentMonth == birthMonth)
    years += addLeap;
  else if(currentDateBefore(birthDay, birthMonth))
    years -= daysBetweenBefore(mp, birthDay, birthMonth) + addLeap;
  else
    years += daysBetweenAfter(mp, birthDay, birthMonth) + addLeap;

  cout<<"You are: "<<years<<" days old on "
    <<currentDay<<"/"
    <<currentMonth<<"/"
    <<currentYear<<"\n";
}
