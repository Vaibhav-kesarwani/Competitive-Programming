#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
template <typename T>
struct Fenwick {
    int n;
    std::vector<T> a;
    
    Fenwick(int n_ = 0) {
        init(n_);
    }
    
    void init(int n_) {
        n = n_;
        a.assign(n, T{});
    }
    
    void add(int x, const T &v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] = a[i - 1] + v;
        }
    }
    
    T sum(int x) {
        T ans{};
        for (int i = x; i > 0; i -= i & -i) {
            ans = ans + a[i - 1];
        }
        return ans;
    }
    
    T rangeSum(int l, int r) {
        return sum(r) - sum(l);
    }
    
    int select(const T &k) {
        int x = 0;
        T cur{};
        for (int i = 1 << std::__lg(n); i; i /= 2) {
            if (x + i <= n && cur + a[x + i - 1] <= k) {
                x += i;
                cur = cur + a[x - 1];
            }
        }
        return x;
    }
};

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        a[i]--;
    }
    
    i64 ans = 0;
    for (int x = 0; x < 10; x++) {
        std::vector<int> f(n + 1), g(n + 1);
        for (int i = 0; i < n; i++) {
            f[i + 1] = f[i] + (a[i] >= x ? 1 : -1);
            g[i + 1] = g[i] + (a[i] <= x ? 1 : -1);
        }
        std::vector<int> p(n + 1);
        std::iota(p.begin(), p.end(), 0);
        std::sort(p.begin(), p.end(),
            [&](int i, int j) {
                if (f[i] != f[j]) {
                    return f[i] < f[j];
                }
                return g[i] > g[j];
            });
        Fenwick<int> fen(2 * n + 1);
        for (auto i : p) {
            ans += fen.sum(n + g[i]);
            fen.add(n + g[i], 1);
        }
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