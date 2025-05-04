#include <bits/stdc++.h>
using namespace std;
string s;
int n, node = 0;
int recur(int& node, int layer){
    if(node < s.length()){
        if(s[node]=='0') return 0;
        else if(s[node]=='1'){
            int cnt = n;
            cnt /= (1 << layer);
            return cnt*cnt;
        }
        else{
            int sum=0;
            for(int i=1; i<=4; ++i){
                sum += recur(++node, layer+1);
            }
            return sum;
        }
    }
}

int main(){  
    cin >> s >> n;
    cout << recur(node,0);;
}