#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

vector<int> stringToInteger(string str){
  vector<int> vect;

  stringstream ss(str);

  for (int i; ss >> i;) { //loop till stringstream object ss reads integers from str in i.
      vect.push_back(i);
      // if (ss.peek() == ' ')
      //     ss.ignore();
  }
  return vect;
}

int main()
{
  int n;
  vector <int> vect;
  string line;
  cin >> n;
  cin.ignore();
  int minsLeft[n][2];
  for (int cnt = 0; cnt < n; cnt++) {
   getline(cin, line);
   vect = stringToInteger(line);
   minsLeft[cnt][0] = vect[0];
   minsLeft[cnt][1] = vect[1];
  }

  for(int i=0; i<n; i++){
    cout<< ((24 - minsLeft[i][0] - 1)*60)-(minsLeft[i][1] - 60);
    cout<<endl;
  }
}
