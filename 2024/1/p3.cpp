#include <bits/stdc++.h>
#define pii pair<int,int>
#define ll long long
#define F first
#define S second
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int p,q,r,m; cin >> p >> q >> r >> m;
    int n = p+q+r;
    vector<int> input(p);
    for(auto &it:input) cin >> it;
    vector<vector<int> >logic_gate(q,vector<int>(3,-1)); //0:type 1,2: input
    for(auto &it:logic_gate) cin >> it[0];
    vector<vector<int> > circuit(n+1);
    vector<int> indeg(n+1, 0);
    vector<int> output(r);
    for(int i=0; i<m; ++i){
        int a,b; cin >> a >> b;
        circuit[a].push_back(b);
        indeg[b]++;
        if (b >= p+1 && b <= p+q) {
            int idx = b-p-1;
            if (logic_gate[idx][0] == 4) {
                logic_gate[idx][1] = a;
            }
            else {
                if (logic_gate[idx][1] == -1) logic_gate[idx][1] = a;
                else logic_gate[idx][2] = a;
            }
        }
        else if(b > p+q) output[b-p-q-1] = a;
    }
    queue<int> qu;
    for(int i=1; i<=p; ++i) qu.push(i);
    vector<int> topo_order;
    while (!qu.empty()) {
        int u = qu.front();
        qu.pop();
        topo_order.push_back(u);
        for (int v : circuit[u]) {
            indeg[v]--;
            if (indeg[v] == 0) {
                qu.push(v);
            }
        }
    }
    vector<int> delay(n+1, 0);
    vector<int> data(n+1, -1);
    for (int cur:topo_order) {
        if (cur <= p) {
            data[cur] = input[cur-1];
        }else if(cur > p+q){
            data[cur] = data[output[cur-p-q-1]];
        } else {
            int type = logic_gate[cur-p-1][0];
            int idx1 = logic_gate[cur-p-1][1];
            int idx2 = logic_gate[cur-p-1][2];

            if (type == 1) { // AND
                data[cur] = data[idx1] & data[idx2];
            } else if (type == 2) { // OR
                data[cur] = data[idx1] | data[idx2];
            } else if (type == 3) { // XOR
                data[cur] = data[idx1] ^ data[idx2];
            } else if (type == 4) { // NOT
                data[cur] = 1-data[idx1];
            }
            delay[cur] = max(delay[idx1], type==4 ? 0 : delay[idx2]) + 1;
        }
    }
    cout << *max_element(delay.begin(), delay.end()) << endl;
    for (int i=p+q+1; i<=n; ++i) {
        if (i > p+q+1) cout << " ";
        cout << data[i];
    }
}
