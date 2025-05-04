#include <iostream>
using namespace std;

int main() {
    int n, d; cin >> n >>d;
    int last=0, cur=0, profit=0;
    cin >> last;
    bool have = true;
    for(int i=0; i<n-1; ++i) {
        cin >> cur;
        if(have) {
            if(cur>=last+d) {
                profit+=(cur-last);
                have = false;
                last = cur;
            }
        } else {
            if(cur<=last-d) {
                have = true;
                last = cur;
            }
        }
    }
    cout << profit;
}
