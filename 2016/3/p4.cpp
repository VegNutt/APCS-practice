#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> tree;
vector<bool> vis;
int mxDist, farthest_node = -1;

void dfs(int node, int dist){//大型資料再cosnt + &
    if(dist > mxDist){
        farthest_node = node;
        mxDist = dist;

    }
    for(auto &next:tree[node]){
        if(!vis[next]){
            vis[next]=true;
            dfs(next, dist+1);
        }
    }
}

int main(){
    int N; cin >> N;
    tree.assign(N, vector<int>());
    // = tree.resize(N);

    while(N-->1){
        int parent, child;
        cin >> parent >> child;
        tree[parent].push_back(child);
        tree[child].push_back(parent);
    }

    vis.assign(tree.size(), false);
    mxDist = -1;
    vis[0] = true;
    dfs(0,0);

    vis.assign(tree.size(), false);
    mxDist = -1;
    vis[farthest_node] = true;
    dfs(farthest_node,0);

    cout << mxDist;
}
