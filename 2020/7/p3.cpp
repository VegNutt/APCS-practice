#include <bits/stdc++.h>
#define mod 1000000009
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m, total=0, input; cin >> n >>m;
    vector<int>prefix;
    for(int i=0; i<n; ++i){
        cin >> input;
        total += input;
        prefix.push_back(total);
    }
    int desire, cur=0;
    for(int i=0; i<m; ++i){ 
        cin >> desire;
        if(cur != 0) desire += prefix[cur-1];
        if(desire > prefix[n-1]) desire -= prefix[n-1];
        cur = (int)(lower_bound(prefix.begin(), prefix.end(), desire) - prefix.begin())+1;
        cur %= n;
    }
    cout << cur;
}//prefix