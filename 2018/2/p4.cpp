#include <bits/stdc++.h>
#define mod 1000000009
using namespace std;

int main(){
    cin.sync_with_stdio(false), cin.tie(0);
    string str;
    vector<vector<int> >dp(100001, vector<int>(10));
    for(int i=1 ; i<10; ++i)    dp[1][i]=1;
    for(int i=1; i<=100000; ++i) dp[i][9]=1;
    for(int i=1; i<=100000; ++i){
        for(int j=8; j>=1; --j){
            dp[i][j] = (dp[i-1][j]+dp[i][j+1])%mod;
        }
    }
    while(cin >> str){
        int ans=0, isladder=1;
        for (int i=1; i<=str.length()-1; ++i)
			if (str[i] < str[i-1]) {
				isladder = 0;
				break;
		}
        ans += isladder;
        for(int i=1; i<=str.length()-1; ++i){
            for(int j=1; j<=9; ++j){
                ans += dp[i][j];
                ans %= mod;
            }
        }
        for (int j=1; j<=str[0]-'0'-1; ++j) {
			ans += dp[str.length()][j];     
			ans %= mod;
		}
        for (int i=1; i<=str.length()-1; ++i) {
            if(str[i]>str[i-1]){
                for(int j=str[i-1]-'0'; j<str[i]-'0'; ++j){
                    ans += dp[i][j];
			        ans %= mod;
                }
            }
			else break;
		}
        cout << ans << endl;
    }
}