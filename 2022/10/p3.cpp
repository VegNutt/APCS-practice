#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define MAXN 2000000000
using namespace std;

ll ans=0;
vector<int> v;

void dfs(int &node){
    int par = node;
    for(int i=0; i<(2+(v[par]%2)); ++i){
        node++;
        if(v[node] == 0) continue;
        ans += abs(v[par]-v[node]);
        dfs(node);
    }
}

int main(){
    int input, root=0;
    while(cin >> input) v.push_back(input);
    dfs(root);
    cout << ans;
}