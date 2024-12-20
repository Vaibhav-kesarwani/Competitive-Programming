#include <bits/stdc++.h>
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
string a;

void check(string a)
{
    int sz = a.size();
    int p = -1;
    for (int i = 0; i < sz; ++i)
        if (a[i] == '=')
            p = i;
    if (p == 0 || p == sz - 1)
        return;
    int cur = 0, flg = 1, ls = 0, rs = 0;
    // printf("%d\n",p);
    for (int i = 0; i + 1 < sz; ++i)
        if (!isdigit(a[i]) && !isdigit(a[i + 1]))
            return;
    if (!isdigit(a[0]) || !isdigit(a[sz - 1]))
        return;
    for (int i = 0; i < sz; ++i)
    {
        if ((i == 0 || !isdigit(a[i - 1])) && a[i] == '0')
        {
            if (i + 1 < sz && isdigit(a[i + 1]))
                return;
        }
    }
    // puts("here");
    for (int i = 0; i < p; ++i)
    {
        if (isdigit(a[i]))
        {
            cur = cur * 10 + (a[i] & 15);
            if (cur > 9999999999ll)
                return;
        }
        else
        {
            ls += cur * flg;
            if (cur > 9999999999ll)
                return;
            cur = 0;
            if (a[i] == '-')
                flg = -1;
            else
                flg = 1;
        }
    }
    ls += cur * flg, cur = 0, flg = 1;
    for (int i = p + 1; i < sz; ++i)
    {
        if (isdigit(a[i]))
        {
            cur = cur * 10 + (a[i] & 15);
            if (cur > 9999999999ll)
                return;
        }
        else
        {
            rs += cur * flg;
            if (cur > 9999999999ll)
                return;
            cur = 0;
            if (a[i] == '-')
                flg = -1;
            else
                flg = 1;
        }
    }
    rs += cur * flg;
    // printf("%lld %lld\n",ls,rs);
    if (ls == rs)
    {
        if (a == ::a)
        {
            puts("Correct");
            exit(0);
        }
        cout << a << endl, exit(0);
    }
    return;
}
signed main()
{
    cin >> a;
    check(a);
    int sz = a.size();
    for (int i = 0; i < sz; ++i)
        if (isdigit(a[i]))
        {
            string b = a;
            for (int j = i; j + 1 < sz; ++j)
                swap(b[j], b[j + 1]), check(b);
            b = a;
            for (int j = i; j - 1 >= 0; --j)
                swap(b[j], b[j - 1]), check(b);
        }
    puts("Impossible");
    return 0;
}