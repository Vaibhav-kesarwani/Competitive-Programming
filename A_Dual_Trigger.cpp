#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        int cnt = 0, mi = n, mx = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                cnt++;
                mi = min(mi, i); mx = max(mx, i);
            }
        }
        cout << (cnt % 2 == 1 || (cnt == 2 && mx - mi == 1) ? "NO\n" : "YES\n");
    }
}