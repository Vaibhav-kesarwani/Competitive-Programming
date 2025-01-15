#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<std::vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    std::vector<int> d(n, 2);
    for (int i = 0; i < n; i++) {
        if (adj[i].size() == 1) {
            d[i] = 0;
            int x = adj[i][0];
            d[x] = std::min(d[x], 1);
        }
    }
    
    int tot1 = std::count(d.begin(), d.end(), 1);
    int tot2 = std::count(d.begin(), d.end(), 2);
    std::vector<int> siz2(n), p(n, -1), siz1(n);
    
    i64 ans = 0;
    auto dfs = [&](this auto &&self, int x) -> void {
        siz2[x] = (d[x] == 2);
        siz1[x] = (d[x] == 1);
        for (auto y : adj[x]) {
            if (y == p[x]) {
                continue;
            }
            p[y] = x;
            self(y);
            siz2[x] += siz2[y];
            siz1[x] += siz1[y];
            
            if (d[x] == 0) {
                ans += siz1[y] + siz2[y];
            } else if (d[y] == 1) {
                ans += siz2[y];
            }
            if (d[y] == 0) {
                ans += tot1 - siz1[y] + tot2 - siz2[y];
            } else if (d[x] == 1) {
                ans += tot2 - siz2[y];
            }
        }
    };
    dfs(0);
    
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
