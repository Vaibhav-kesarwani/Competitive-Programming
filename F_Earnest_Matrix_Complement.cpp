#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    
    i64 ans = 0;
    std::vector a(n, std::vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> a[i][j];
            if (a[i][j] > 0) {
                a[i][j]--;
            }
        }
    }
    
    {
        std::vector<int> cnt(k);
        for (int i = 1; i < n; i++) {
            for (auto x : a[i - 1]) {
                if (x >= 0) {
                    cnt[x]++;
                }
            }
            for (auto x : a[i]) {
                if (x >= 0) {
                    ans += cnt[x];
                }
            }
            for (auto x : a[i - 1]) {
                if (x >= 0) {
                    cnt[x]--;
                }
            }
        }
    }
    
    std::vector<int> e(n);
    for (int i = 0; i < n; i++) {
        e[i] = std::count(a[i].begin(), a[i].end(), -1);
    }
    
    std::vector<i64> dp(k);
    i64 mx = 0;
    i64 chm = 0;
    i64 add = 0;
    std::vector<int> cnt(k);
    
    for (int i = 1; i < n; i++) {
        for (auto x : a[i]) {
            if (x >= 0) {
                cnt[x]++;
            }
        }
        for (auto x : a[i]) {
            if (x >= 0 && cnt[x] > 0) {
                dp[x] = std::max(dp[x], chm) + 1LL * e[i - 1] * cnt[x];
                mx = std::max(mx, dp[x]);
                cnt[x] = 0;
            }
        }
        i64 E = 1LL * e[i - 1] * e[i];
        for (auto x : a[i - 1]) {
            if (x >= 0) {
                cnt[x]++;
            }
        }
        i64 nc = std::max(mx, chm) - E;
        i64 omx = mx;
        for (auto x : a[i - 1]) {
            if (x >= 0 && cnt[x] > 0) {
                dp[x] = std::max(std::max(dp[x], chm), std::max(omx, chm) - E) + 1LL * e[i] * cnt[x];
                mx = std::max(mx, dp[x]);
                cnt[x] = 0;
            }
        }
        chm = std::max(chm, nc);
        add += E;
    }
    ans += std::max(mx, chm) + add;
    
    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}
