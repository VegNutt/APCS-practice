#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b;
    bool c,cmp=0;
    cin>>a>>b>>c;
    a=(a!=0?1:0),b=(b!=0?1:0);
    if((a&&b)==c){
        cmp=1;
        cout<<"AND\n";
    }
    if((a||b)==c){
        cmp=1;
        cout<<"OR\n";
    }
    if((a^b)==c){
        cmp=1;
        cout<<"XOR\n";
    }
    if(cmp==0)cout<<"IMPOSSIBLE";
}   