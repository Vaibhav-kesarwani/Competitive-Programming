#include "bits/stdc++.h"

#pragma GCC optimize("O3")

#pragma GCC target("sse4")

using namespace std;

// #include <ext/pb_ds/assoc_container.hpp>

// using namespace __gnu_pbds;

// #pragma region

// template <typename T>

// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ll long long

#define ull unsigned long long

#define ld long double

#define mp make_pair

#define pb push_back

#define f first

#define s second

#define lb lower_bound

#define ub upper_bound

#define all(x) x.begin(), x.end()

#define rall(x) x.rbegin(), x.rend()

#define ins insert

#define sz(x) static_cast<int>((x).size())

void __print(int x) { cout << x; }

void __print(long x) { cout << x; }

void __print(long long x) { cout << x; }

void __print(unsigned x) { cout << x; }

void __print(unsigned long x) { cout << x; }

void __print(unsigned long long x) { cout << x; }

void __print(float x) { cout << x; }

void __print(double x) { cout << x; }

void __print(long double x) { cout << x; }

void __print(char x) { cout << '\'' << x << '\''; }

void __print(const char *x) { cout << '\"' << x << '\"'; }

void __print(const string &x) { cout << '\"' << x << '\"'; }

void __print(bool x) { cout << (x ? "true" : "false"); }

template <typename T, typename V>

void __print(const pair<T, V> &x);

template <size_t N>

void __print(const bitset<N> &x);

template <typename T>

void __print(const T &x);

template <typename T, typename... V>

void _print(T t, V... v);

template <typename T, typename V>

void __print(const pair<T, V> &x)
{
    cout << '{';
    __print(x.first);
    cout << ", ";
    __print(x.second);
    cout << '}';
}

template <typename T>

void __print(const T &x)
{
    int f = 0;
    cout << '{';
    for (auto &i : x)
        cout << (f++ ? ", " : ""), __print(i);
    cout << "}";
}

void _print() { cout << "]\n"; }

template <typename T, typename... V>

void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cout << ", ";
    _print(v...);
}

template <size_t N>

void __print(const bitset<N> &x)
{
    cout << x;
}

#define F_OR(i, a, b, s) for (int i = (a); (s) > 0 ? i < (int)(b) : i > (int)(b); i += (s))

#define F_OR1(e) F_OR(i, 0, e, 1)

#define F_OR2(i, e) F_OR(i, 0, e, 1)

#define F_OR3(i, b, e) F_OR(i, b, e, 1)

#define F_OR4(i, b, e, s) F_OR(i, b, e, s)

#define GET5(a, b, c, d, e, ...) e

#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)

#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)

#define E_ACH2(x, a) for (auto &x : a)

#define E_ACH3(x, y, a) for (auto &[x, y] : a)

#define E_ACH4(x, y, z, a) for (auto &[x, y, z] : a)

#define E_ACHC(...) GET5(__VA_ARGS__, E_ACH4, E_ACH3, E_ACH2)

#define EACH(...) E_ACHC(__VA_ARGS__)(__VA_ARGS__)

template <class T>
using vec = vector<T>;

template <class T>
using vvec = vec<vec<T>>;

template <class T>
using vvvec = vec<vvec<T>>;

template <class T, size_t SZ>
using vac = vec<array<T, SZ>>;

template <class T, size_t SZ>
using vvac = vec<vac<T, SZ>>;

void decrement() {}

template <class T>
void decrement(vec<T> &v) { EACH(x, v)
                            -- x; }

template <class T, size_t SZ>
void decrement(vec<array<T, SZ>> &v) { EACH(row, v)
                                       EACH(x, row)-- x; }

template <class T>
void decrement(vec<vec<T>> &v) { EACH(row, v)
                                 EACH(x, row)-- x; }

template <class T, class... U>
void decrement(T &t, U &...u)
{
    --t;
    decrement(u...);
}

#define SUBMASKS(t, s) for (ll t = (s); t >= 0; t = (t == 0 ? -1 : (t - 1) & (s)))

#define MIN(v) *min_element(all(v))

#define MAX(v) *max_element(all(v))

template <class T, size_t SZ>
using vac = vec<array<T, SZ>>;

template <class T, size_t SZ>
using vvac = vec<vac<T, SZ>>;

template <class T, size_t SZ>
istream &operator>>(istream &s, array<T, SZ> &v)
{
    FOR(sz(v))
        s >> v[i];
    return s;
}

template <class T>
istream &operator>>(istream &s, vec<T> &v)
{
    FOR(sz(v))
        s >> v[i];
    return s;
}

template <class T>
void read(T &x) { cin >> x; }

template <class T, class... U>
void read(T &t, U &...u)
{
    read(t);
    read(u...);
}

#define ints(...)    \
    int __VA_ARGS__; \
    read(__VA_ARGS__);

#define int1(...)      \
    ints(__VA_ARGS__); \
    decrement(__VA_ARGS__);

#define lls(...)    \
    ll __VA_ARGS__; \
    read(__VA_ARGS__);

#define vint(n, a) \
    int n;         \
    cin >> n;      \
    vec<ll> a(n);  \
    cin >> a;

#define vin(n, a)   \
    vec<ll> a((n)); \
    cin >> a;

#define vvin(n, m, a)                  \
    vec<vec<ll>> a((n), vec<ll>((m))); \
    cin >> a;

#define vain(n, m, a)           \
    vec<array<ll, (m)>> a((n)); \
    cin >> a;

#define graphin(n, m, adj) \
    vvec<ll> adj(n);       \
    FOR(m)                 \
    {                      \
        int1(u, v);        \
        adj[u].pb(v);      \
        adj[v].pb(u);      \
    }

#define wgraphin(n, m, adj) \
    vvac<ll, 2> adj(n);     \
    FOR(m)                  \
    {                       \
        int1(u, v);         \
        ints(w);            \
        adj[u].pb({v, w});  \
        adj[v].pb({u, w});  \
    }

#define dgraphin(n, m, adj) \
    vvec<ll> adj(n);        \
    FOR(m)                  \
    {                       \
        int1(u, v);         \
        adj[u].pb(v);       \
    }

#define dwgraphin(n, m, adj)   \
    vvac<ll, 2> adj(n);        \
    FOR(m)                     \
    {                          \
        int1(u, v, w);         \
        adj[u].pb({v, w + 1}); \
    }

#define dbg(x...)                                                            \
    cout << "[" << __func__ << ":" << __LINE__ - 5 << " [" << #x << "] = ["; \
    _print(x);                                                               \
    cout << endl;

// #define dbg(x...)

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// uniform_int_distribution<int> distribution(10, 100);

// ints(N, M);

// wgraphin(N, M, A);

// dbg(A);

#include <bits/stdc++.h>

using namespace std;

// Source: https://github.com/atcoder/ac-library

namespace atcoder
{

    namespace internal
    {

        constexpr long long safe_mod(long long x, long long m)
        {

            x %= m;

            if (x < 0)
                x += m;

            return x;
        }

        struct barrett
        {

            unsigned int _m;

            unsigned long long im;

            barrett(unsigned int m) : _m(m), im((unsigned long long)(-1) / m + 1) {}

            unsigned int umod() const { return _m; }

            unsigned int mul(unsigned int a, unsigned int b) const
            {

                unsigned long long z = a;

                z *= b;

#ifdef _MSC_VER

                unsigned long long x;

                _umul128(z, im, &x);

#else

                unsigned long long x =

                    (unsigned long long)(((unsigned __int128)(z)*im) >> 64);

#endif

                unsigned int v = (unsigned int)(z - x * _m);

                if (_m <= v)
                    v += _m;

                return v;
            }
        };

        constexpr long long pow_mod_constexpr(long long x, long long n, int m)
        {

            if (m == 1)
                return 0;

            unsigned int _m = (unsigned int)(m);

            unsigned long long r = 1;

            unsigned long long y = safe_mod(x, m);

            while (n)
            {

                if (n & 1)
                    r = (r * y) % _m;

                y = (y * y) % _m;

                n >>= 1;
            }

            return r;
        }

        constexpr bool is_prime_constexpr(int n)
        {

            if (n <= 1)
                return false;

            if (n == 2 || n == 7 || n == 61)
                return true;

            if (n % 2 == 0)
                return false;

            long long d = n - 1;

            while (d % 2 == 0)
                d /= 2;

            constexpr long long bases[3] = {2, 7, 61};

            for (long long a : bases)
            {

                long long t = d;

                long long y = pow_mod_constexpr(a, t, n);

                while (t != n - 1 && y != 1 && y != n - 1)
                {

                    y = y * y % n;

                    t <<= 1;
                }

                if (y != n - 1 && t % 2 == 0)
                {

                    return false;
                }
            }

            return true;
        }

        template <int n>
        constexpr bool is_prime = is_prime_constexpr(n);

        constexpr std::pair<long long, long long> inv_gcd(long long a, long long b)
        {

            a = safe_mod(a, b);

            if (a == 0)
                return {b, 0};

            long long s = b, t = a;

            long long m0 = 0, m1 = 1;

            while (t)
            {

                long long u = s / t;

                s -= t * u;

                m0 -= m1 * u; // |m1 * u| <= |m1| * s <= b

                auto tmp = s;

                s = t;

                t = tmp;

                tmp = m0;

                m0 = m1;

                m1 = tmp;
            }

            if (m0 < 0)
                m0 += b / s;

            return {s, m0};
        }

        constexpr int primitive_root_constexpr(int m)
        {

            if (m == 2)
                return 1;

            if (m == 167772161)
                return 3;

            if (m == 469762049)
                return 3;

            if (m == 754974721)
                return 11;

            if (m == 998244353)
                return 3;

            int divs[20] = {};

            divs[0] = 2;

            int cnt = 1;

            int x = (m - 1) / 2;

            while (x % 2 == 0)
                x /= 2;

            for (int i = 3; (long long)(i)*i <= x; i += 2)
            {

                if (x % i == 0)
                {

                    divs[cnt++] = i;

                    while (x % i == 0)
                    {

                        x /= i;
                    }
                }
            }

            if (x > 1)
            {

                divs[cnt++] = x;
            }

            for (int g = 2;; g++)
            {

                bool ok = true;

                for (int i = 0; i < cnt; i++)
                {

                    if (pow_mod_constexpr(g, (m - 1) / divs[i], m) == 1)
                    {

                        ok = false;

                        break;
                    }
                }

                if (ok)
                    return g;
            }
        }

        template <int m>
        constexpr int primitive_root = primitive_root_constexpr(m);

    } // namespace internal

} // namespace atcoder

#include <cassert>

#include <numeric>

#include <type_traits>

namespace atcoder
{

    namespace internal
    {

#ifndef _MSC_VER

        template <class T>

        using is_signed_int128 =

            typename std::conditional<std::is_same<T, __int128_t>::value ||

                                          std::is_same<T, __int128>::value,

                                      std::true_type,

                                      std::false_type>::type;

        template <class T>

        using is_unsigned_int128 =

            typename std::conditional<std::is_same<T, __uint128_t>::value ||

                                          std::is_same<T, unsigned __int128>::value,

                                      std::true_type,

                                      std::false_type>::type;

        template <class T>

        using make_unsigned_int128 =

            typename std::conditional<std::is_same<T, __int128_t>::value,

                                      __uint128_t,

                                      unsigned __int128>;

        template <class T>

        using is_integral = typename std::conditional<std::is_integral<T>::value ||

                                                          is_signed_int128<T>::value ||

                                                          is_unsigned_int128<T>::value,

                                                      std::true_type,

                                                      std::false_type>::type;

        template <class T>

        using is_signed_int = typename std::conditional<(is_integral<T>::value &&

                                                         std::is_signed<T>::value) ||

                                                            is_signed_int128<T>::value,

                                                        std::true_type,

                                                        std::false_type>::type;

        template <class T>

        using is_unsigned_int =

            typename std::conditional<(is_integral<T>::value &&

                                       std::is_unsigned<T>::value) ||

                                          is_unsigned_int128<T>::value,

                                      std::true_type,

                                      std::false_type>::type;

        template <class T>

        using to_unsigned = typename std::conditional<

            is_signed_int128<T>::value,

            make_unsigned_int128<T>,

            typename std::conditional<std::is_signed<T>::value,

                                      std::make_unsigned<T>,

                                      std::common_type<T>>::type>::type;

#else

        template <class T>
        using is_integral = typename std::is_integral<T>;

        template <class T>

        using is_signed_int =

            typename std::conditional<is_integral<T>::value && std::is_signed<T>::value,

                                      std::true_type,

                                      std::false_type>::type;

        template <class T>

        using is_unsigned_int =

            typename std::conditional<is_integral<T>::value &&

                                          std::is_unsigned<T>::value,

                                      std::true_type,

                                      std::false_type>::type;

        template <class T>

        using to_unsigned = typename std::conditional<is_signed_int<T>::value,

                                                      std::make_unsigned<T>,

                                                      std::common_type<T>>::type;

#endif

        template <class T>

        using is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;

        template <class T>

        using is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;

        template <class T>
        using to_unsigned_t = typename to_unsigned<T>::type;

    } // namespace internal

} // namespace atcoder

#include <cassert>

#include <numeric>

#include <type_traits>

#ifdef _MSC_VER

#include <intrin.h>

#endif

namespace atcoder
{

    namespace internal
    {

        struct modint_base
        {
        };

        struct static_modint_base : modint_base
        {
        };

        template <class T>
        using is_modint = std::is_base_of<modint_base, T>;

        template <class T>
        using is_modint_t = std::enable_if_t<is_modint<T>::value>;

    } // namespace internal

    template <int m, std::enable_if_t<(1 <= m)> * = nullptr>

    struct static_modint : internal::static_modint_base
    {

        using mint = static_modint;

    public:
        static constexpr int mod() { return m; }

        static mint raw(int v)
        {

            mint x;

            x._v = v;

            return x;
        }

        static_modint() : _v(0) {}

        template <class T, internal::is_signed_int_t<T> * = nullptr>

        static_modint(T v)
        {

            long long x = (long long)(v % (long long)(umod()));

            if (x < 0)
                x += umod();

            _v = (unsigned int)(x);
        }

        template <class T, internal::is_unsigned_int_t<T> * = nullptr>

        static_modint(T v)
        {

            _v = (unsigned int)(v % umod());
        }

        static_modint(bool v) { _v = ((unsigned int)(v) % umod()); }

        unsigned int val() const { return _v; }

        mint &operator++()
        {

            _v++;

            if (_v == umod())
                _v = 0;

            return *this;
        }

        mint &operator--()
        {

            if (_v == 0)
                _v = umod();

            _v--;

            return *this;
        }

        mint operator++(int)
        {

            mint result = *this;

            ++*this;

            return result;
        }

        mint operator--(int)
        {

            mint result = *this;

            --*this;

            return result;
        }

        mint &operator+=(const mint &rhs)
        {

            _v += rhs._v;

            if (_v >= umod())
                _v -= umod();

            return *this;
        }

        mint &operator-=(const mint &rhs)
        {

            _v -= rhs._v;

            if (_v >= umod())
                _v += umod();

            return *this;
        }

        mint &operator*=(const mint &rhs)
        {

            unsigned long long z = _v;

            z *= rhs._v;

            _v = (unsigned int)(z % umod());

            return *this;
        }

        mint &operator/=(const mint &rhs) { return *this = *this * rhs.inv(); }

        mint operator+() const { return *this; }

        mint operator-() const { return mint() - *this; }

        mint pow(long long n) const
        {

            assert(0 <= n);

            mint x = *this, r = 1;

            while (n)
            {

                if (n & 1)
                    r *= x;

                x *= x;

                n >>= 1;
            }

            return r;
        }

        mint inv() const
        {

            if (prime)
            {

                assert(_v);

                return pow(umod() - 2);
            }
            else
            {

                auto eg = internal::inv_gcd(_v, m);

                assert(eg.first == 1);

                return eg.second;
            }
        }

        friend mint operator+(const mint &lhs, const mint &rhs)
        {

            return mint(lhs) += rhs;
        }

        friend mint operator-(const mint &lhs, const mint &rhs)
        {

            return mint(lhs) -= rhs;
        }

        friend mint operator*(const mint &lhs, const mint &rhs)
        {

            return mint(lhs) *= rhs;
        }

        friend mint operator/(const mint &lhs, const mint &rhs)
        {

            return mint(lhs) /= rhs;
        }

        friend bool operator==(const mint &lhs, const mint &rhs)
        {

            return lhs._v == rhs._v;
        }

        friend bool operator!=(const mint &lhs, const mint &rhs)
        {

            return lhs._v != rhs._v;
        }

    private:
        unsigned int _v;

        static constexpr unsigned int umod() { return m; }

        static constexpr bool prime = internal::is_prime<m>;
    };

    template <int id>
    struct dynamic_modint : internal::modint_base
    {

        using mint = dynamic_modint;

    public:
        static int mod() { return (int)(bt.umod()); }

        static void set_mod(int m)
        {

            assert(1 <= m);

            bt = internal::barrett(m);
        }

        static mint raw(int v)
        {

            mint x;

            x._v = v;

            return x;
        }

        dynamic_modint() : _v(0) {}

        template <class T, internal::is_signed_int_t<T> * = nullptr>

        dynamic_modint(T v)
        {

            long long x = (long long)(v % (long long)(mod()));

            if (x < 0)
                x += mod();

            _v = (unsigned int)(x);
        }

        template <class T, internal::is_unsigned_int_t<T> * = nullptr>

        dynamic_modint(T v)
        {

            _v = (unsigned int)(v % mod());
        }

        dynamic_modint(bool v) { _v = ((unsigned int)(v) % mod()); }

        unsigned int val() const { return _v; }

        mint &operator++()
        {

            _v++;

            if (_v == umod())
                _v = 0;

            return *this;
        }

        mint &operator--()
        {

            if (_v == 0)
                _v = umod();

            _v--;

            return *this;
        }

        mint operator++(int)
        {

            mint result = *this;

            ++*this;

            return result;
        }

        mint operator--(int)
        {

            mint result = *this;

            --*this;

            return result;
        }

        mint &operator+=(const mint &rhs)
        {

            _v += rhs._v;

            if (_v >= umod())
                _v -= umod();

            return *this;
        }

        mint &operator-=(const mint &rhs)
        {

            _v += mod() - rhs._v;

            if (_v >= umod())
                _v -= umod();

            return *this;
        }

        mint &operator*=(const mint &rhs)
        {

            _v = bt.mul(_v, rhs._v);

            return *this;
        }

        mint &operator/=(const mint &rhs) { return *this = *this * rhs.inv(); }

        mint operator+() const { return *this; }

        mint operator-() const { return mint() - *this; }

        mint pow(long long n) const
        {

            assert(0 <= n);

            mint x = *this, r = 1;

            while (n)
            {

                if (n & 1)
                    r *= x;

                x *= x;

                n >>= 1;
            }

            return r;
        }

        mint inv() const
        {

            auto eg = internal::inv_gcd(_v, mod());

            assert(eg.first == 1);

            return eg.second;
        }

        friend mint operator+(const mint &lhs, const mint &rhs)
        {

            return mint(lhs) += rhs;
        }

        friend mint operator-(const mint &lhs, const mint &rhs)
        {

            return mint(lhs) -= rhs;
        }

        friend mint operator*(const mint &lhs, const mint &rhs)
        {

            return mint(lhs) *= rhs;
        }

        friend mint operator/(const mint &lhs, const mint &rhs)
        {

            return mint(lhs) /= rhs;
        }

        friend bool operator==(const mint &lhs, const mint &rhs)
        {

            return lhs._v == rhs._v;
        }

        friend bool operator!=(const mint &lhs, const mint &rhs)
        {

            return lhs._v != rhs._v;
        }

    private:
        unsigned int _v;

        static internal::barrett bt;

        static unsigned int umod() { return bt.umod(); }
    };

    template <int id>
    internal::barrett dynamic_modint<id>::bt = 998244353;

    using modint998244353 = static_modint<998244353>;

    using modint1000000007 = static_modint<1000000007>;

    using modint = dynamic_modint<-1>;

    using mint = modint1000000007;

    namespace internal
    {

        template <class T>

        using is_static_modint = std::is_base_of<internal::static_modint_base, T>;

        template <class T>

        using is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;

        template <class>
        struct is_dynamic_modint : public std::false_type
        {
        };

        template <int id>

        struct is_dynamic_modint<dynamic_modint<id>> : public std::true_type
        {
        };

        template <class T>

        using is_dynamic_modint_t = std::enable_if_t<is_dynamic_modint<T>::value>;

    } // namespace internal

} // namespace atcoder

using namespace atcoder;

#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

long long mul(long long a, long long b)
{

    return a * b % MOD;
}

long long power(long long base, long long exp = MOD - 2)
{

    long long res = 1, y = base;

    while (exp)
    {

        if (exp & 1)
            res = mul(res, y);

        y = mul(y, y);

        exp >>= 1;
    }

    return res;
}

struct Math
{

    vector<long long> fact, inv;

    Math(int n = 1)
    {

        fact.resize(n + 1);

        inv.resize(n + 1);

        fact[0] = inv[0] = 1;

        for (int i = 1; i <= n; i++)
            fact[i] = mul(fact[i - 1], i);

        inv[n] = power(fact[n]);

        for (int i = n; i > 1; i--)
            inv[i - 1] = mul(inv[i], i);
    }

    long long comb(int n, int k)
    {

        if (n < k)
            return 0;

        return mul(mul(fact[n], inv[k]), inv[n - k]);
    }

    long long perm(int n, int k)
    {

        if (n < k)
            return 0;

        return mul(fact[n], inv[n - k]);
    }

    long long multi(vector<int> v)
    {

        long long res = fact[accumulate(v.begin(), v.end(), 0)];

        for (int i : v)
            res = mul(res, inv[i]);

        return res;
    }

} math(100005);

void solve_case()
{

    lls(C, R, K, X, Y);

    mint P = mint(X) / mint(Y);

    // dbg(P.val());

    // K = min(K, C);

    mint res(0);

    for (int s = 1; s <= K; ++s)
    {

        res += ((1 + (1 - 2 * P).pow(s)) / 2).pow(R) * math.comb(C, s);
    }

    cout << res.val() << endl;
}

int main()
{

    ios_base::sync_with_stdio(0);

    cin.tie(0);

    // solve();

    // int T = 1;

    int T;
    cin >> T;

    for (int t = 0; t < T; ++t)
    {

        solve_case();
    }

    return 0;
}
