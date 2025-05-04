#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > graph;
vector<vector<bool> > vis;
int dir[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};

bool valid(const int &y, const int &x){
    return (y>=0 && x >=0 && y<graph.size() && x<graph[0].size()) && vis[y][x]==false;
}

int dfs(const int &y, const int &x, int sum){
    int mn = 1000000, nexty, nextx, newy, newx;
    vis[y][x] = true;
    sum += graph[y][x];
    for(int i=0; i<4; ++i){
        newy = y+dir[i][0], newx = x+dir[i][1];
        if(valid(newy,newx) && mn > graph[newy][newx]){
            mn = graph[newy][newx];
            nexty = newy; 
            nextx = newx;
        }
    }
    if(mn == 1000000) return sum;
    return dfs(nexty, nextx, sum);
}

int main(){
    int n,m,mn = 1000000,sy,sx; cin >> n >> m;
    graph.resize(n,vector<int>(m)); vis.resize(n,vector<bool>(m, false));
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            cin >> graph[i][j];
            if(mn > graph[i][j]){
                mn = graph[i][j];
                sy = i; 
                sx = j;
            }
        }
    }
    cout << dfs(sy,sx, 0);
}