#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;

int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    int n; cin >> n;
    int curX=0, curY=0, dir=0; //1:up 2:down 3:left 4:right
    vector<int>ans(3,0); // l,r,re
    for(int i=0; i<n; ++i){
        int a,b; cin >> a >> b;
        if(dir == 1){
            if(a-curX > 0) ans[1]++, dir = 4;
            else if(a-curX < 0) ans[0]++, dir = 3;
            else if(b-curY < 0) ans[2]++, dir = 2;
        }
        if(dir == 2){
            if(a-curX > 0) ans[0]++, dir = 4;
            else if(a-curX < 0) ans[1]++, dir = 3;
            else if(b-curY > 0) ans[2]++, dir = 1;
        }
        if(dir == 3){
            if(a-curX > 0) ans[2]++, dir = 4;
            else if(b-curY > 0) ans[1]++, dir = 1;
            else if(b-curY < 0) ans[0]++, dir = 2;
        }
        if(dir == 4){
            if(a-curX < 0) ans[2]++, dir = 3;
            else if(b-curY > 0) ans[0]++, dir = 1;
            else if(b-curY < 0) ans[1]++, dir = 2;
        }
        if(i==0){
            if(b-curY > 0) dir = 1;
            else if(b-curY < 0) dir = 2;
            else if(a-curX < 0) dir = 3;
            else dir = 4;
        }
        curX = a, curY = b;
    }
    cout << ans[0] << " " << ans[1] << " " << ans[2];
}
