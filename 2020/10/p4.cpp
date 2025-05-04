#include<bits/stdc++.h>
#define MOD 1e9+7
#define MAXN 2e9
#define ll long long
using namespace std;

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int n, input; cin >> n;
    vector<vector<int> >rof(n+1);
    for(int i=1; i<=2*n; ++i){
        cin >> input;
        rof[input].push_back(i);
    }
    ll ans=0;
    for(int i=2; i<=n; ++i){
        for(int j=1; j<i; ++j){
            if(rof[j][0]>rof[i][0] && rof[j][0]<rof[i][1]) ans++;
            if(rof[j][1]>rof[i][0] && rof[j][1]<rof[i][1]) ans++;
        }
    }
    cout << ans;
}