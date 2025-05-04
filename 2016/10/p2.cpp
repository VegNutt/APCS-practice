#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,m; cin >> n >> m;
    vector<vector<int> > v(n,vector<int>(m));
    for(auto &row:v){
        for(auto &it:row) cin >> it;
    }
    int total=0;
    vector<int> ans;
    for(auto &row:v) {
        row[0] = *max_element(row.begin(), row.end());
        total+=row[0];
    }
    cout << total << endl;
    for(int i=0; i<n; ++i){
        if(total % v[i][0]) continue;
        ans.push_back(v[i][0]);
    }
    if(ans.empty()) cout << -1;
    else{
        for(int i=0; i<ans.size()-1; ++i){
            cout << ans[i] << " ";
        }
        cout << ans[ans.size()-1];
    }
}
//sort 2d array and pair array...