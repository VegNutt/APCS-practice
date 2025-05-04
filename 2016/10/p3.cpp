#include <bits/stdc++.h>
using namespace std;

int n,m,k,cur=1;
vector<int> died;

void next(const int &x){
    for(int i=0; i<x;){
        cur = (cur+1)%n;
        if(died[cur] == 0) ++i;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k; m--;
    died.resize(n+1,0);

    while(k--){
        next(m);
        died[cur] = 1;
        next(1);
    }
    cout << cur;
}
