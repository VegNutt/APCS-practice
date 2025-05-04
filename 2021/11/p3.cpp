#include <bits/stdc++.h>
#define MAXN 2000000000
#define MOD 1000000007 
#define ll long long
using namespace std;


int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n,m,l,r,w; cin >> n >>m;
    vector<int> cnt(n+1,0);
    for(int i=0; i<m; ++i){
        cin >> l >> r >> w;
        cnt[l] += w;
        cnt[r+1] -= w;
    }
    for(int i=1; i<=n; ++i) cnt[i] += cnt[i-1];
    vector<int> time(n);
    for(int i=0; i<n; ++i) cin >> time[i];
    sort(cnt.begin(),cnt.end(), greater<int>());
    sort(time.begin(),time.end());
    ll ans=0;
    for(int i=0; i<n; ++i){
        ans += time[i]*cnt[i];
    }
    cout << ans;
}
