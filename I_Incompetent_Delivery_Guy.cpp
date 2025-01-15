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
vector<pair<int, int>> e[1 << 19], g[1 << 19];
bool from_one[1 << 19];
void dfs_one(int x)
{
    // printf("%lld\n",x);
    from_one[x] = 1;
    for (auto [y, z] : g[x])
        if (!from_one[y])
            dfs_one(y);
}
bool vis[1 << 19];
priority_queue<pair<int, int>> q;
int d[1 << 19];
bool bad[1 << 19];
int dep[1 << 19];
int p[1 << 19];
int outs[1 << 19];
signed main()
{
    int n = read(), m = read();
    for (int i = 1, u, v, w; i <= m; ++i)
    {
        u = read(), v = read(), w = read();
        if (u == n)
            continue;
        g[u].push_back({v, w}),
            e[v].push_back({u, w});
    }
    dfs_one(1);
    if (!from_one[n])
        puts("-1"), exit(0);
    q.push({0, n});
    memset(d, 0x3f, sizeof(d));
    d[n] = 0;
    while (!q.empty())
    {
        auto [_, x] = q.top();
        q.pop();
        if (vis[x])
            continue;
        vis[x] = 1;
        for (auto [y, z] : e[x])
            if (d[y] > d[x] + z)
            {
                d[y] = d[x] + z;
                q.push({-d[y], y});
            }
    }
    memset(dep, 0x3f, sizeof(dep));
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; ++i)
        if (d[i] < 1e18)
            for (auto [j, k] : g[i])
                outs[i] += (d[i] == d[j] + k);
    for (int i = 1; i <= n; ++i)
        if (d[i] > 1e18)
        {
            dep[i] = 0;
            q.push({0, i});
        }
    while (!q.empty())
    {
        auto [_, x] = q.top();
        q.pop();
        if (vis[x])
            continue;
        vis[x] = 1;
        // printf("search %lld\n",x);
        for (auto [y, z] : e[x])
        {
            if (d[y] == d[x] + z)
            {
                // puts("wow");
                // printf("spe %lld\n",y);
                if (!--outs[y])
                    z = 0;
                else
                    z = 1;
            }
            else
            {
                z = 1;
            }
            if (dep[y] > dep[x] + z)
            {
                dep[y] = dep[x] + z;
                q.push({-dep[y], y});
            }
        }
    }
    printf("%lld\n", min(dep[1] - 1, n));
    return 0;
}