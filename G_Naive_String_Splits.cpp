#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

template<class T>
constexpr T power(T a, u64 b, T res = 1) {
    for (; b != 0; b /= 2, a *= a) {
        if (b & 1) {
            res *= a;
        }
    }
    return res;
}

template<u32 P>
constexpr u32 mulMod(u32 a, u32 b) {
    return u64(a) * b % P;
}

template<u64 P>
constexpr u64 mulMod(u64 a, u64 b) {
    u64 res = a * b - u64(1.L * a * b / P - 0.5L) * P;
    res %= P;
    return res;
}

constexpr i64 safeMod(i64 x, i64 m) {
    x %= m;
    if (x < 0) {
        x += m;
    }
    return x;
}

constexpr std::pair<i64, i64> invGcd(i64 a, i64 b) {
    a = safeMod(a, b);
    if (a == 0) {
        return {b, 0};
    }
    
    i64 s = b, t = a;
    i64 m0 = 0, m1 = 1;

    while (t) {
        i64 u = s / t;
        s -= t * u;
        m0 -= m1 * u;
        
        std::swap(s, t);
        std::swap(m0, m1);
    }
    
    if (m0 < 0) {
        m0 += b / s;
    }
    
    return {s, m0};
}

template<std::unsigned_integral U, U P>
struct ModIntBase {
public:
    constexpr ModIntBase() : x(0) {}
    template<std::unsigned_integral T>
    constexpr ModIntBase(T x_) : x(x_ % mod()) {}
    template<std::signed_integral T>
    constexpr ModIntBase(T x_) {
        using S = std::make_signed_t<U>;
        S v = x_ % S(mod());
        if (v < 0) {
            v += mod();
        }
        x = v;
    }
    
    constexpr static U mod() {
        return P;
    }
    
    constexpr U val() const {
        return x;
    }
    
    constexpr ModIntBase operator-() const {
        ModIntBase res;
        res.x = (x == 0 ? 0 : mod() - x);
        return res;
    }
    
    constexpr ModIntBase inv() const {
        return power(*this, mod() - 2);
    }
    
    constexpr ModIntBase &operator*=(const ModIntBase &rhs) & {
        x = mulMod<mod()>(x, rhs.val());
        return *this;
    }
    constexpr ModIntBase &operator+=(const ModIntBase &rhs) & {
        x += rhs.val();
        if (x >= mod()) {
            x -= mod();
        }
        return *this;
    }
    constexpr ModIntBase &operator-=(const ModIntBase &rhs) & {
        x -= rhs.val();
        if (x >= mod()) {
            x += mod();
        }
        return *this;
    }
    constexpr ModIntBase &operator/=(const ModIntBase &rhs) & {
        return *this *= rhs.inv();
    }
    
    friend constexpr ModIntBase operator*(ModIntBase lhs, const ModIntBase &rhs) {
        lhs *= rhs;
        return lhs;
    }
    friend constexpr ModIntBase operator+(ModIntBase lhs, const ModIntBase &rhs) {
        lhs += rhs;
        return lhs;
    }
    friend constexpr ModIntBase operator-(ModIntBase lhs, const ModIntBase &rhs) {
        lhs -= rhs;
        return lhs;
    }
    friend constexpr ModIntBase operator/(ModIntBase lhs, const ModIntBase &rhs) {
        lhs /= rhs;
        return lhs;
    }
    
    friend constexpr std::istream &operator>>(std::istream &is, ModIntBase &a) {
        i64 i;
        is >> i;
        a = i;
        return is;
    }
    friend constexpr std::ostream &operator<<(std::ostream &os, const ModIntBase &a) {
        return os << a.val();
    }
    
    friend constexpr bool operator==(const ModIntBase &lhs, const ModIntBase &rhs) {
        return lhs.val() == rhs.val();
    }
    friend constexpr std::strong_ordering operator<=>(const ModIntBase &lhs, const ModIntBase &rhs) {
        return lhs.val() <=> rhs.val();
    }
    
private:
    U x;
};

template<u32 P>
using ModInt = ModIntBase<u32, P>;
template<u64 P>
using ModInt64 = ModIntBase<u64, P>;

struct Barrett {
public:
    Barrett(u32 m_) : m(m_), im((u64)(-1) / m_ + 1) {}

    constexpr u32 mod() const {
        return m;
    }

    constexpr u32 mul(u32 a, u32 b) const {
        u64 z = a;
        z *= b;
        
        u64 x = u64((u128(z) * im) >> 64);
        
        u32 v = u32(z - x * m);
        if (m <= v) {
            v += m;
        }
        return v;
    }

private:
    u32 m;
    u64 im;
};

template<u32 Id>
struct DynModInt {
public:
    constexpr DynModInt() : x(0) {}
    template<std::unsigned_integral T>
    constexpr DynModInt(T x_) : x(x_ % mod()) {}
    template<std::signed_integral T>
    constexpr DynModInt(T x_) {
        int v = x_ % int(mod());
        if (v < 0) {
            v += mod();
        }
        x = v;
    }
    
    constexpr static void setMod(u32 m) {
        bt = m;
    }
    
    static u32 mod() {
        return bt.mod();
    }
    
    constexpr u32 val() const {
        return x;
    }
    
    constexpr DynModInt operator-() const {
        DynModInt res;
        res.x = (x == 0 ? 0 : mod() - x);
        return res;
    }
    
    constexpr DynModInt inv() const {
        auto v = invGcd(x, mod());
        assert(v.first == 1);
        return v.second;
    }
    
    constexpr DynModInt &operator*=(const DynModInt &rhs) & {
        x = bt.mul(x, rhs.val());
        return *this;
    }
    constexpr DynModInt &operator+=(const DynModInt &rhs) & {
        x += rhs.val();
        if (x >= mod()) {
            x -= mod();
        }
        return *this;
    }
    constexpr DynModInt &operator-=(const DynModInt &rhs) & {
        x -= rhs.val();
        if (x >= mod()) {
            x += mod();
        }
        return *this;
    }
    constexpr DynModInt &operator/=(const DynModInt &rhs) & {
        return *this *= rhs.inv();
    }
    
    friend constexpr DynModInt operator*(DynModInt lhs, const DynModInt &rhs) {
        lhs *= rhs;
        return lhs;
    }
    friend constexpr DynModInt operator+(DynModInt lhs, const DynModInt &rhs) {
        lhs += rhs;
        return lhs;
    }
    friend constexpr DynModInt operator-(DynModInt lhs, const DynModInt &rhs) {
        lhs -= rhs;
        return lhs;
    }
    friend constexpr DynModInt operator/(DynModInt lhs, const DynModInt &rhs) {
        lhs /= rhs;
        return lhs;
    }
    
    friend constexpr std::istream &operator>>(std::istream &is, DynModInt &a) {
        i64 i;
        is >> i;
        a = i;
        return is;
    }
    friend constexpr std::ostream &operator<<(std::ostream &os, const DynModInt &a) {
        return os << a.val();
    }
    
    friend constexpr bool operator==(const DynModInt &lhs, const DynModInt &rhs) {
        return lhs.val() == rhs.val();
    }
    friend constexpr std::strong_ordering operator<=>(const DynModInt &lhs, const DynModInt &rhs) {
        return lhs.val() <=> rhs.val();
    }
    
private:
    u32 x;
    static Barrett bt;
};

template<u32 Id>
Barrett DynModInt<Id>::bt = 998244353;

#ifdef ONLINE_JUDGE
constexpr u64 P = u64(1E18) + 9;
#else
constexpr u64 P = 998244353;
#endif
using Z = ModInt64<P>;
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
const Z B = rng() % (P / 2) + P / 4;

int exgcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int g = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return g;
}

void solve() {
    int n, m;
    std::cin >> n >> m;
    
    std::string s;
    std::cin >> s;
    
    std::string t;
    std::cin >> t;
    
    std::vector<Z> pw(m + 1);
    pw[0] = 1;
    for (int i = 1; i <= m; i++) {
        pw[i] = pw[i - 1] * B;
    }
    
    std::vector<Z> prod(m + 1);
    prod[0] = 1;
    for (int i = 1; i <= m; i++) {
        prod[i] = prod[i - 1] * (pw[i] - 1);
    }
    std::vector<Z> inv(m + 1);
    auto iprod = prod[m].inv();
    for (int i = m; i >= 1; i--) {
        inv[i] = iprod * prod[i - 1];
        iprod *= (pw[i] - 1);
    }
    
    std::vector<Z> hs(n + 1), ht(m + 1);
    for (int i = 0; i < n; i++) {
        hs[i + 1] = hs[i] * B + s[i];
    }
    for (int i = 0; i < m; i++) {
        ht[i + 1] = ht[i] * B + t[i];
    }
    
    auto gethash = [&](auto &h, int l, int r) {
        return h[r] - h[l] * pw[r - l];
    };
    
    std::vector<int> f(n + 1);
    for (int i = 1, j = 0; i < n; i++) {
        while (j && s[i] != s[j]) {
            j = f[j];
        }
        j += (s[i] == s[j]);
        f[i + 1] = j;
    }
    int T = n % (n - f[n]) == 0 ? n - f[n] : n;
    
    auto copy = [&](Z h, int len, int t) {
        return h * (pw[len * t] - 1) * inv[len];
    };
    
    auto getmax = [&](auto &h, int l, int r, Z hs, int len) {
        int lo = 0, hi = (r - l) / len;
        while (lo < hi) {
            int x = (lo + hi + 1) / 2;
            if (gethash(h, l, l + x * len) == copy(hs, len, x)) {
                lo = x;
            } else {
                hi = x - 1;
            }
        }
        return lo;
    };
    
    auto check = [&](int i) {
        if (i % T == 0) {
            if (m % T != 0) {
                return false;
            }
            if (ht[m] != copy(hs[T], T, m / T)) {
                return false;
            }
            int a = i, b = n - i;
            int x, y;
            int g = exgcd(a, b, x, y);
            if (m % g != 0) {
                return false;
            }
            x = 1LL * x * (m / g) % (b / g);
            if (x < 0) {
                x += b / g;
            }
            return 1LL * x * a <= m;
        }
        int la = i, lb = n - i;
        auto ha = gethash(hs, 0, i), hb = gethash(hs, i, n);
        int times = 0;
        if (la <= lb) {
            times = getmax(hs, i, n, ha, la);
        } else {
            times = getmax(hs, 0, i, hb, lb);
            std::swap(la, lb);
            std::swap(ha, hb);
        }
        for (int i = 0; i < m; ) {
            int x = getmax(ht, i, m, ha, la);
            if (i + x * la == m) {
                return true;
            }
            if (x < times) {
                return false;
            }
            if (i + (x - times) * la + lb <= m && gethash(ht, i + (x - times) * la, i + (x - times) * la + lb) == hb) {
                i += (x - times) * la + lb;
            } else if (x > times && i + (x - times - 1) * la + lb <= m && gethash(ht, i + (x - 1 - times) * la, i + (x - 1 - times) * la + lb) == hb) {
                i += (x - 1 - times) * la + lb;
            } else {
                return false;
            }
        }
        return true;
    };
    
    std::string ans(n - 1, '0');
    for (int i = 1; i < n; i++) {
        if (check(i)) {
            ans[i - 1] = '1';
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
