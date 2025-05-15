#define ll long long
#define F first
#define S second
#define pii pair<int,int>
#include <bits/stdc++.h>
using namespace std;

int n;
string L, S;
set<string> allowed;

void dfs(string sub){
    for(int i=0; i<L.length(); ++i){
        string newsub = sub + L[i];
        if(newsub.length() < n) dfs(newsub);
        else allowed.insert(newsub);
    }
}


int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> L >> n >> S;
    dfs("");
    for(int i=0; i<S.length()-n+1; ++i){
        string newstr = S.substr(i,n);
        allowed.erase(newstr);
    }
    cout << *allowed.begin();
}
