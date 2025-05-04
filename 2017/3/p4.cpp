#include <bits/stdc++.h>
using namespace std;

int n,k;
vector<int> s;

bool covered(const int &d){
    int cur=s[0]+d, cnt=1;
    for(int i=1; i<n; ++i){
        if(cur < s[i]) {
            cur=s[i]+d;
            cnt++;
        }
    }
    return (cnt<=k);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k; 
    s.resize(n);
    for(auto &it:s) cin >> it;
    sort(s.begin(),s.end());

    int left=1, right=s[n-1]-s[0]+1, mid, ans=0;
    while(left <= right){
        mid = (left+right)/2;   
        if(covered(mid)){
            ans=mid;
            right = mid-1;
        }
        else left = mid+1;
    }
    cout << ans;
}
// binary search (l<=r)