#include <bits/stdc++.h>
#define pii pair<int,int>
#define ll long long
#define F first
#define S second
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n; cin >> n;
    vector<pii>v(n);
    for(pii &p:v) cin >> p.F >> p.S;
    sort(v.begin(),v.end(), [](const pii &a, const pii&b){
         return a.F*a.F + a.S*a.S > b.F*b.F + b.S*b.S;
         });
    cout << v[1].F << " " << v[1].S;
}
