#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
int main(){
    int n, L, R; cin >> n;
    deque<pair<int, int>> dp;
    while(n--){
        cin >> L >> R;
        dp.push_back({L,R});
    }
    sort(dp.begin(), dp.end());
    int ans=0;
    while(dp.size()-1){
        if(dp[0].S > dp[1].F){
            dp[1].F = min(dp[0].F, dp[1].F);
            dp[1].S = max(dp[0].S, dp[1].S);
            dp.pop_front();
        }
        else{
            ans += (dp[0].S- dp[0].F);
            dp.pop_front();
        }
    }
    ans += (dp[0].S- dp[0].F);
    cout << ans;
}
