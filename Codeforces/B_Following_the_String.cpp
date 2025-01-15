#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int t;
    cin >> t;

    auto solve = [&]() {
        int n;
        cin >> n;

        vector<int> cnt(26);

        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;

            int c = find(cnt.begin(), cnt.end(), a) - cnt.begin();
            cout << char('a' + c);
            cnt[c]++;
        }

        cout << '\n';
    };

    while (t--) {
        solve();
    }
    
    return 0;
}
