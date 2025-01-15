#include <bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
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
int a[1003];
signed main()
{
    int n = read();
    for (int i = 1; i <= n; ++i)
        a[i] = read();
    vector<pair<int, int>> ans;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j < n; ++j)
            if (a[j] < a[j + 1])
                swap(a[j], a[j + 1]),
                    ans.push_back({a[j], a[j + 1]});
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j < n; ++j)
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]),
                    ans.push_back({a[j], a[j + 1]});
    reverse(ans.begin(), ans.end());
    printf("%lld\n", (int)ans.size());
    for (auto [x, y] : ans)
        printf("%lld %lld\n", y, x);
    return 0;
}