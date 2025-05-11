#define pii pair<int,int>
#define F first
#define S second
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    vector<pii> activities(n);
    for(int i=0; i<n; ++i) cin >> activities[i].F;
    for(int i=0; i<n; ++i) cin >> activities[i].S;
    sort(activities.begin(), activities.end(), [](auto &a, auto &b) {return a.S < b.S;});
    multiset<int> endtimes;
    for(int i=0; i<k; ++i) endtimes.insert(1e8);

    int ans=0;
    for(auto cur: activities){
        auto it = endtimes.upper_bound(1e8 - cur.F);
        if (it == endtimes.end()) continue;
        endtimes.erase(it);
        endtimes.insert(1e8 - cur.S);
        ans++;
    }
    cout << ans;
}
