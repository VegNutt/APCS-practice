#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int k,q,r; cin >> k>>q>>r;
    vector<vector<char> > ans(q+1, vector<char>(k));
    for(int j=0; j<k; ++j) cin >> ans[0][j];

    vector<vector<int> > graph(q, vector<int>(k));
    for(auto &row:graph) for(auto &it:row) cin >> it;

    for(int c=1; c<=q; ++c){
        for(int row=0; row<k; ++row){
            ans[c][graph[c-1][row]-1] = ans[c-1][row];
        }
    }
    for(int i=0; i<r; ++i){
        for(int c=1; c<=q; c++) cout << ans[c][i];
        cout << endl;
    }
}
