#include <bits/stdc++.h>
using namespace std;
vector<int> rel;
vector<int> vis;

void dfs(const int &node){
    vis[node]=1;
    if(!vis[rel[node]]) dfs(rel[node]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie();
    int n,cnt=0; cin >> n;
    rel.resize(n); vis.resize(n);
    for(auto &it:rel) cin >> it;

    for(int i=0; i<n; ++i){
        if(!vis[i]) {
            dfs(i);
            cnt++;
        }
    }
    cout << cnt;
}
