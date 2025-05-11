#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int r, c;
    cin >> r >> c;
    vector<vector<int>> a(r, vector<int>(c));
    for(auto &row:a) for(int &it:row) cin >> it;

    int ans = 0;
    bool modify = true;
    while (modify) {
        modify = false;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (a[i][j] < 0) continue;

                int val = a[i][j];

                // down
                int k = i + 1;
                while (k < r && a[k][j] == -1) ++k;
                if (k < r && a[k][j] == val) {
                    ans += val;
                    a[i][j] = a[k][j] = -1;
                    modify = true;
                    continue;
                }

                // right
                int l = j + 1;
                while (l < c && a[i][l] == -1) ++l;
                if (l < c && a[i][l] == val) {
                    ans += val;
                    a[i][j] = a[i][l] = -1;
                    modify = true;
                }
            }
        }
    }

    cout << ans << '\n';
}
