#ifndef LOCAL
#define FAST_IO
#endif

// ============
#include <bits/stdc++.h>
#define OVERRIDE(a, b, c, d, ...) d
#define REP2(i, n) for (i32 i = 0; i < (i32)(n); ++i)
#define REP3(i, m, n) for (i32 i = (i32)(m); i < (i32)(n); ++i)
#define REP(...) OVERRIDE(__VA_ARGS__, REP3, REP2)(__VA_ARGS__)
#define PER2(i, n) for (i32 i = (i32)(n)-1; i >= 0; --i)
#define PER3(i, m, n) for (i32 i = (i32)(n)-1; i >= (i32)(m); --i)
#define PER(...) OVERRIDE(__VA_ARGS__, PER3, PER2)(__VA_ARGS__)
#define ALL(x) begin(x), end(x)
#define LEN(x) (i32)(x.size())
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using i32 = signed int;
using i64 = signed long long;
using f64 = double;
using f80 = long double;
using pi = pair<i32, i32>;
using pl = pair<i64, i64>;
template <typename T>
using V = vector<T>;
template <typename T>
using VV = V<V<T>>;
template <typename T>
using VVV = V<V<V<T>>>;
template <typename T>
using VVVV = V<V<V<V<T>>>>;
template <typename T>
using PQR = priority_queue<T, V<T>, greater<T>>;
template <typename T>
bool chmin(T &x, const T &y) {
    if (x > y) {
        x = y;
        return true;
    }
    return false;
}
template <typename T>
bool chmax(T &x, const T &y) {
    if (x < y) {
        x = y;
        return true;
    }
    return false;
}
template <typename T>
i32 lob(const V<T> &arr, const T &v) {
    return (i32)(lower_bound(ALL(arr), v) - arr.begin());
}
template <typename T>
i32 upb(const V<T> &arr, const T &v) {
    return (i32)(upper_bound(ALL(arr), v) - arr.begin());
}
template <typename T>
V<i32> argsort(const V<T> &arr) {
    V<i32> ret(arr.size());
    iota(ALL(ret), 0);
    sort(ALL(ret), [&](i32 i, i32 j) -> bool {
        if (arr[i] == arr[j]) {
            return i < j;
        } else {
            return arr[i] < arr[j];
        }
    });
    return ret;
}
#ifdef INT128
using u128 = __uint128_t;
using i128 = __int128_t;
#endif
[[maybe_unused]] constexpr i32 INF = 1000000100;
[[maybe_unused]] constexpr i64 INF64 = 3000000000000000100;
struct SetUpIO {
    SetUpIO() {
#ifdef FAST_IO
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
#endif
        cout << fixed << setprecision(15);
    }
} set_up_io;
void scan(char &x) { cin >> x; }
void scan(u32 &x) { cin >> x; }
void scan(u64 &x) { cin >> x; }
void scan(i32 &x) { cin >> x; }
void scan(i64 &x) { cin >> x; }
void scan(string &x) { cin >> x; }
template <typename T>
void scan(V<T> &x) {
    for (T &ele : x) {
        scan(ele);
    }
}
void read() {}
template <typename Head, typename... Tail>
void read(Head &head, Tail &...tail) {
    scan(head);
    read(tail...);
}
#define CHAR(...)     \
    char __VA_ARGS__; \
    read(__VA_ARGS__);
#define U32(...)     \
    u32 __VA_ARGS__; \
    read(__VA_ARGS__);
#define U64(...)     \
    u64 __VA_ARGS__; \
    read(__VA_ARGS__);
#define I32(...)     \
    i32 __VA_ARGS__; \
    read(__VA_ARGS__);
#define I64(...)     \
    i64 __VA_ARGS__; \
    read(__VA_ARGS__);
#define STR(...)        \
    string __VA_ARGS__; \
    read(__VA_ARGS__);
#define VEC(type, name, size) \
    V<type> name(size);       \
    read(name);
#define VVEC(type, name, size1, size2)    \
    VV<type> name(size1, V<type>(size2)); \
    read(name);
// ============

#ifdef DEBUGF
#else
#define DBG(...) (void)0
#endif

struct Dat {
    i64 a, b;
};

Dat id() {
    return Dat{0, 0};
}

Dat op(const Dat &d, const Dat &e) {
    i64 a = max(d.a, d.a - d.b + e.a);
    i64 f = d.b - d.a + e.b - e.a;
    i64 b = f + a;
    return Dat{a, b};
}

void solve() {
    I32(n);
    V<i64> a(n), b(n);
    REP(i, n) {
        read(a[i], b[i]);
    }
    V<Dat> dats(n);
    REP(i, n) {
        dats[i] = Dat{a[i], b[i]};
    }
    const auto comp = [&](const Dat &d, const Dat &e) -> bool {
        i64 x = d.b - d.a;
        i64 y = e.b - e.a;
        if (x >= 0 && y < 0) {
            return true;
        }
        if (x < 0 && y >= 0) {
            return false;
        }
        if (x >= 0 && y >= 0) {
            return d.a < e.a;
        }
        return d.b > e.b;
    };
    sort(ALL(dats), comp);
    REP(i, n) {
        DBG(dats[i].a, dats[i].b);
    }
    V<Dat> lp(n + 1, id()), rp(n + 1, id());
    REP(i, n) {
        lp[i + 1] = op(lp[i], dats[i]);
    }
    PER(i, n) {
        rp[i] = op(dats[i], rp[i + 1]);
    }
    i64 asum = accumulate(ALL(a), 0LL), bsum = accumulate(ALL(b), 0LL);
    i64 mx = bsum - asum;
    DBG(asum, bsum, mx);
    i64 ans = INF64;
    REP(i, n) {
        if (dats[i].b <= mx) {
            Dat me = op(lp[i], rp[i + 1]);
            DBG(i, me.a, me.b);
            chmin(ans, me.a);
        }
    }
    if (ans == INF64) {
        cout << -1 << '\n';
        return;
    }
    ans += asum;
    cout << ans << '\n';
}

int main() {
    i32 t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
