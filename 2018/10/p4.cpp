#include <bits/stdc++.h>
using namespace std;

int main(){
    int m,s,n; cin >> m >> s >> n;
    vector<int> locker(n);
    for(auto &it:locker) cin >> it;       
    vector<vector<int> >dp(n+1,vector<int>(m+1,0));
    for(int i=0; i<=n; ++i) dp[i][0]=1; 

    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            if(dp[i-1][j])  dp[i][j] = 1;
            else if(j>=locker[i-1]){
                if(dp[i-1][j-locker[i-1]]) dp[i][j] = 1;
            }
        }
    }
    for(int j=s; j<=m; ++j){
        if(dp[n][j]){
            cout << j;
            break;
        }
    }
}