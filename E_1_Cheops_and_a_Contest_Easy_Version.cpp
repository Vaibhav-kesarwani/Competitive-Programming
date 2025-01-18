#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

constexpr int inf = 1E9;

void solve() {
    int n, m;
    std::cin >> n >> m;
    
    std::vector<int> a(n), b(n), s(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i] >> b[i] >> s[i];
    }
    
    auto ss = s;
    auto vs = a;
    vs.insert(vs.end(), b.begin(), b.end());
    std::sort(ss.begin(), ss.end());
    std::sort(vs.begin(), vs.end());
    
    vs.erase(std::unique(vs.begin(), vs.end()), vs.end());
    ss.erase(std::unique(ss.begin(), ss.end()), ss.end());
    
    for (int i = 0; i < n; i++) {
        a[i] = std::lower_bound(vs.begin(), vs.end(), a[i]) - vs.begin();
        b[i] = std::lower_bound(vs.begin(), vs.end(), b[i]) - vs.begin();
        s[i] = std::lower_bound(ss.begin(), ss.end(), s[i]) - ss.begin();
    }
    
    std::vector<std::vector<int>> q(m);
    for (int i = 0; i < m; i++) {
        int k;
        std::cin >> k;
        q[i].resize(k);
        for (int j = 0; j < k; j++) {
            std::cin >> q[i][j];
            q[i][j]--;
        }
    }
    
    const int nv = vs.size();
    const int ns = ss.size();
    
    int maxa = -1;
    
    std::vector<int> L(ns, -inf), R(ns, inf);
    
    std::vector<std::vector<std::array<int, 2>>> ban(ns + 1);
    auto addSeg = [&](int s, int l, int r) {
        ban[s].push_back({l, r});
    };
    
    for (int i = m - 1; i >= 0; i--) {
        for (auto j : q[i]) {
            if (maxa < a[j]) {
                continue;
            }
            R[s[j]] = std::min(R[s[j]], b[j]);
            L[s[j]] = std::max(L[s[j]], maxa + 1);
            if (a[j] < maxa) {
                addSeg(ns, a[j] + 1, maxa);
            }
        }
        for (auto j : q[i]) {
            maxa = std::max(maxa, a[j]);
        }
    }
    
    std::vector<std::vector<int>> vec(ns);
    for (int i = 0; i < n; i++) {
        vec[s[i]].push_back(i);
    }
    
    for (int i = 0; i < ns; i++) {
        if (L[i] > R[i]) {
            std::cout << -1 << "\n";
            return;
        }
    }
    
    int mina = inf;
    for (int i = 0; i < m; i++) {
        for (auto j : q[i]) {
            if (mina > a[j]) {
                continue;
            }
            if (b[j] > a[j]) {
                addSeg(s[j], a[j] + 1, b[j]);
            }
        }
        for (auto j : q[i]) {
            mina = std::min(mina, a[j]);
        }
    }
    
    std::vector<bool> can(nv);
    {
        std::vector<int> d(nv);
        for (auto [l, r] : ban[ns]) {
            d[l]++;
            if (r + 1 < nv) {
                d[r + 1]--;
            }
        }
        for (int i = 1; i < nv; i++) {
            d[i] += d[i - 1];
        }
        for (int i = 0; i < nv; i++) {
            can[i] = (d[i] == 0);
        }
    }
    
    std::vector<int> left(nv, -1);
    for (int i = 0; i < nv; i++) {
        if (i > 0) {
            left[i] = left[i - 1];
        }
        if (can[i]) {
            left[i] = i;
        }
    }
    
    std::vector<std::array<int, 2>> ans;
    for (int i = 0; i < ns; i++) {
        if (L[i] < 0) {
            continue;
        }
        int lst = -1;
        std::vector<std::array<int, 2>> e;
        for (auto [l, r] : ban[i]) {
            e.push_back({l - 1, -1});
            e.push_back({r, 1});
        }
        std::sort(e.begin(), e.end());
        int sum = 0;
        int val = -1;
        for (auto [x, t] : e) {
            if (sum == 0 && x >= 0) {
                int u = left[std::min(x, R[i])];
                if (u > lst && u >= L[i]) {
                    val = u;
                }
            }
            sum += t;
            lst = x;
        }
        if (int u = left[R[i]]; u > lst && u >= L[i]) {
            val = u;
        }
        if (val == -1) {
            std::cout << -1 << "\n";
            return;
        }
        ans.push_back({vs[val], ss[i]});
    }
    
    std::vector<int> score(n);
    std::sort(ans.begin(), ans.end());
    std::map<int, int> diff;
    for (auto [d, p] : ans) {
        diff[p] = d;
    }
    for (int i = 0; i < n; i++) {
        score[i] += std::lower_bound(ans.begin(), ans.end(), std::array {vs[a[i]] + 1, 0}) - ans.begin();
        if (diff.contains(ss[s[i]])) {
            int x = diff[ss[s[i]]];
            if (vs[a[i]] < x && x <= vs[b[i]]) {
                score[i]++;
            }
        }
    }
    
    int cur = 0;
    std::vector<std::set<int>> set(n + 1);
    for (int i = m - 1; i >= 0; i--) {
        for (auto j : q[i]) {
            int val = -1;
            for (int k = score[j]; k <= score[j] + 1 && k <= n; k++) {
                auto it = set[k].lower_bound(a[j]);
                if (it != set[k].begin()) {
                    val = std::max(val, *std::prev(it));
                }
            }
            if (val != -1) {
                int u = left[a[j]];
                if (u <= val) {
                    std::cout << -1 << "\n";
                    return;
                }
                for (int t = 0; t < 2; t++) {
                    while (std::binary_search(ss.begin(), ss.end(), cur)) {
                        cur++;
                    }
                    ans.push_back({vs[u], cur});
                    cur++;
                }
            }
        }
        for (auto j : q[i]) {
            set[score[j]].insert(a[j]);
        }
    }
    
    std::cout << ans.size() << "\n";
    for (auto [d, p] : ans) {
        std::cout << d << " " << p << "\n";
    }
    
    // {
    //     std::vector<int> score(n);
    //     for (int i = 0; i < n; i++) {
    //         for (auto [d, p] : ans) {
    //             if (vs[a[i]] >= d || (ss[s[i]] == p && vs[b[i]] >= d)) {
    //                 score[i]++;
    //             }
    //         }
    //     }
    //     for (int i = 0; i < m; i++) {
    //         for (int j = i + 1; j < m; j++) {
    //             for (auto x : q[i]) {
    //                 for (auto y : q[j]) {
    //                     assert(score[x] > score[y]);
    //                 }
    //             }
    //         }
    //     }
    //     assert(!ans.empty());
    //     for (int i = 0; i < ans.size(); i++) {
    //         for (int j = 0; j < i; j++) {
    //             assert(ans[i][1] != ans[j][1]);
    //         }
    //     }
    // }
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