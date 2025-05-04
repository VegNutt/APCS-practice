#include<bits/stdc++.h>
#define MAXN 2000000000
#define MOD 1000000007
#define ll long long
using namespace std;

vector<ll> pre;
vector<int> v;

int findCut(const int &s, const int &e){
    int mn = MAXN, cut;
    for(int i=s; i<=e; ++i){
        if(mn > v[i]){
            mn = v[i];
            cut = i;
        }
    }
    return cut;
}

int main(){
    ios::sync_with_stdio(false),cin.tie(0);
    int n,input, total=0; cin >> n;
    v.resize(n+1), pre.resize(n+1);
    v[0]=MAXN;
    for(int i=1; i<=n; ++i){
        cin >> v[i];
        pre[i]=pre[i-1]+v[i];
    }
    int stPoint=1, edPoint = n;
    int cut = findCut(stPoint, edPoint);
    while(true){
        ll lSum = pre[cut-1]-pre[stPoint-1];
        ll rSum = pre[edPoint]-pre[(cut+1)-1];

        if(rSum >= lSum) stPoint = cut+1;
        else edPoint = cut-1;
        if(stPoint >= edPoint) break;
        cut = findCut(stPoint, edPoint);
    }
    cout << pre[edPoint]-pre[edPoint-1];
}