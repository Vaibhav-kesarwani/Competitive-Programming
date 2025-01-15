#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
#define int long long
inline int read()
{
    int s = 0, w = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
        s = s * 10 + ch - '0', ch = getchar();
    return s * w;
}
const int p = 998244353;
int qp(int x, int y)
{
    int res = 1;
    for (int t = x; y; y >>= 1, t = 1ll * t * t % p)
        if (y & 1)
            res = 1ll * res * t % p;
    return res;
}
int X1[1 << 13], Y1[1 << 13], X2[1 << 13], Y2[1 << 13];
bool X[1 << 26], Y[1 << 26];
signed main()
{
    for (int T = read(); T--;)
    {
        int n = read(), m = read();
        int n1 = read(), m1 = read(), x1 = read(), y1 = read(), dx1 = read(), dy1 = read();
        int n2 = read(), m2 = read(), x2 = read(), y2 = read(), dx2 = read(), dy2 = read();
        int A = (n - n1) * (n - n2) * 2;
        int B = (m - m1) * (m - m2) * 2;
        for (int i = 0; i < A; ++i)
        {
            if (dx1 == 1)
            {
                if (x1 == n - n1)
                    dx1 = -1;
            }
            else
            {
                if (x1 == 0)
                    dx1 = 1;
            }
            x1 += dx1;
            if (dx2 == 1)
            {
                if (x2 == n - n2)
                    dx2 = -1;
            }
            else
            {
                if (x2 == 0)
                    dx2 = 1;
            }
            x2 += dx2;
            if (x1 + n1 <= x2 || x2 + n2 <= x1)
                X[i] = 0;
            else
                X[i] = 1;
        }
        for (int i = 0; i < B; ++i)
        {
            if (dy1 == 1)
            {
                if (y1 == m - m1)
                    dy1 = -1;
            }
            else
            {
                if (y1 == 0)
                    dy1 = 1;
            }
            y1 += dy1;
            if (dy2 == 1)
            {
                if (y2 == m - m2)
                    dy2 = -1;
            }
            else
            {
                if (y2 == 0)
                    dy2 = 1;
            }
            y2 += dy2;
            if (y1 + m1 <= y2 || y2 + m2 <= y1)
                Y[i] = 0;
            else
                Y[i] = 1;
            // cout<<Y[i];
        }
        // puts("");
        int g = __gcd(A, B);
        int fm = A * B / g;
        int fz = 0;
        for (int i = 0; i < g; ++i)
        {
            int P = 0, Q = 0;
            for (int j = i; j < A; j += g)
                P += X[j];
            for (int j = i; j < B; j += g)
                Q += Y[j];
            fz += P * Q;
        }
        g = __gcd(fz, fm);
        printf("%lld/%lld\n", fz / g, fm / g);
    }
    return 0;
}