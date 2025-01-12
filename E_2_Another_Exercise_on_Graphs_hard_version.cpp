#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

constexpr int N = 400;
using B = std::bitset<N>;

void solve() {
    int n, m, q;
    std::cin >> n >> m >> q;
    
    std::vector<B> e0(n), e1(n);
    std::vector<std::array<int, 3>> edges(m);
    
    std::vector dis(n, std::vector<int>(n, n));
    for (int i = 0; i < m; i++) {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--;
        v--;
        e1[u].set(v);
        e1[v].set(u);
        edges[i] = {w, u, v};
        dis[u][v] = 1;
        dis[v][u] = 1;
    }
    std::sort(edges.begin(), edges.end());
    for (int i = 0; i < n; i++) {
        dis[i][i] = 0;
    }
    
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dis[i][j] = std::min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    
    std::vector dv(n, std::vector<B>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dv[i][dis[i][j]].set(j);
        }
    }
    
    std::vector ans(n, std::vector(n, std::vector<int>(n)));
    
    
    std::queue<int> Q;
    
    auto check = [&](int s, int v, int w) {
        dv[s][dis[s][v]].set(v, 0);
        dis[s][v]--;
        dv[s][dis[s][v]].set(v);
        ans[s][v][dis[s][v]] = w;
        Q.push(v);
    };
    for (auto [w, u, v] : edges) {
        e0[u].set(v);
        e0[v].set(u);
        e1[u].set(v, 0);
        e1[v].set(u, 0);
        for (int s = 0; s < n; s++) {
            if (dis[s][u] == dis[s][v]) {
                continue;
            }
            if (dis[s][u] > dis[s][v]) {
                std::swap(u, v);
            }
            check(s, v, w);
            
            while (!Q.empty()) {
                int v = Q.front();
                Q.pop();
                
                auto work = [&](const auto &b) {
                    for (int i = b._Find_first(); i < n; i = b._Find_next(i)) {
                        check(s, i, w);
                    }
                };
                if (dis[s][v] + 2 < n) {
                    auto b = dv[s][dis[s][v] + 2] & e1[v];
                    work(b);
                }
                if (dis[s][v] + 1 < n) {
                    auto b = dv[s][dis[s][v] + 1] & e0[v];
                    work(b);
                }
            }
        }
    }
    
    for (int i = 0; i < q; i++) {
        int a, b, k;
        std::cin >> a >> b >> k;
        a--;
        b--;
        k--;
        std::cout << ans[a][b][k] << " \n"[i == q - 1];
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