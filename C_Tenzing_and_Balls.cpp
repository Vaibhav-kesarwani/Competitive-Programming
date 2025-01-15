#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        const int N = 200000 + 5;
        int n, a[N], dp[N], buc[N];
        cin >> n;
        dp[0] = 0;
        for (int i = 1; i <= n; i++) buc[i] = 0x3f3f3f3f;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            dp[i] = min(dp[i - 1] + 1, buc[a[i]]);
            buc[a[i]] = min(buc[a[i]], dp[i - 1]);
        }
        cout << n - dp[n] << '\n';
    }
}