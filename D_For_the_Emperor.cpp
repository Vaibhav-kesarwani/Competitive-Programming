#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

template<class T>
struct MinCostFlow {
    struct _Edge {
        int to;
        T cap;
        T cost;
        _Edge(int to_, T cap_, T cost_) : to(to_), cap(cap_), cost(cost_) {}
    };
    int n;
    std::vector<_Edge> e;
    std::vector<std::vector<int>> g;
    std::vector<T> h, dis;
    std::vector<int> pre;
    bool dijkstra(int s, int t) {
        dis.assign(n, std::numeric_limits<T>::max());
        pre.assign(n, -1);
        std::priority_queue<std::pair<T, int>, std::vector<std::pair<T, int>>, std::greater<std::pair<T, int>>> que;
        dis[s] = 0;
        que.emplace(0, s);
        while (!que.empty()) {
            T d = que.top().first;
            int u = que.top().second;
            que.pop();
            if (dis[u] != d) {
                continue;
            }
            for (int i : g[u]) {
                int v = e[i].to;
                T cap = e[i].cap;
                T cost = e[i].cost;
                if (cap > 0 && dis[v] > d + h[u] - h[v] + cost) {
                    dis[v] = d + h[u] - h[v] + cost;
                    pre[v] = i;
                    que.emplace(dis[v], v);
                }
            }
        }
        return dis[t] != std::numeric_limits<T>::max();
    }
    MinCostFlow() {}
    MinCostFlow(int n_) {
        init(n_);
    }
    void init(int n_) {
        n = n_;
        e.clear();
        g.assign(n, {});
    }
    void addEdge(int u, int v, T cap, T cost) {
        g[u].push_back(e.size());
        e.emplace_back(v, cap, cost);
        g[v].push_back(e.size());
        e.emplace_back(u, 0, -cost);
    }
    std::pair<T, T> flow(int s, int t) {
        T flow = 0;
        T cost = 0;
        h.assign(n, 0);
        while (dijkstra(s, t)) {
            for (int i = 0; i < n; ++i) {
                h[i] += dis[i];
            }
            T aug = std::numeric_limits<int>::max();
            for (int i = t; i != s; i = e[pre[i] ^ 1].to) {
                aug = std::min(aug, e[pre[i]].cap);
            }
            for (int i = t; i != s; i = e[pre[i] ^ 1].to) {
                e[pre[i]].cap -= aug;
                e[pre[i] ^ 1].cap += aug;
            }
            flow += aug;
            cost += aug * h[t];
        }
        return std::make_pair(flow, cost);
    }
    struct Edge {
        int from;
        int to;
        T cap;
        T cost;
        T flow;
    };
    std::vector<Edge> edges() {
        std::vector<Edge> a;
        for (int i = 0; i < e.size(); i += 2) {
            Edge x;
            x.from = e[i + 1].to;
            x.to = e[i].to;
            x.cap = e[i].cap + e[i + 1].cap;
            x.cost = e[i].cost;
            x.flow = e[i + 1].cap;
            a.push_back(x);
        }
        return a;
    }
};

constexpr int N = 200;
constexpr int inf = 1E5;

void solve() {
    int n, m;
    std::cin >> n >> m;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    std::vector g(n, std::bitset<N> {});
    for (int i = 0; i < n; i++) {
        g[i].set(i);
    }
    
    std::vector<std::array<int, 2>> edges(m);
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;
        g[u].set(v);
        edges[i] = {u, v};
    }
    
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            if (g[i][k]) {
                g[i] |= g[k];
            }
        }
    }
    
    std::vector<int> bel(n, -1);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (g[i] == g[j]) {
                bel[i] = bel[j];
                break;
            }
        }
        if (bel[i] == -1) {
            bel[i] = cnt++;
        }
    }
    
    std::vector<int> sum(cnt);
    for (int i = 0; i < n; i++) {
        sum[bel[i]] += a[i];
    }
    
    for (auto &[u, v] : edges) {
        u = bel[u];
        v = bel[v];
    }
    n = cnt;
    
    MinCostFlow<int> G(n * 3 + 4);
    int S = n * 3, T = S + 1;
    int S0 = T + 1, T0 = S0 + 1;
    
    int ans = 0;
    std::vector<int> cost(n);
    for (int i = 0; i < n; i++) {
        cost[i] = sum[i] > 0 ? 1 : inf;
    }
    
    int must = 0;
    for (int i = 0; i < n; i++) {
        G.addEdge(S0, 3 * i + 1, 1, 0);
        G.addEdge(3 * i, T0, 1, 0);
        G.addEdge(3 * i + 1, 3 * i, 1, cost[i]);
        must++;
        
        G.addEdge(3 * i, 3 * i + 1, inf, 0);
        G.addEdge(3 * i + 1, 3 * i + 2, inf, 0);
        
        G.addEdge(S0, 3 * i + 2, 1, 0);
        G.addEdge(3 * i + 1, T0, 1, 0);
        must++;
        
        G.addEdge(S, 3 * i + 1, sum[i], 0);
        
        G.addEdge(3 * i + 2, T, inf, 0);
    }
    G.addEdge(T, S, inf, 0);
    for (auto [u, v] : edges) {
        if (u != v) {
            G.addEdge(3 * u + 2, 3 * v, inf, 0);
        }
    }
    {
        auto [flow, cost] = G.flow(S0, T0);
        if (flow != must) {
            std::cout << -1 << "\n";
            return;
        }
        ans += cost;
    }
    
    if (ans > n) {
        ans = -1;
    }
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