#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 1E9;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    std::vector<int> p(n, -1);
    for (int i = 1; i < n; i++) {
        std::cin >> p[i];
        p[i]--;
    }
    
    std::vector<std::vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        adj[p[i]].push_back(i);
    }
    
    int lo = 1, hi = n + 1;
    while (lo < hi) {
        int m = (lo + hi + 1) / 2;
        int ans = 0;
        ans += (m - 1) / 3 + 1;
        for (int k = 2; 2 * k <= m; k++) {
            ans += (m - k) / k;
        }
        if (ans <= n) {
            lo = m;
        } else {
            hi = m - 1;
        }
    }
    
    const int m = lo;
    std::vector dp(n, std::vector<int>(m + 1));
    
    auto get = [&](int x) {
        int ans = inf;
        for (int i = 1; i <= m; i++) {
            ans = std::min(ans, dp[x][i] + i);
        }
        return ans;
    };
    
    int ans = inf;
    auto dfs = [&](auto &&self, int x) -> void {
        if (adj[x].size() == 0) {
            if (a[x] <= m) {
                dp[x][a[x]] = inf;
            }
        } else if (adj[x].size() == 1) {
            int y = adj[x][0];
            self(self, y);
            if (a[x] <= m) {
                dp[y][a[x]] = inf;
            }
            int gy = get(y);
            for (int i = 1; i <= m; i++) {
                if (i == a[x]) {
                    dp[x][i] = inf;
                } else {
                    dp[x][i] = std::min(gy, dp[y][i]);
                }
            }
        } else {
            int y = adj[x][0], z = adj[x][1];
            self(self, y);
            self(self, z);
            if (a[x] <= m) {
                dp[y][a[x]] = inf;
                dp[z][a[x]] = inf;
            }
            int gy = get(y);
            int gz = get(z);
            int gyz = inf;
            for (int i = 1; i <= m; i++) {
                gyz = std::min(gyz, dp[y][i] + dp[z][i] + i);
            }
            for (int i = 1; i <= m; i++) {
                if (i == a[x]) {
                    dp[x][i] = inf;
                } else {
                    dp[x][i] = std::min({gy + gz, dp[y][i] + gz, gy + dp[z][i], gyz});
                    if (x == 0) {
                        ans = std::min(ans, gyz);
                    }
                }
            }
        }
    };
    dfs(dfs, 0);
    
    ans = std::min(ans, get(0));
    
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