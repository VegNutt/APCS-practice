#define pii pair<int, int>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int k, minT = INT_MAX, maxS = -INT_MAX, m; cin >> k;
    int ans = -k;
    while(k--){
        int t,s; cin >> t >> s;
        if(s>maxS){
            maxS = s;
            minT = t;
        }
        if(s<0)ans-=2;
    }
    ans = (ans+maxS>=0)?ans+maxS:0;
    cout << ans << " " << minT;
}
