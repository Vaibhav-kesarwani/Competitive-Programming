#include <bits/stdc++.h>

using i64 = long long;
struct DSU {
    std::vector<int> f, siz;
    
    DSU() {}
    DSU(int n) {
        init(n);
    }
    
    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }
    
    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }
    
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    
    int size(int x) {
        return siz[find(x)];
    }
};
void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    
    std::vector<std::array<int, 3>> seg;
    seg.reserve(2 * n);
    for (int i = 0; i < n; i++) {
        int l, r;
        std::cin >> l >> r >> a[i];
        seg.push_back({l, 0, i});
        seg.push_back({r, 1, i});
    }
    
    std::set<std::pair<int, int>> s;
    std::vector<std::array<int, 3>> edges;
    edges.reserve(2 * n);
    
    std::sort(seg.begin(), seg.end());
    for (auto [_, t, i] : seg) {
        if (t == 0) {
            auto it = s.emplace(a[i], i).first;
            if (it != s.begin()) {
                auto l = std::prev(it);
                edges.push_back({a[i] - l->first, l->second, i});
            }
            auto r = std::next(it);
            if (r != s.end()) {
                edges.push_back({r->first - a[i], i, r->second});
            }
        } else {
            auto it = s.erase(s.find({a[i], i}));
            if (it != s.end() && it != s.begin()) {
                auto l = std::prev(it);
                edges.push_back({it->first - l->first, l->second, it->second});
            }
        }
    }
    std::sort(edges.begin(), edges.end());
    DSU dsu(n);
    int cnt = n;
    i64 ans = 0;
    for (auto [w, u, v] : edges) {
        if (dsu.merge(u, v)) {
            ans += w;
            cnt--;
        }
    }
    if (cnt != 1) {
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