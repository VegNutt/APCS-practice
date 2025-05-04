#include<bits/stdc++.h>
#define MOD 1e9+7
#define MAXN 2e9
#define ll long long
using namespace std;

int main(){
    vector<ll> f1(3);
    vector<ll> f2(3);
    for(ll &it:f1) cin >> it;
    for(ll &it:f2) cin >> it;
    ll n,v1,v2,mx=-MAXN; cin >> n;
    for(int i=0; i<=n; ++i){
        v1 = f1[0]*((n-i)*(n-i))+f1[1]*(n-i)+f1[2];
        v2 = f2[0]*(i*i)+f2[1]*i+f2[2];
        if(mx < v1+v2) mx = v1+v2;
    }
    cout << mx;
}