#include <bits/stdc++.h>
#define ll long long
#define MOD 1e9+7
#define MAXN 2e9
using namespace std;

int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    int n,m,k; cin >> n >> m >> k;
    vector<vector<int> > cost(n,vector<int>(m));
    for(auto &row:cost){
        for(auto &it:row) cin >> it;
    }
    int place,cnt, minCnt=MAXN;
    while(k--){
        vector<vector<int> > assign(m,vector<int>(m,0));
        cnt=0;
        for(int i=0; i<n; ++i){
            cin >> place;
            for(int j=0; j<m; ++j){
                assign[place][j] += cost[i][j];
            }
        }
        for(int i=0; i<m; ++i){
            for(int j=0; j<m; ++j){
                if(i==j) cnt += assign[i][j];
                else if(assign[i][j] <= 1000) cnt += assign[i][j]*3;
                else cnt += (assign[i][j]-1000)*2+3000;
            }
        }
        minCnt = min(minCnt, cnt);
    }
    cout << minCnt;
}