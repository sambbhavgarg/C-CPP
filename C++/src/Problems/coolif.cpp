#include <bits/stdc++.h>
// #include <cstring>
// #include <stdexcept>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string name[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "Greater than 9"};
    int lengthName = sizeof(name)/sizeof(name[0]);
    string nameFinal = n<=9 ? name[n-1] : name[lengthName-1];
    cout<<nameFinal<<endl;
    return 0;
}
