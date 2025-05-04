#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define MAXN 2000000000
using namespace std;

unordered_map<ll,int> mp;
string str;
ll tmp, mask=0;

int cToI(char c){
    if(c <= 'Z') return c-'A';
    else return c-'a'+26;
}

int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    int m,n; cin >> m >>n;
    while(n--){
        cin >> str;
        tmp = 0;
        for(auto &it:str){
            tmp |= (ll)1 << (cToI(it));
        }
        mp[tmp]++;
    }
    int ans=0; 
    for(int i=0; i<m; ++i) mask |= (ll)1 << i;
    for(auto &it:mp){   
        tmp = mask ^ it.first;
        if(mp.count(tmp)) ans+=it.second*mp[tmp];
    }
    cout << ans/2;
}