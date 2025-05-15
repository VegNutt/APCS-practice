#include <bits/stdc++.h>
#define pii pair<int,int>
#define ll long long
#define F first
#define S second
using namespace std;

int dir[8][2] = {{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};

int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    int h,w,n; cin >> h >> w >> n;
    vector<vector<int> >graph(h, vector<int>(w,0));
    while(n--){
        vector<vector<bool> >vis(h, vector<bool>(w,0));
        int oy,ox,t,color; cin >> oy >> ox >> t >> color;
        queue<pii> q;
        q.push({oy,ox});
        vis[oy][ox] = true;
        while(!q.empty()){
            int y = q.front().F, x = q.front().S;
            q.pop();
            graph[y][x] += color;
            for(int i=0; i<8; ++i){
                int ny = y+dir[i][0], nx = x+dir[i][1];
                if(ny>=0 && ny<h && nx>=0 && nx<w && !vis[ny][nx] && (abs(ny-oy)+abs(nx-ox))<=t){
                    vis[ny][nx] = true;
                    q.push({ny,nx});
                }
            }
        }
    }
    for(auto row:graph){
        for(int it:row) cout << it << " ";
        cout << endl;
    }
}

