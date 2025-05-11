#define ll long long
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;cin >> n >> m;
    vector<vector<int> > graph(n,vector<int>(m));
    for(auto &row:graph) for(int &it:row) cin >> it;
    vector<pair<int, int> > ans;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            int x = graph[i][j], total=0;
            for(int a=i-x; a<=i+x; ++a){
                for(int b=j-x; b<=j+x; ++b)
                if(a>=0 && a<n && b>=0 && b<m){
                    if(abs(a-i)+abs(b-j) <= x) total += graph[a][b];
                }
            }
            if(total%10 == x%10) ans.push_back({i,j});
        }
    }
    cout << ans.size() << "\n";
    for(auto it:ans){
        cout << it.first << " " << it.second << "\n";
    }
}
