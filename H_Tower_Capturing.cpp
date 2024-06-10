#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

template <typename T>
T inverse(T a, T m)
{
    T u = 0, v = 1;
    while (a != 0)
    {
        T t = m / a;
        m -= t * a;
        swap(a, m);
        u -= t * v;
        swap(u, v);
    }
    assert(m == 1);
    return u;
}

template <typename T>
class Modular
{
public:
    using Type = typename decay<decltype(T::value)>::type;

    constexpr Modular() : value() {}
    template <typename U>
    Modular(const U &x)
    {
        value = normalize(x);
    }

    template <typename U>
    static Type normalize(const U &x)
    {
        Type v;
        if (-mod() <= x && x < mod())
            v = static_cast<Type>(x);
        else
            v = static_cast<Type>(x % mod());
        if (v < 0)
            v += mod();
        return v;
    }

    const Type &operator()() const { return value; }
    template <typename U>
    explicit operator U() const { return static_cast<U>(value); }
    constexpr static Type mod() { return T::value; }

    Modular &operator+=(const Modular &other)
    {
        if ((value += other.value) >= mod())
            value -= mod();
        return *this;
    }
    Modular &operator-=(const Modular &other)
    {
        if ((value -= other.value) < 0)
            value += mod();
        return *this;
    }
    template <typename U>
    Modular &operator+=(const U &other) { return *this += Modular(other); }
    template <typename U>
    Modular &operator-=(const U &other) { return *this -= Modular(other); }
    Modular &operator++() { return *this += 1; }
    Modular &operator--() { return *this -= 1; }
    Modular operator++(int)
    {
        Modular result(*this);
        *this += 1;
        return result;
    }
    Modular operator--(int)
    {
        Modular result(*this);
        *this -= 1;
        return result;
    }
    Modular operator-() const { return Modular(-value); }

    template <typename U = T>
    typename enable_if<is_same<typename Modular<U>::Type, int>::value, Modular>::type &operator*=(const Modular &rhs)
    {
        value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));
        return *this;
    }
    template <typename U = T>
    typename enable_if<is_same<typename Modular<U>::Type, long long>::value, Modular>::type &operator*=(const Modular &rhs)
    {
        long long q = static_cast<long long>(static_cast<long double>(value) * rhs.value / mod());
        value = normalize(value * rhs.value - q * mod());
        return *this;
    }
    template <typename U = T>
    typename enable_if<!is_integral<typename Modular<U>::Type>::value, Modular>::type &operator*=(const Modular &rhs)
    {
        value = normalize(value * rhs.value);
        return *this;
    }

    Modular &operator/=(const Modular &other) { return *this *= Modular(inverse(other.value, mod())); }

    friend const Type &abs(const Modular &x) { return x.value; }

    template <typename U>
    friend bool operator==(const Modular<U> &lhs, const Modular<U> &rhs);

    template <typename U>
    friend bool operator<(const Modular<U> &lhs, const Modular<U> &rhs);

    template <typename V, typename U>
    friend V &operator>>(V &stream, Modular<U> &number);

private:
    Type value;
};

template <typename T>
bool operator==(const Modular<T> &lhs, const Modular<T> &rhs) { return lhs.value == rhs.value; }
template <typename T, typename U>
bool operator==(const Modular<T> &lhs, U rhs) { return lhs == Modular<T>(rhs); }
template <typename T, typename U>
bool operator==(U lhs, const Modular<T> &rhs) { return Modular<T>(lhs) == rhs; }

template <typename T>
bool operator!=(const Modular<T> &lhs, const Modular<T> &rhs) { return !(lhs == rhs); }
template <typename T, typename U>
bool operator!=(const Modular<T> &lhs, U rhs) { return !(lhs == rhs); }
template <typename T, typename U>
bool operator!=(U lhs, const Modular<T> &rhs) { return !(lhs == rhs); }

template <typename T>
bool operator<(const Modular<T> &lhs, const Modular<T> &rhs) { return lhs.value < rhs.value; }

template <typename T>
Modular<T> operator+(const Modular<T> &lhs, const Modular<T> &rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U>
Modular<T> operator+(const Modular<T> &lhs, U rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U>
Modular<T> operator+(U lhs, const Modular<T> &rhs) { return Modular<T>(lhs) += rhs; }

template <typename T>
Modular<T> operator-(const Modular<T> &lhs, const Modular<T> &rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U>
Modular<T> operator-(const Modular<T> &lhs, U rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U>
Modular<T> operator-(U lhs, const Modular<T> &rhs) { return Modular<T>(lhs) -= rhs; }

template <typename T>
Modular<T> operator*(const Modular<T> &lhs, const Modular<T> &rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U>
Modular<T> operator*(const Modular<T> &lhs, U rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U>
Modular<T> operator*(U lhs, const Modular<T> &rhs) { return Modular<T>(lhs) *= rhs; }

template <typename T>
Modular<T> operator/(const Modular<T> &lhs, const Modular<T> &rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U>
Modular<T> operator/(const Modular<T> &lhs, U rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U>
Modular<T> operator/(U lhs, const Modular<T> &rhs) { return Modular<T>(lhs) /= rhs; }

template <typename T, typename U>
Modular<T> power(const Modular<T> &a, const U &b)
{
    assert(b >= 0);
    Modular<T> x = a, res = 1;
    U p = b;
    while (p > 0)
    {
        if (p & 1)
            res *= x;
        x *= x;
        p >>= 1;
    }
    return res;
}

template <typename T>
bool IsZero(const Modular<T> &number)
{
    return number() == 0;
}

template <typename T>
string to_string(const Modular<T> &number)
{
    return to_string(number());
}

// U == std::ostream? but done this way because of fastoutput
template <typename U, typename T>
U &operator<<(U &stream, const Modular<T> &number)
{
    return stream << number();
}

// U == std::istream? but done this way because of fastinput
template <typename U, typename T>
U &operator>>(U &stream, Modular<T> &number)
{
    typename common_type<typename Modular<T>::Type, long long>::type x;
    stream >> x;
    number.value = Modular<T>::normalize(x);
    return stream;
}

/*
using ModType = int;

struct VarMod { static ModType value; };
ModType VarMod::value;
ModType& md = VarMod::value;
using Mint = Modular<VarMod>;
*/

constexpr int md = 998244353;
using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;

vector<Mint> fact(1, 1);
vector<Mint> inv_fact(1, 1);

Mint C(int n, int k)
{
    if (k < 0 || k > n)
    {
        return 0;
    }
    while ((int)fact.size() < n + 1)
    {
        fact.push_back(fact.back() * (int)fact.size());
        inv_fact.push_back(1 / fact.back());
    }
    return fact[n] * inv_fact[k] * inv_fact[n - k];
}

template <typename T>
struct TPoint
{
    T x;
    T y;
    int id;

    TPoint() : x(0), y(0), id(-1) {}
    TPoint(const T &x_, const T &y_) : x(x_), y(y_), id(-1) {}
    TPoint(const T &x_, const T &y_, int id_) : x(x_), y(y_), id(id_) {}

    static constexpr T eps = static_cast<T>(1e-9);

    inline TPoint operator+(const TPoint &rhs) const { return TPoint(x + rhs.x, y + rhs.y); }
    inline TPoint operator-(const TPoint &rhs) const { return TPoint(x - rhs.x, y - rhs.y); }
    inline TPoint operator*(const T &rhs) const { return TPoint(x * rhs, y * rhs); }
    inline TPoint operator/(const T &rhs) const { return TPoint(x / rhs, y / rhs); }

    friend T smul(const TPoint &a, const TPoint &b)
    {
        return a.x * b.x + a.y * b.y;
    }

    friend T vmul(const TPoint &a, const TPoint &b)
    {
        return a.x * b.y - a.y * b.x;
    }

    inline T abs2() const
    {
        return x * x + y * y;
    }

    inline bool operator<(const TPoint &rhs) const
    {
        return (y < rhs.y || (y == rhs.y && x < rhs.x));
    }

    inline bool is_upper() const
    {
        return (y > eps || (abs(y) <= eps && x > eps));
    }

    inline int cmp_polar(const TPoint &rhs) const
    {
        assert(abs(x) > eps || abs(y) > eps);
        assert(abs(rhs.x) > eps || abs(rhs.y) > eps);
        bool a = is_upper();
        bool b = rhs.is_upper();
        if (a != b)
        {
            return (a ? -1 : 1);
        }
        long long v = x * rhs.y - y * rhs.x;
        return (v > eps ? -1 : (v < -eps ? 1 : 0));
    }
};

using Point = TPoint<int64_t>;
// using Point = TPoint<long double>;

template <typename T>
string to_string(const TPoint<T> &p)
{
    return "(" + to_string(p.x) + ", " + to_string(p.y) + ")";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--)
    {
        int n;
        cin >> n;
        vector<Point> p(n);
        for (int i = 0; i < n; i++)
        {
            cin >> p[i].x >> p[i].y;
            p[i].id = i;
        }
        for (int i = 1; i < n; i++)
        {
            if (p[i] < p[0])
            {
                swap(p[0], p[i]);
            }
        }
        sort(p.begin() + 1, p.end(), [&](Point a, Point b)
             { return vmul(a - p[0], b - p[0]) > 0; });
        int sz = 1;
        for (int i = 1; i < n; i++)
        {
            while (sz > 1 && vmul(p[sz - 1] - p[sz - 2], p[i] - p[sz - 1]) < 0)
            {
                sz -= 1;
            }
            p[sz++] = p[i];
        }
        p.resize(sz);
        vector<int> pos(n, -1);
        for (int i = 0; i < sz; i++)
        {
            pos[p[i].id] = i;
        }
        if (pos[0] == -1 || pos[1] == -1)
        {
            cout << 0 << '\n';
            continue;
        }
        auto Check = [&](int i, int j, int k) -> bool
        {
            if (vmul(p[j] - p[i], p[k] - p[i]) < 0)
            {
                swap(j, k);
            }
            for (int t = 0; t < sz; t++)
            {
                if (t == i || t == j || t == k)
                {
                    continue;
                }
                auto a = p[i] - p[t];
                auto b = p[j] - p[t];
                auto c = p[k] - p[t];
                if (
                    (a.x * a.x + a.y * a.y) * (b.x * c.y - c.x * b.y) -
                        (b.x * b.x + b.y * b.y) * (a.x * c.y - c.x * a.y) +
                        (c.x * c.x + c.y * c.y) * (a.x * b.y - b.x * a.y) <
                    0)
                {
                    return false;
                }
            }
            return true;
        };
        auto Go = [&](auto &&self, int l, int r) -> pair<Mint, int>
        {
            int x = (l + 1) % sz;
            if (x == r)
            {
                return make_pair(1, 0);
            }
            while (x != r)
            {
                if (Check(l, r, x))
                {
                    auto g1 = self(self, l, x);
                    auto g2 = self(self, x, r);
                    auto ans = g1.first * g2.first * C(g1.second + g2.second, g1.second);
                    return make_pair(ans, g1.second + g2.second + 1);
                }
                x = (x + 1) % sz;
            }
            return make_pair(0, 0);
        };
        auto g1 = Go(Go, pos[0], pos[1]);
        auto g2 = Go(Go, pos[1], pos[0]);
        auto ans = g1.first * g2.first * C(g1.second + g2.second, g1.second);
        cout << ans << '\n';
    }
    return 0;
}
