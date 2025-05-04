#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,a,b; cin >> n >>m;
    vector<int>dice{1,4,2};
    vector<vector<int> >save(n,dice);
    int u,f,s;
    for(int i=0; i<m; ++i){
        cin >> a >> b;
        if(b>0) swap(save[a-1],save[b-1]);
        else if(b == -1){
            u = 7-save[a-1][1];
            f = save[a-1][0];
            save[a-1][0] = u;
            save[a-1][1] = f;
        }
        else{
            u = 7-save[a-1][2];
            s = save[a-1][0];
            save[a-1][0] = u;
            save[a-1][2] = s;
        }   
    }
    for(auto &row:save) cout << row[0] << " ";

}