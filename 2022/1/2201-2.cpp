#include <iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define a s[all[i]]
#define b t[all[i]]
#define c s[all[i+1]]
#define d t[all[i+1]]

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m, tmp, s[1000], t[1000]; cin >> n >> m;
    vector<int>lost(n, 0), all, winner, loser;
    for(int i=0; i<n; ++i) cin >>s[i];
    for(int i=0; i<n; ++i) cin >>t[i];
    for(int i=0; i<n; ++i) {
        cin >> tmp;
        all.push_back(tmp);
    }
    while(all.size()>1) {
        cout << "all.size:" << all.size() << " ";
        for(int i=0; i<all.size()-1; i+=2){
            //1>2
            if(a*b >= c*d){
                s[all[i]] += c*d / (2*b);
                t[all[i]] += c*d / (2*a);
                s[all[i+1]] += c/2;
                t[all[i+1]] += d/2;
                winner.push_back(all[i]);
                lost[all[i+1]]++;
                if(lost[all[i+1]] < m) loser.push_back(all[i+1]););
            }
            // 2>1
            else {
                s[all[i+1]] += a*b / (2*d);
                t[all[i+1]] += a*b / (2*c);
                s[all[i]] += a/2;
                t[all[i]] += b/2;
                winner.push_back(all[i+1]);
                lost[all[i]]++;
                if(lost[all[i]] < m) loser.push_back(all[i]);
            }
        }
        if(all.size()%2==1) winner.push_back(n-1);
        // restart
        cout << endl << "winner: ";
        for(int &it:winner) cout << it << " ";
        all = winner;
        cout << " all: ";
        for(int &it:loser) all.push_back(it);
        winner.clear(); loser.clear();
        for(int &it:all) cout << it << " ";
    }
    cout << all[0];
}

