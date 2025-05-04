#include<bits/stdc++.h>
#define MOD 1e9+7
#define MAXN 2e9
#define ll long long
using namespace std;

bool cmp(pair<int,int> f, pair<int,int> s){
    return f.first*s.second < s.first*f.second;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int n; 
    while(cin >> n){
        vector<pair<int,int> >box(n);
        for(auto &it:box) cin >> it.first;
        for(auto &it:box) cin >> it.second;
        sort(box.begin(), box.end(), cmp);
        ll ans=0, wt=0;
        for(int i=0; i<n-1; ++i){
            wt += box[i].first;
            ans += wt*box[i+1].second;
        }
        cout << ans << endl;
    }
}   