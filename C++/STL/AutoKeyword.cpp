#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Create a set of strings
    set<string> st;
    st.insert({ "geeks", "for", "geeks", "org" });

    // 'it' evaluates to iterator to set of string
    // type automatically
    for (auto it = st.begin(); it != st.end(); ++it)
        cout << *it << " ";
    cout<<endl;

    for(auto elem : st){
      cout<<elem<<" ";
    }
    cout<<endl;
    return 0;
}
