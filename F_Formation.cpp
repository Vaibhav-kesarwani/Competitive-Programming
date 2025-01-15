#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

void solve() {
    int n, q;
    std::cin >> n >> q;
    
    std::vector<i64> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        a[i]--;
    }
    
    i64 mxa = *std::max_element(a.begin(), a.end());
    
    std::vector<i64> k(q);
    std::vector<i64> ans(q, mxa);
    for (int i = 0; i < q; i++) {
        std::cin >> k[i];
    }
    
    std::vector<i64> sum(n);
    for (int d = 0; d <= 30 && d < n; d++) {
        std::vector<std::array<i64, 3>> e;
        for (int i = d; i < n; i++) {
            i64 l = (a[i - d] + 1) << d;
            i64 r = 1LL << 31;
            if (i > d) {
                r = std::min(r, (a[i - d - 1] + 1) << (d + 1));
            }
            sum[i] += a[i - d];
            if (l < r) {
                e.push_back({l, 1, sum[i]});
                e.push_back({r, -1, sum[i]});
            }
        }
        std::sort(e.begin(), e.end());
        std::priority_queue<i64> q1, q2;
        q1.push(0);
        i64 lst = 0;
        std::vector<i64> p {0}, g;
        for (auto [x, t, v] : e) {
            if (lst < x) {
                while (!q2.empty() && q1.top() == q2.top()) {
                    q1.pop();
                    q2.pop();
                }
                g.push_back(q1.top());
                p.push_back(x);
            }
            if (t == 1) {
                q1.push(v);
            } else {
                q2.push(v);
            }
            lst = x;
        }
        
        auto get = [&](i64 x) {
            i64 ans = 2 * x - __builtin_popcountll(x);
            x >>= (d + 1);
            ans -= 2 * x - __builtin_popcountll(x);
            return ans;
        };
        
        int m = g.size();
        if (m == 0) {
            continue;
        }
        // for (int i = 0; i <= m; i++) {
        //     std::cerr << p[i] << " \n"[i == m];
        // }
        // for (int i = 0; i < m; i++) {
        //     std::cerr << g[i] << " \n"[i == m - 1];
        // }
        std::vector<i64> suf(m + 1);
        suf[m] = 1LL << 31;
        for (int i = m - 1; i >= 0; i--) {
            suf[i] = std::min(suf[i + 1], get(p[i]) - g[i]);
        }
        assert(suf[0] == 0);
        
        for (int i = 0; i < q; i++) {
            auto it = std::lower_bound(suf.begin(), suf.end(), k[i] + 1);
            int u = it - suf.begin() - 1;
            i64 lo = p[u], hi = p[u + 1] - 1;
            
            while (lo < hi) {
                i64 x = (lo + hi + 1) / 2;
                if (get(x) - g[u] <= k[i]) {
                    lo = x;
                } else {
                    hi = x - 1;
                }
            }
            ans[i] = std::max(ans[i], lo);
        }
    }
    
    for (int i = 0; i < q; i++) {
        std::cout << ans[i] + 1 << " \n"[i == q - 1];
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