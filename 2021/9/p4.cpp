#include<bits/stdc++.h>
#define MAXN 2e9
#define MOD 1e9+7
#define ll long long
#define pii pair<int,int>
using namespace std;

int main(){
    ios::sync_with_stdio(false),cin.tie(0);
    int n,m; cin >> n >> m;
    vector<int> v(n);
    for(auto &it:v) cin >> it;
    for(int i=0; i<=n-1; ++i){
        set<int>st;
        int cur=i%n;
        while(true){
            if(st.count(v[cur])){
                cout << st.size() << " ";
                pq.push(st.size());
                if(pq.size()>m) pq.pop();  
                break;
            }
            else{
                st.insert(v[cur]);
                cur = (cur+1)%n;
            }
        }
    }
    ll ans=0;
    while(!pq.empty()){
        ans+=pq.top();
        pq.pop();
    }
    cout << ans;
}