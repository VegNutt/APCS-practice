#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
using namespace std;

int n,m;
vector<vector<char> > sewer;
vector<vector<bool> > vis;
unordered_map<char, string> pipe = { // up down left right
        {'X', "1111"},
        {'I', "1100"},
        {'H', "0011"},
        {'L', "1001"},
        {'7', "0110"},
        {'F', "0101"},
        {'J', "1010"}
};
int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
int oppo[4] = {1, 0, 3, 2};

int dfs(int y, int x){
    int depth=1;
    vis[y][x] = true;
    for(int d=0; d<4; ++d){
        int ny=y+dir[d][0], nx=x+dir[d][1];
        if(ny<0 || ny>=n || nx<0 || nx>=m || vis[ny][nx]) continue;
        char c1 = sewer[y][x], c2 = sewer[ny][nx];
        if(pipe[c1][d]=='1' && pipe[c2][oppo[d]]=='1'){
            depth += dfs(ny, nx);
        }
    }
    return depth;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> n >> m;
    sewer.resize(n,vector<char>(m));
    vis.resize(n,vector<bool>(m, false));
    for(auto &row:sewer) for(char &it:row) cin >> it;
    int ans=0;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            if(!vis[i][j] && sewer[i][j]!='0') ans = max(ans, dfs(i,j));
        }
    }
    cout << ans;
}
