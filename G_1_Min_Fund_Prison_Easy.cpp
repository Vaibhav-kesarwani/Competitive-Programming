#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) int((a).size())

template<typename Fun>
struct y_combinator {
    const Fun fun;

    explicit y_combinator(const Fun&& fun) : fun(std::forward<const Fun>(fun)) {}

    template<typename... Args>
    auto operator()(Args&&... args) const {
        return fun(std::ref(*this), std::forward<Args>(args)...);
    }
};

void solve(int /* test_num */) {
    int n, m, c;
    cin >> n >> m >> c;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        g[v].push_back(u);
        g[u].push_back(v);
    }

    ll ans = 1e18;
    vector<int> sz(n, 1);

    y_combinator([&](auto dfs, int v) -> void {
        for (auto u : g[v]) {
            g[u].erase(find(all(g[u]), v));
            dfs(u);
            ans = min(ans, 1ll * sz[u] * sz[u] + 1ll * (n - sz[u]) * (n - sz[u]));
            sz[v] += sz[u];
        }
    })(0);

    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tests;
    cin >> tests;
    for (int test_num = 1; test_num <= tests; test_num++) {
        solve(test_num);
    }
}
