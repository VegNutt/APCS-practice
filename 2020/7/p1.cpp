#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie();
    int a,b,n,ans=0,input; cin>>a>>b>>n;
    for(int i=0; i<n; ++i){
        int aCnt=0, bCnt=0;
        while(cin >> input){
            if(input == 0) break;
            if(input == a) aCnt++;
            else if(input == -a) aCnt--;
            else if(input == b) bCnt++;
            else if(input == -b) bCnt--;
        }
        if(aCnt && bCnt) ans++;
    }
    cout << ans;
}