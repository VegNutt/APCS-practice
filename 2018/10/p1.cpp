#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, smol=10000009; cin >> n;
    vector<vector<string> > v(27);
    for(int i=0; i<n; ++i){
        string s; cin >> s;
        set<char> charSet;
        for(int j=0; j<s.length(); ++j) charSet.insert(s[j]);
        v[charSet.size()].push_back(s);
        smol = min(smol, (int)charSet.size());
    }
    sort(v[smol].begin(),v[smol].end());
    cout << v[smol][0];
}     