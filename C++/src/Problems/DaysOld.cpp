#include<iostream>
#include<map>
#include<iterator>

#define currentYear 2020
#define currentMonth 2
#define currentDay 21

using namespace std;

int daysBetweenBefore(map<int, int> mp, int birthDay, int birthMonth){
  if(currentMonth == birthMonth)
    return abs(currentDay-birthDay);
  else{
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
}

int daysBetweenAfter(map<int, int> mp, int birthDay, int birthMonth){
  if(currentMonth == birthMonth)
    return abs(currentDay-birthDay);
  else{
    auto it = mp.find(birthMonth);
    // cout<<it->second<<"\n";
    int daysBetween = 0;
    int daysToGoInBirthMonth = it->second - birthDay;
    for(int i = birthMonth+1; i<currentMonth; i++){
      it = mp.find(i);
      daysBetween += it->second;
    }
    daysBetween = daysBetween + daysToGoInBirthMonth + currentDay;
    // cout<<daysBetween;
    return daysBetween;
  }

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
  for(int i=start; i<end; i++)
    flag += isLeap(i);
  return flag;
}

int birthLeapToBeAdded(int birthYear){
  if(birthYear>2){
    return 0;
  }
  else {
    return 1;
  }
}

int currentLeapToBeAdded(){
  if(currentMonth>2){
    return 1;
  }
  else if(currentMonth == 2){
    if(currentDay == 29){
      return 1;
    }
    else if(currentDay <= 28){
      return 0;
    }
  }
  else{
    return 0;
  }
}

int leapDays(int birthYear){
  int totalLeap;
  if(isLeap(birthYear)){
    totalLeap = findLeap(birthYear+1, currentYear) + birthLeapToBeAdded(birthYear);
  }
  else{
    totalLeap = findLeap(birthYear, currentYear);
  }
  if(isLeap(currentYear)){
    totalLeap += currentLeapToBeAdded();
  }
  return totalLeap;
}

void createMonthHashTable(map<int, int> mp){
}

int main(){
  int birthDay, birthMonth, birthYear,birthLeap, currentLeap;
  map<int, int> mp;
  mp.insert({1,31});
  mp.insert({2,28});
  mp.insert({3,31});
  mp.insert({4,30});
  mp.insert({5,31});
  mp.insert({6,30});
  mp.insert({7,31});
  mp.insert({8,31});
  mp.insert({9,30});
  mp.insert({10,31});
  mp.insert({11,30});
  mp.insert({12,31});
  // createMonthHashTable(mp);
  // cout<<"Enter your birthdate seperated by '-'\nExample: 02-01-1999";
  cout<<"Enter your birth year: ";
  cin>>birthYear;
  cout<<"Enter your birth month: ";
  cin>>birthMonth;
  cout<<"Enter the day you were born: ";
  cin>>birthDay;

  int years = currentYear - birthYear;
  years = years*365;
  cout<<years<<endl;

  int addLeap = leapDays(birthYear);
  cout<<addLeap<<endl;

  if(currentDay == birthDay && currentMonth == birthMonth)
    years += addLeap;
  else if(currentDateBefore(birthDay, birthMonth)){
    years = years - daysBetweenBefore(mp, birthDay, birthMonth) + addLeap;
    cout<<daysBetweenBefore(mp, birthDay, birthMonth)<<endl;}
  else{
    years += daysBetweenAfter(mp, birthDay, birthMonth) + addLeap;
    cout<<daysBetweenAfter(mp, birthDay, birthMonth)<<endl;}


  cout<<"You are: "<<years<<" days old on "
    <<currentDay<<"/"
    <<currentMonth<<"/"
    <<currentYear<<"\n";
}
