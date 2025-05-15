#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define F first
#define S second
using namespace std;

vector<vector<int> > a;
vector<vector<bool> > vis;
vector<vector<bool> > v;
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}},col, row, k, cnt=0;

void chain(int i, int j){
    queue<pii>b;
    b.push({i,j});
    while(!b.empty()){
        int y=b.front().F, x=b.front().S;
        b.pop();
        cnt++;
        if(cnt >= k) return;
        v[y][x] = true;
        for(int d=0; d<4; ++d){
            int ny=y+dir[d][0], nx = x+dir[d][1];
            if(ny<0 || ny>=col || nx<0 || nx>=row || vis[ny][nx] || v[ny][nx] || a[ny][nx] == -1) continue;
            if(abs(ny-i)+abs(nx-j) >= a[i][j]) continue;
            b.push({ny,nx});
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> col >> row >> k;
    a.resize(col, vector<int>(row));
    vis.resize(col, vector<bool>(row,false));
    v.resize(col, vector<bool>(row,false));
    int sy,sx;
    for(int i=0; i<col; ++i){
        for(int j=0; j<row; ++j){
            cin >> a[i][j];
            if(a[i][j] == -2){
                sy=i,sx=j;
                a[i][j]=k;
            }
        }
    }
    queue <pii> q;
    q.push({sy,sx});
    vis[sy][sx] = true;
    int range=0;
    while(!q.empty()){
        int y=q.front().F, x=q.front().S;
        q.pop();
        if(v[y][x]==false) cnt++;
        range = max(range, abs(y-sy)+abs(x-sx));
        if(cnt >= k) break;
        a[y][x]=9;
        for(int d=0; d<4; ++d){
            int ny=y+dir[d][0], nx = x+dir[d][1];
            if(ny<0 || ny>=col || nx<0 || nx>=row || vis[ny][nx] || a[ny][nx] == -1) continue;
            bool toomuch= false;
            if(a[ny][nx] != 0) chain(ny,nx);
            q.push({ny,nx});
            vis[ny][nx] = true;
            if(cnt >= k) break;
        }
        if(cnt >= k) break;
    }
    cout << range;
    return 0;
}
