#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 1E9;
template<class Info>
struct SegmentTree {
    int n;
    std::vector<Info> info;
    SegmentTree() : n(0) {}
    SegmentTree(int n_, Info v_ = Info()) {
        init(n_, v_);
    }
    template<class T>
    SegmentTree(std::vector<T> init_) {
        init(init_);
    }
    void init(int n_, Info v_ = Info()) {
        init(std::vector(n_, v_));
    }
    template<class T>
    void init(std::vector<T> init_) {
        n = init_.size();
        info.assign(4 << std::__lg(n), Info());
        std::function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (r - l == 1) {
                info[p] = init_[l];
                return;
            }
            int m = (l + r) / 2;
            build(2 * p, l, m);
            build(2 * p + 1, m, r);
            pull(p);
        };
        build(1, 0, n);
    }
    void pull(int p) {
        info[p] = info[2 * p] + info[2 * p + 1];
    }
    void modify(int p, int l, int r, int x, const Info &v) {
        if (r - l == 1) {
            info[p] = v;
            return;
        }
        int m = (l + r) / 2;
        if (x < m) {
            modify(2 * p, l, m, x, v);
        } else {
            modify(2 * p + 1, m, r, x, v);
        }
        pull(p);
    }
    void modify(int p, const Info &v) {
        modify(1, 0, n, p, v);
    }
    Info rangeQuery(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x) {
            return Info();
        }
        if (l >= x && r <= y) {
            return info[p];
        }
        int m = (l + r) / 2;
        return rangeQuery(2 * p, l, m, x, y) + rangeQuery(2 * p + 1, m, r, x, y);
    }
    Info rangeQuery(int l, int r) {
        return rangeQuery(1, 0, n, l, r);
    }
    template<class F>
    int findFirst(int p, int l, int r, int x, int y, F &&pred) {
        if (l >= y || r <= x) {
            return -1;
        }
        if (l >= x && r <= y && !pred(info[p])) {
            return -1;
        }
        if (r - l == 1) {
            return l;
        }
        int m = (l + r) / 2;
        int res = findFirst(2 * p, l, m, x, y, pred);
        if (res == -1) {
            res = findFirst(2 * p + 1, m, r, x, y, pred);
        }
        return res;
    }
    template<class F>
    int findFirst(int l, int r, F &&pred) {
        return findFirst(1, 0, n, l, r, pred);
    }
    template<class F>
    int findLast(int p, int l, int r, int x, int y, F &&pred) {
        if (l >= y || r <= x) {
            return -1;
        }
        if (l >= x && r <= y && !pred(info[p])) {
            return -1;
        }
        if (r - l == 1) {
            return l;
        }
        int m = (l + r) / 2;
        int res = findLast(2 * p + 1, m, r, x, y, pred);
        if (res == -1) {
            res = findLast(2 * p, l, m, x, y, pred);
        }
        return res;
    }
    template<class F>
    int findLast(int l, int r, F &&pred) {
        return findLast(1, 0, n, l, r, pred);
    }
};

struct Info {
    int a[3][3];
    Info() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                a[i][j] = (i == j ? 0 : inf);
            }
        }
    }
};

Info operator+(const Info &a, const Info &b) {
    Info c;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            c.a[i][j] = inf;
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = i; j < 3; j++) {
            for (int k = j; k < 3; k++) {
                c.a[i][k] = std::min(c.a[i][k], a.a[i][j] + b.a[j][k]);
            }
        }
    }
    return c;
}

void solve() {
    int n, q;
    std::cin >> n >> q;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    std::vector<int> ans(q, inf);
    std::vector<int> l(q), r(q);
    for (int i = 0; i < q; i++) {
        std::cin >> l[i] >> r[i];
        l[i]--;
    }
    
    auto work = [&]() {
        std::vector<i64> pre(n + 1);
        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + a[i];
        }
        
        std::vector<int> ord;
        for (int i = 0; i < q; i++) {
            if (pre[r[i]] < pre[l[i]]) {
                continue;
            }
            ord.push_back(i);
        }
        std::sort(ord.begin(), ord.end(),
            [&](int i, int j) {
                return pre[l[i]] > pre[l[j]];
            });
        std::vector<int> p(n + 1);
        std::iota(p.begin(), p.end(), 0);
        std::sort(p.begin(), p.end(),
            [&](int i, int j) {
                return pre[i] > pre[j];
            });
        
        SegmentTree<Info> seg(n + 1);
        for (int j = 0; auto i : ord) {
            while (j <= n && pre[p[j]] >= pre[l[i]]) {
                Info c;
                c.a[1][1] = -2;
                c.a[0][1] = -p[j];
                c.a[1][2] = p[j];
                c.a[0][2] = 2;
                seg.modify(p[j], c);
                j++;
            }
            auto c = seg.rangeQuery(l[i] + 1, r[i]);
            ans[i] = std::min(ans[i], std::min({c.a[0][2] - 4, c.a[1][2] - 2 - l[i], c.a[0][1] - 2 + r[i], c.a[1][1] + r[i] - l[i] - 2}) + 2 * (r[i] - l[i]) - 1);
        }
    };
    
    work();
    std::reverse(a.begin(), a.end());
    for (int i = 0; i < q; i++) {
        std::tie(l[i], r[i]) = std::make_pair(n - r[i], n - l[i]);
    }
    work();
    
    for (int i = 0; i < q; i++) {
        if (ans[i] == inf) {
            ans[i] = -1;
        }
        std::cout << ans[i] << "\n";
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