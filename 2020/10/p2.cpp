#include<bits/stdc++.h>
#define MOD 1e9+7
#define MAXN 2e9
#define ll long long
using namespace std;

int r,c,k,m;
int dir[8][2] = {{-1,0}, {-1,-1}, {0,-1}, {1,-1}, {1,0}, {1,1}, {0,1}, {-1,1}};
vector<vector<int> > cities;
vector<vector<int> > tmp;

void immigrant(){
    tmp = cities;
    int ny,nx;
    for(int i=0; i<r; ++i){
        for(int j=0; j<c; ++j){
            if(cities[i][j]==-1) continue;
            for(int d=0; d<8; ++d){
                ny = i+dir[d][0];
                nx = j+dir[d][1];
                if(ny>=0 && nx>=0 && ny<r && nx<c && cities[ny][nx]!=-1){
                    tmp[i][j] -= cities[i][j]/k;
                    tmp[ny][nx] += cities[i][j]/k;
                }
            }
        }
    }
    cities = tmp;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> r >> c >> k >> m;
    cities.resize(r,vector<int>(c));
    for(auto &row:cities){
        for(auto &it:row) cin >> it;
    }
    for(int i=0; i<m; ++i)  immigrant();
    int mx=0, mn=MAXN;
    for(int i=0; i<r; ++i){
        for(int j=0; j<c; ++j){
            if(cities[i][j] > mx) mx = cities[i][j];
            if(cities[i][j]<mn && cities[i][j]!=-1) mn = cities[i][j];
        }
    }
    cout << mn << endl << mx << endl;
}