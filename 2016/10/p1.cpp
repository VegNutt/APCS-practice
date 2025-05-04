#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int>v(3);
    cin >> v[0] >> v[1] >> v[2];
    sort(v.begin(), v.end());
    for(auto &it:v) cout << it << " ";
    if(v[0]+v[1] <= v[2]) cout << "\nNo";
    else if(v[0]*v[0] + v[1]*v[1] > v[2]*v[2]) cout << "\nAcute";
    else if(v[0]*v[0] + v[1]*v[1] < v[2]*v[2]) cout << "\nObtuse";
    else cout << "\nRight";
}