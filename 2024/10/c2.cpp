#include<bits/stdc++.h>
#define ll long long
#define F first
#define S second
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int col, row, k, y, x; cin >> col >> row >> k >> y >> x;
    vector<vector<int> > a(col, vector<int>(row));
    for(auto &r:a) for(int &it:r) cin >> it;
    int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}},score=0, gem=0,d=0;
    while(a[y][x] != 0){
        score += a[y][x];
        gem++; a[y][x]--;
        if(score%k==0) d++;
        int ny = y+dir[d%4][0], nx = x+dir[d%4][1];
        while(ny<0 || ny >= col || nx < 0 || nx >= row || a[ny][nx] == -1){
            d++;
            ny = y+dir[d%4][0], nx = x+dir[d%4][1];
        }
        y=ny, x=nx;
    }
    cout << gem;
    return 0;
}

