#include <bits/stdc++.h>
#define ll long long
#define MOD 1e9+7
#define MAXN 2e9
using namespace std;

int main(){
    int n,d,a,b,c, mx, mn, ans=0, cnt=0; cin >> n >> d;
    for(int i=0; i<n; ++i){
        cin >> a >> b >> c;
        mx = max(a, max(b,c));
        mn = min(a, min(b,c));
        if(mx-mn >= d){
            ans++;
            cnt += (a+b+c)/3;
        }
    }
    cout << ans << " " << cnt;
}