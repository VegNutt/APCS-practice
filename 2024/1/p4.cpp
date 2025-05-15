#include <bits/stdc++.h>
#define pii pair<int,int>
#define ll long long
#define F first
#define S second
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n; cin >> n;
    vector<vector<int> > cost(n+1, vector<int>(n+1)), value(n+1, vector<int>(n+1));
    for (int i=1; i<=n; ++i){
        cin >> value[i][i];
        cost[i][i]=0;
    }
    for(int len=2;len<=n; ++len){
        for(int l=1;l<=n-len+1; ++l){
            int r = l+len-1;
            cost[l][r] = 1e9;
            for(int k=l; k<r; ++k){
                cost[l][r] = min(cost[l][r], cost[l][k]+cost[k+1][r]+abs(value[l][k]-value[k+1][r]));
                value[l][r] = value[l][k]+value[k+1][r];
            }
        }
    }
    cout << cost[1][n];
}
