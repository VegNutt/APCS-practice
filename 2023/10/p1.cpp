#include<bits/stdc++.h>
#define ll long long
#define F first
#define S second
using namespace std;

int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    int x,n; cin >> x >> n;
    int mx = -INT_MAX, mn = INT_MAX, lcnt=0, rcnt=0;
    for(int i=0; i<n; ++i){
        int food; cin >> food;
        if(food-x > 0){
            mx = max(food, mx);
            rcnt++;
        }
        else if(food-x <0){
            mn = min(food, mn);
            lcnt++;
        }
    }
    if(rcnt>=lcnt) cout << rcnt << " " << mx;
    else cout << lcnt << " " << mn;
}
