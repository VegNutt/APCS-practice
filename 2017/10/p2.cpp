#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    int k; cin >> k >> s;
    for(int i=0; i<s.length(); ++i){
        if(s[i]<='z' && s[i]>='a') s[i]='0';
        else s[i]='1';
    }
    int cnt=1;
    vector<int>v;
    for(int i=1; i<s.length(); ++i){
        if(s[i]==s[i-1]) cnt++;
        else{
            v.push_back(cnt);
            cnt=1;
        }
    }
    v.push_back(cnt);
    
    int ans=0, maxAns=0;
    for(int i=0; i<v.size(); ++i){
        if(v[i]==k) ans+=k;
        else if(v[i]>=k){
            ans+=k;
            maxAns = max(ans, maxAns);
            ans=k;
        }
        else{
            maxAns = max(ans, maxAns);
            ans=0;
        }
    }
    cout << max(ans, maxAns);
}