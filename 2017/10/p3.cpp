#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > rel;
vector<int> par;
vector<int> dist;

void dfs(int node) {
    int maxDepth = -1;
    for (auto &child : rel[node]) {
        dfs(child);
        maxDepth = max(maxDepth, dist[child]);
    }
    dist[node] = maxDepth+1;
}

int main() {
    int n, t, input;
    cin >> n;
    rel.resize(n); par.resize(n,-1);
    for (int i = 0; i < n; ++i) {
        cin >> t;
        while (t--) {
            cin >> input;
            par[input-1]=i;
            rel[i].push_back(input-1);
        }
    }
    dist.resize(n, 0);
    for (int i = 0; i < n; ++i) {
        if (par[i]==-1){
            dfs(i); 
            break;
        } 
    }
    
    long long gross=0;
    int rootDist = *max_element(dist.begin(), dist.end());
    for(int i=0; i<n; ++i){
        gross += dist[i];
        if(dist[i] == rootDist) cout << i+1 << endl;
    }
    cout << gross;
}
