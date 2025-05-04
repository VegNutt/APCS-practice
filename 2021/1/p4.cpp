#include <bits/stdc++.h>
#define ll long long
#define MOD 1e9+7
#define MAXN 2e9
using namespace std;

int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    int n,a,b,xMax=0,yMax=0; cin >> n;
    vector<vector<int>> dp(101, vector<int>(101, 0));
    for(int i=0; i<n; ++i){
        cin >> a >> b;
        dp[b][a]=1;
        xMax = max(xMax, a);
        yMax = max(yMax, b);
    }
    for(int j=1; j<=xMax; ++j){
        for(int i=1; i<=yMax; ++i){
            dp[i][j] += max(dp[i][j-1], dp[i-1][j]);
        }
    }
    cout << dp[xMax][yMax];
}