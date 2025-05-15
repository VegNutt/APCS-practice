#include <bits/stdc++.h>
#define pii pair<int,int>
#define ll long long
#define F first
#define S second
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int m, n, k; cin >> m >> n >> k;
    int dir[6][2] = {{-1,0},{0,1},{1,1},{1,0},{0,-1},{-1,-1}};
    vector<vector<char> > hive(m,vector<char>(n));
    for(auto &row:hive) for(char &it:row) cin >> it;
    int input, y=m-1, x=0;
    set<char>cnt;
    for(int i=0; i<k; ++i){
        cin >> input;
        int ny = y+dir[input][0], nx = x+dir[input][1];
        if(ny<0 || ny>=m || nx<0 || nx>=n){
            cout << hive[y][x];
            continue;
        }
        cnt.insert(hive[ny][nx]);
        cout << hive[ny][nx];
        y=ny,x=nx;
    }
    cout << "\n" << cnt.size();
}

