#include <bits/stdc++.h>

namespace FastIO
{
    template <typename T>
    inline T read()
    {
        T x = 0, w = 0;
        char ch = getchar();
        while (ch < '0' || ch > '9')
            w |= (ch == '-'), ch = getchar();
        while ('0' <= ch && ch <= '9')
            x = x * 10 + (ch ^ '0'), ch = getchar();
        return w ? -x : x;
    }
    template <typename T>
    inline void write(T x)
    {
        if (!x)
            return;
        write<T>(x / 10), putchar((x % 10) ^ '0');
    }
    template <typename T>
    inline void print(T x)
    {
        if (x > 0)
            write<T>(x);
        else if (x < 0)
            putchar('-'), write<T>(-x);
        else
            putchar('0');
    }
    template <typename T>
    inline void print(T x, char en) { print<T>(x), putchar(en); }
};
using namespace FastIO;

const int MOD = 998244353;
namespace Modint
{
    inline int add(int x, int y) { return (x += y) >= MOD ? x - MOD : x; }
    inline int sub(int x, int y) { return x < y ? x - y + MOD : x - y; }
    inline int mul(int x, int y) { return 1ll * x * y % MOD; }
    inline int pow(int x, int y)
    {
        int r = 1;
        for (; y; y >>= 1, x = mul(x, x))
            if (y & 1)
                r = mul(r, x);
        return r;
    }
    inline int inv(int x) { return pow(x, MOD - 2); }
};
struct modint
{
    int v;
    modint(int x = 0) : v(x) { /* for debug only. assert(0 <= x && x < MOD); */ }
    inline int get() { return v; }
    modint operator-() const { return v ? MOD - v : 0; }
    modint operator+(const modint &k) const { return Modint::add(v, k.v); }
    modint operator-(const modint &k) const { return Modint::sub(v, k.v); }
    modint operator*(const modint &k) const { return Modint::mul(v, k.v); }
    modint operator/(const modint &k) const { return Modint::mul(v, Modint::inv(k.v)); }
    modint pow(const modint &k) const { return Modint::pow(v, k.v); }
    modint inverse() const { return Modint::inv(v); }
    modint operator+=(const modint &k)
    {
        (v += k.v) >= MOD && (v -= MOD);
        return *this;
    }
    modint operator-=(const modint &k)
    {
        (v -= k.v) < 0 && (v += MOD);
        return *this;
    }
    modint operator*=(const modint &k) { return v = Modint::mul(v, k.v); }
    modint operator/=(const modint &k) { return v = Modint::mul(v, Modint::inv(k.v)); }
};

struct Node
{
    int f;
    modint g;
    long long len;
    Node() {}
    Node(int F, int G, long long L) : f(F), g(G), len(L) {}
    Node(int F, modint G, long long L) : f(F), g(G), len(L) {}
};
std::deque<Node> Q;

#define MAXN 3000001
int a[MAXN];
void solve()
{
    int N = read<int>();
    long long p = 0, l = 0, r = 0, v = 0;
    for (int i = 1; i <= N; ++i)
        p += (a[i] = read<int>());
    for (int i = 1; i <= N; ++i)
        assert(std::abs(a[i]) <= p);
    Q.clear();
    Q.push_back(Node(0, 1, 1)), Q.push_back(Node(1, 1, p));
    modint gv = 1, gz = p % MOD, tv = 0, tz = 0;
    for (int i = 1; i <= N; ++i)
        if (a[i] >= 0)
        {
            for (long long ls = a[i]; ls > 0;)
            {
                Node k = Q.back();
                Q.pop_back();
                if (ls < k.len)
                    Q.push_back(Node(k.f, k.g, k.len - ls)), k.len = ls;
                (k.f == v ? gv : gz) -= k.g * (k.len % MOD), ls -= k.len;
            }
            l += a[i], r = std::min(r + a[i], p);
            if (l > r)
                ++v, l = a[i], r = p, gv = gz, tv = tz, gz = tz = 0;
            gz += -tz * (a[i] >= MOD ? a[i] - MOD : a[i]);
            if (a[i] > 0)
                Q.push_front(Node(v + 1, -tz, a[i]));
            tz += gv + tv * ((r - l + 1) % MOD);
        }
        else if (a[i] < 0)
        {
            a[i] = -a[i];
            for (long long ls = a[i]; ls > 0;)
            {
                Node k = Q.front();
                Q.pop_front();
                if (ls < k.len)
                    Q.push_front(Node(k.f, k.g, k.len - ls)), k.len = ls;
                (k.f == v ? gv : gz) -= k.g * (k.len % MOD), ls -= k.len;
            }
            r -= a[i], l = std::max(l - a[i], 0ll);
            if (l > r)
                ++v, l = 0, r = p - a[i], gv = gz, tv = tz, gz = tz = 0;
            gz += -tz * (a[i] >= MOD ? a[i] - MOD : a[i]), Q.push_back(Node(v + 1, -tz, a[i])), tz += gv + tv * ((r - l + 1) % MOD);
        }
    print<int>((Q.back().g + (r == p ? tv : tz)).get(), '\n');
}
int main()
{
    int T = read<int>();
    while (T--)
        solve();
    return 0;
}