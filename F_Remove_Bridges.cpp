#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<std::vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    std::vector<int> a;
    auto dfs = [&](auto &&self, int x, int p) -> int {
        int h = 0;
        for (auto y : adj[x]) {
            if (y == p) {
                continue;
            }
            int v = self(self, y, x) + 1;
            if (v > h) {
                std::swap(v, h);
            }
            if (v > 0) {
                a.push_back(v);
            }
        }
        return h;
    };
    a.push_back(dfs(dfs, 0, -1));
    
    std::sort(a.begin(), a.end(), std::greater());
    
    int ans = n - 1;
    for (int i = 1, j = 0; i < n; i++) {
        while (j < 2 * i - 1 && j < a.size()) {
            ans -= a[j];
            j++;
        }
        std::cout << ans << " \n"[i == n - 1];
    }
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