#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n,k; cin >> n >> k;
    vector<int> profits(n);
    for(int &it: profits) cin >> it;
    vector<vector<int> > dp(n, vector<int>(k+1, INT_MIN));
    int mx=0, curSum=0;
    for (int j = 0; j <= k; ++j) {
        dp[0][j] = (j==0 ? profits[0] : 0);
        mx = max(mx, dp[0][j]);
    }
    for(int i=1; i<n; ++i){
        for(int j=0; j<=k; ++j){
            // not use
            if(dp[i-1][j] != INT_MIN){
                dp[i][j] = dp[i-1][j]+profits[i];
            }
            // use
            if(j>0 && dp[i-1][j-1] != INT_MIN){
                dp[i][j] = max(dp[i][j], dp[i-1][j-1]);
            }
            // give up prev
            dp[i][j] = max(dp[i][j], (j==0 ? profits[i] : 0));

            mx = max(mx, dp[i][j]);
        }
    }
    cout << mx;
}
