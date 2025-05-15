#define ll long long
#define F first
#define S second
#define pii pair<int,int>
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    int n, k; cin >> n >> k;
    vector<int> a(n), prefix_sum(n+1, 0), prefix_parity(n+1, 0);
    vector<vector<int>> suffix_sum(2*n + 1);

    for (int i=0; i<n; ++i) {
        cin >> a[i];
        prefix_sum[i+1] = prefix_sum[i] + a[i];
        prefix_parity[i+1] = prefix_parity[i] + (a[i] % 2 ? 1 : -1);
    }

    int suffix_total = 0, suffix_parity = 0;
    for (int i=n-1; i>=0; --i) {
        suffix_total += a[i];
        suffix_parity += (a[i] % 2 ? 1 : -1);
        suffix_sum[suffix_parity + n].push_back(suffix_total);
    }

    // Sort suffix sum groups
    for (int i=0; i<=2*n; ++i) {
        sort(suffix_sum[i].begin(), suffix_sum[i].end());
    }

    int ans = INT_MIN;
    for (int i=0; i<=n; ++i) {
        int sumL = prefix_sum[i];
        int parityL = prefix_parity[i];

        if (parityL ==0 && sumL <= k) ans = max(ans, sumL);

        // find suffix with -parityL
        int idx = -parityL + n;
        if (idx >= 0 && idx <= 2 * n) {
            int remain = k - sumL;
            auto it = upper_bound(suffix_sum[idx].begin(), suffix_sum[idx].end(), remain);
            if (it != suffix_sum[idx].begin()) {
                --it;
                ans = max(ans, sumL + *it);
            }
        }
    }

    cout << ans << '\n';
}
