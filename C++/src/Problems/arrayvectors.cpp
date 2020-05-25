#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n , q, k, r, c,num;
    cin >> n >> q;
    vector<int> arr[n];
    for (int i = 0; i<n; i++){
        cin>>k;
        for(int j=0; j<k; j++){
            cin>>num;
            arr[i].push_back(num);
        }
    }
    for(int i=0; i<q; i++){
        cin>>r>>c;
        cout<<arr[r].at(c)<<endl;
    }
    return 0;

}
