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
    
    std::vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
        std::cin >> x[i] >> y[i];
    }
    
    auto xs = x, ys = y;
    std::sort(xs.begin(), xs.end());
    std::sort(ys.begin(), ys.end());
    xs.erase(std::unique(xs.begin(), xs.end()), xs.end());
    ys.erase(std::unique(ys.begin(), ys.end()), ys.end());
    
    for (int i = 0; i < n; i++) {
        x[i] = std::lower_bound(xs.begin(), xs.end(), x[i]) - xs.begin();
        y[i] = std::lower_bound(ys.begin(), ys.end(), y[i]) - ys.begin();
    }
    
    int k = 0;
    int X0 = 0, Y0 = 0;
    
    Fenwick<int> fl(n), fr(n);
    for (int i = 0; i < n; i++) {
        fr.add(y[i], 1);
    }
    
    std::vector<int> p(n);
    std::iota(p.begin(), p.end(), 0);
    std::sort(p.begin(), p.end(),
        [&](int i, int j) {
            return x[i] < x[j];
        });
    
    for (int j = 0; j < n; j++) {
        int i = p[j];
        fr.add(y[i], -1);
        fl.add(y[i], 1);
        
        if (j + 1 < n && x[p[j + 1]] == x[i]) {
            continue;
        }
        
        while (true) {
            if (j + 1 < 2 * (k + 1)) {
                break;
            }
            if (n - j - 1 < 2 * (k + 1)) {
                break;
            }
            int yl = std::max(fl.select(k), fr.select(k));
            int yr = std::min(fl.select(j - k), fr.select(n - 1 - j - 1 - k));
            if (yl >= yr) {
                break;
            }
            k++;
            X0 = xs[x[i]] + 1;
            Y0 = ys[yr];
        }
    }
    
    std::cout << k << "\n";
    std::cout << X0 << " " << Y0 << "\n";
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