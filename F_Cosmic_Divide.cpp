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

void solve() {
    I32(n);
    V<i64> l(n), r(n);
    REP(i, n) {
        read(l[i], r[i]);
        ++r[i];
    }
    
    V<i64> len(n);
    REP(i, n) {
        len[i] = r[i] - l[i];
    }
    DBG(len);
    
    auto test = [&](i32 d) -> bool {
        DBG(d);
        if (d == 0) {
            if (len[0] % 2) {
                return false;
            }
            REP(i, n) {
                if (len[i] != len[0]) {
                    return false;
                }
            }
            i32 p = len[0] / 2;
            REP(i, n - 1) {
                if (abs(l[i] - l[i + 1]) >= p) {
                    return false;
                }
            }
            return true;
        }
        if (2 * d > n) {
            return false;
        }
        {
            V<i64> a(n - d);
            REP(i, d) {
                a[i] = len[i];
            }
            REP(i, d, n - d) {
                a[i] = len[i] - a[i - d];
                if (a[i] <= 0) {
                    return false;
                }
            }
            REP(i, n - d, n) {
                if (a[i - d] != len[i]) {
                    return false;
                }
            }
        }
        REP(iter, 2) {
            // (0, l[0]) -> (d, l[d])
            i64 shift = l[d] - l[0];
            V<i64> ll = l;
            bool ok = true;
            REP(i, n - d) {
                if (ll[i] + shift != l[i + d]) {
                    ok = false;
                    break;
                }
                ll[i + d] = r[i] + shift;
            }
            DBG(ll, ok);
            if (ok) REP(i, n - d, n) {
                if (ll[i] != r[i]) {
                    ok = false;
                    break;
                }
            }
            REP(i, n - d - 1) {
                if (r[i] <= ll[i + 1] || r[i + 1] <= ll[i]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                return true;
            }
            REP(i, n) {
                i32 mem = l[i];
                l[i] = -r[i];
                r[i] = -mem;
            }
        }
        return false;
    };
    
    V<i64> sum(n + 1, 0);
    REP(i, n) {
        sum[i + 1] = sum[i] + len[i];
    }
    
    if (test(0)) {
        cout << "YES\n";
        return;
    }
    REP(d, 1, n) {
        i64 s = 0;
        i64 sign = 1;
        for (i32 i = 0; i < n; i += d) {
            i32 r = min(n, i + d);
            s += sign * (sum[r] - sum[i]);
            sign = -sign;
        }
        if (s == 0 && test(d)) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main() {
    i32 t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
