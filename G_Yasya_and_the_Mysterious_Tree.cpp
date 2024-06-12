#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 1E7;

int trie[N][2];
int cnt[N][2];

int tot = 0;
int newNode()
{
    int x = ++tot;
    trie[x][0] = trie[x][1] = 0;
    cnt[x][0] = cnt[x][1] = 0;
    return x;
}

void add(int x, int d, int t = 1)
{
    int p = 1;
    cnt[p][d] += t;
    for (int i = 29; i >= 0; i--)
    {
        int u = x >> i & 1;
        if (!trie[p][u])
        {
            trie[p][u] = newNode();
        }
        p = trie[p][u];
        cnt[p][d] += t;
    }
}

int query(int x, int d)
{
    int p = 1;
    if (!cnt[p][d])
    {
        return 0;
    }
    int ans = 0;
    for (int i = 29; i >= 0; i--)
    {
        int u = x >> i & 1;
        if (cnt[trie[p][u ^ 1]][d])
        {
            ans |= 1 << i;
            p = trie[p][u ^ 1];
        }
        else
        {
            p = trie[p][u];
        }
    }
    return ans;
}

void solve()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<std::pair<int, int>>> adj(n);
    for (int i = 1; i < n; i++)
    {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--, v--;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    std::vector<int> a(n), d(n);
    auto dfs = [&](auto &&self, int x, int p) -> void
    {
        for (auto [y, w] : adj[x])
        {
            if (y == p)
            {
                continue;
            }
            d[y] = d[x] ^ 1;
            a[y] = a[x] ^ w;
            self(self, y, x);
        }
    };
    dfs(dfs, 0, -1);

    tot = 0;
    newNode();
    for (int i = 0; i < n; i++)
    {
        add(a[i], d[i]);
    }

    int w = 0;
    while (m--)
    {
        char o;
        std::cin >> o;

        if (o == '^')
        {
            int y;
            std::cin >> y;
            w ^= y;
        }
        else
        {
            int v, x;
            std::cin >> v >> x;
            v--;
            add(a[v], d[v], -1);
            int ans = std::max(query(a[v] ^ x, d[v]), query(a[v] ^ x ^ w, d[v] ^ 1));
            add(a[v], d[v]);
            std::cout << ans << " ";
        }
    }
    std::cout << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
