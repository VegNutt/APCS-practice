#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, d; cin >> n >> d;
    vector<vector<int> >mat(n, vector<int>(n));
    for(auto &row:mat) for(auto&it:row) cin >> it;
    int dir[4][2] = {{0,-1}, {-1,0}, {0,1}, {1,0}};
    pair<int,int> cur = {n/2,n/2};
    int speed=1;
    vector<int> ans(1,mat[cur.first][cur.second]);
    while(ans.size() < n*n-(n-1)){
        for(int i=0; i<speed; ++i){
            cur.first+=dir[d][0];
            cur.second+=dir[d][1];
            ans.push_back(mat[cur.first][cur.second]);
        }
        if(ans.size() < n*n-(n-1)){
            d = (d+1)%4;
            for(int i=0; i<speed; ++i){
                cur.first+=dir[d][0];
                cur.second+=dir[d][1];
                ans.push_back(mat[cur.first][cur.second]);
            }  
            d = (d+1)%4;
            speed++;
        }
        else break;
    }
    speed--;
    for(int i=0; i<speed; ++i){
            cur.first+=dir[d][0];
            cur.second+=dir[d][1];
            ans.push_back(mat[cur.first][cur.second]);
    }
    for(auto &it:ans) cout << it;
}