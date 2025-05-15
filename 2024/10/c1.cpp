#include<bits/stdc++.h>
#define ll long long
#define F first
#define S second
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int n, w1, w2, h1, h2; cin >> n >> w1 >> w2 >> h1 >> h2;
    vector<int> preV(n+1,0);
    for(int i=1; i<=n; ++i){
        cin >> preV[i];
        preV[i] += preV[i-1];
    }
    int curV=0, curN=1, ans=0;
    for(int curh=1, h=1; curh<=h1+h2; curh++, h++){
        curV += (curV < w1*w1*h1) ? w1*w1 : w2*w2;
        ans = max(ans, h);
        if(curV >= preV[curN]){
            h=0;
            curN+=1;
            if(curN > n) break;
        }
    }
    cout << ans;
    return 0;
}
