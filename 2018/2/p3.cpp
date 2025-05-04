#include <bits/stdc++.h>
using namespace std;
int n,k,en,rpre,lpre;
vector<int>pre;

void findCut(int l, int r, int &cur){
    if(l-r < 0){
        cur++;
        lpre=l;
        rpre=r;
        r -= (pre[en]-pre[cur-1]);
        l += pre[cur-1];
        return findCut(l, r, cur);
    } 
    else{
        if(l-r >= rpre-lpre) cur--;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k; en = n-1;
    int input, total=0;
    for(int i=0; i<n; ++i){
        cin >> input;
        total += input;
        pre.push_back(total);
    }
    int lSum=pre[0],rSum=0, cur, ans=0;
    while(k-- && en > 2){
        cur=1; rSum=0;
        for(int i=2; i<=en; ++i) rSum += (pre[en] - pre[i-1]);
        findCut(lSum,rSum, cur);
        lSum = pre[0];
        en = cur-1;
        ans += (pre[cur]-pre[cur-1]);
    }
    cout << ans;
}