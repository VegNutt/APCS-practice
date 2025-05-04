#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000009
#define MAXN 2000000000
using namespace std;

int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    int m, n; cin >> m >> n;
    vector<string> rainbow(n);
    for(auto &it : rainbow) cin >> it;

    unordered_map<string, int> colors;
    int beauty = 0;
    for(int i = 0; i < n; ++i){
        colors[rainbow[i]]++;
        if(i >= m){
            colors[rainbow[i - m]]--;
            if(colors[rainbow[i - m]] == 0){
                colors.erase(rainbow[i - m]);
            }
        }
        if(i >= m - 1 && colors.size() == m) beauty++;
    }
    cout << beauty;
}
