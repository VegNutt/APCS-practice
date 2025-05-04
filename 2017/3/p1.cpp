#include <bits/stdc++.h>
using namespace std;

int main(){
    string n;
    int ans=0; cin >> n;
    for(int i=0; i<n.length(); ++i){
        if(i%2) ans+=n[i]-'0';
        else ans-=n[i]-'0';
    }
    cout << abs(ans) << endl;
}

// warn***while(n/=10) will /10 first and then enter the loop