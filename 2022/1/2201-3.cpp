#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int m; cin >> m;
    vector<string>stick(m);
    for(int i=0; i<m; ++i) cin >> stick[i];
    cout << endl;
    //start
    string bigs="";
    int midline=0, ans=0;
    bool same = false;
    for(int i=0; i<m; ++i) {
        for(int j=i+1; j<m; ++j) {
            bigs = stick[i]+stick[j];
            if(bigs.length()%2==1) continue;
            // cmp
            midline = bigs.length()/2;
            same = true;
            for(int k=0; k<midline; ++k) {
                if(bigs[k] == bigs[midline+k]) continue;
                same = false;
                break;
            }
            if(same) ans++;
        }
    }
    cout << ans;
}
