#include<bits/stdc++.h>
#define ll long long
#define F first
#define S second
using namespace std;

int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    int n,m,k; cin >> n >> m >> k;
    int t; cin >> t;
    queue<int> mykey;
    for(int i=0; i<t; ++i){
        int key; cin >> key;
        mykey.push(key);
    }

    vector<int> deg(n,k);
    vector<vector<int> > ktob(m);
    vector<vector<int> > btok(n);
    for(int i=0; i<n; ++i){
        for(int j=0; j<k; ++j){
            int key; cin >> key;
            ktob[key].push_back(i);
        }
    }
    for(int i=0; i<n; ++i){
        for(int j=0; j<k; ++j){
            int key; cin >> key;
            btok[i].push_back(key);
        }
    }
    vector<bool> cleared(n, false);
    int ans=0;
    while(!mykey.empty()){
        int key = mykey.front();
        mykey.pop();
        for(int box:ktob[key]){
            if(cleared[box]) continue;
            if(--deg[box] == 0){
                cleared[box] = true;
                ans++;
                for(int get:btok[box]){
                    if(!seenkey[get]){
                        mykey.push(get);
                        seenkey[get] = true;
                    }
                }
            }
        }
    }
    cout << ans;
}
