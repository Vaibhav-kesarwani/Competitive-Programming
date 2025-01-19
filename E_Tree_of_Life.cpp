#include <bits/stdc++.h>

using i64 = long long;

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
    
    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        i64 d = adj[i].size();
        ans += d * (d - 1) / 2;
    }
    std::vector<i64> f(n), g(n);
    auto dfs = [&](this auto &&self, int x, int p) -> void {
        i64 d = adj[x].size();
        
        i64 max = 0;
        for (auto y : adj[x]) {
            if (y == p) {
                continue;
            }
            self(y, x);
            
            i64 t = std::min(d - 1, f[y]);
            f[y] -= t;
            ans -= t;
            
            t = d - 1 - t;
            i64 v = std::min(t, 2 * g[y]);
            ans -= v;
            
            g[y] -= v / 2;
            if (v % 2 == 1) {
                g[y]--;
                f[y]++;
            }
            
            g[x] += g[y];
            f[x] += f[y];
            max = std::max(max, f[y]);
        }
        
        if (max * 2 > f[x]) {
            i64 v = g[x];
            for (auto y : adj[x]) {
                if (y == p) {
                    continue;
                }
                if (f[y] == max) {
                    v -= g[y];
                    break;
                }
            }
            g[x] += f[x] - max;
            f[x] = max * 2 - f[x];
            v = std::min(v, f[x] / 2);
            f[x] -= 2 * v;
            g[x] += v;
        } else {
            g[x] += f[x] / 2;
            f[x] %= 2;
        }
        
        f[x] += d - 1;
    };
    dfs(0, -1);
    
    ans -= g[0];
    
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