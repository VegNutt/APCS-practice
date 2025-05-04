#include <bits/stdc++.h>
using namespace std;

int main(){
    int cmp=0, input;
    for(int i=0; i<2; ++i){
        int a=0,b=0;
        for(int j=0; j<4; ++j){
            cin >> input;
            a += input;
        }
        for(int j=0; j<4; ++j){
            cin >> input;
            b += input;
        }
        cout << a << ":" << b << endl;
        if(a>b) cmp++;
    }
    if(cmp==2) cout << "Win";
    else if(cmp==1) cout << "Tie";
    else cout << "Lose";
}