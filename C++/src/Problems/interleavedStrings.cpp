#include<iostream>
#include<string.h>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        for(int i=0; i<s3.length(); i++){
            if(!s3.empty()){
                if(s3[i] == s1[0] && !s1.empty())
                    s1.erase(0);
                else if(s3[i] == s2[0] && !s2.empty())
                    s2.erase(0);
                else
                    return false;
            }     
            else
                return true;
        }
    }
};


string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s1 = stringToString(line);
        getline(cin, line);
        string s2 = stringToString(line);
        getline(cin, line);
        string s3 = stringToString(line);

        bool ret = Solution().isInterleave(s1, s2, s3);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
