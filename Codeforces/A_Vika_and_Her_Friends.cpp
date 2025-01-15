#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        int x, y;
        cin >> x >> y;
        string ans = "YES\n";
        for (int i = 0; i < k; ++i) {
            int xx, yy;
            cin >> xx >> yy;
            if ((x + y) % 2 == (xx + yy) % 2) {
                ans = "NO\n";
            }
        }
        cout << ans;
    }
    return 0;
}