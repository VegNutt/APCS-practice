#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define MAXN 30000
using namespace std;

vector<pair<int,int> > vx[MAXN+1];
vector<pair<int,int> > vy[MAXN*2+1];

int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    int n,a,b,t; cin >> n;
    while(n--){
        cin >> a >> b >> t;
        b += MAXN;
        vx[a].push_back({b,t});
        vy[b].push_back({a,t});
    }
    for (int i=1; i<=MAXN; i++) sort(vx[i].begin(), vx[i].end());
    for (int i=0; i<=MAXN*2; i++) sort(vy[i].begin(), vy[i].end());
    int x=0, y=MAXN, d=0,cnt=0;
    while(true){
        if(d==0){
            auto it = upper_bound(vy[y].begin(), vy[y].end(), make_pair(x, 1));
            if(it == vy[y].end()) break;
            x = (*it).first;
            if((*it).second == 0) d=1;
            else d=3;
        }
        else if(d==1){
            auto it = upper_bound(vx[x].begin(), vx[x].end(), make_pair(y, 1));
            if(it == vx[x].end()) break;
            y = (*it).first;
            if((*it).second == 0) d=0;
            else d=2;
        }
        else if(d==2){
            auto it = lower_bound(vy[y].begin(), vy[y].end(), make_pair(x, 0));
            if(it == vy[y].begin()) break;
            it--;
            x = (*it).first;
            if((*it).second == 0) d=3;
            else d=1;   
        }
        else if(d==3){
            auto it = lower_bound(vx[x].begin(), vx[x].end(), make_pair(y, 0));
            if(it == vx[x].begin()) break;  
            it--;
            y = (*it).first;
            if((*it).second == 0) d=2;
            else d=0;
        }
        cnt++;
    }
    cout << cnt;
}