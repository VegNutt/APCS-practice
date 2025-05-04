#include<bits/stdc++.h>
#define MOD 1e9+7
#define MAXN 2e9
#define ll long long
using namespace std;

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int n,m; cin >> n >> m;
    vector<vector<int> > ex(n+1,vector<int>(m+1));
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j) cin >> ex[i][j];
    }
    int ans = -MAXN;
    vector<vector<vector<int> > > dp(n+2,vector<vector<int> >(m+2,vector<int>(3,0))); 
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            dp[i][j][0] = ex[i][j] + *max_element(dp[i-1][j].begin(), dp[i-1][j].end());
            dp[i][j][1] = ex[i][j] + max(dp[i][j-1][0], dp[i][j-1][1]);
        }
        for(int j=m; j>=1; --j){
            dp[i][j][2] = ex[i][j] + max(dp[i][j+1][0], dp[i][j+1][2]);
        }
    }
    int mx = -MAXN;
    for(int j=1; j<=m; ++j){
        mx = max(mx, *max_element(dp[n][j].begin(), dp[n][j].end()));
    }
    cout << mx;
}
