#include <bits/stdc++.h>
#define ll long long
#define MOD 1e9+7
#define MAXN 2e9
using namespace std;

int main(){
    ios::sync_with_stdio(false), cin.tie(0);
	int n,l,order,place; cin >> n >> l;
	vector<int> cut(n);
	for(int i=0; i<n; ++i){
		cin >> place >> order;
		cut[order-1] = place;
	} 
	set<int> st;
	st.insert(0); st.insert(l);
	ll ans=0;
	for(int i=0; i<n; ++i){
		st.insert(cut[i]);
		auto it = st.lower_bound(cut[i]);
		ans += (*next(it))-(*prev(it));
	}
	cout << ans;
}