#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#else
#define debug(...) 42
#endif

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
        vector<vector<int>> g(n);
        for (int i = 0; i < n - 1; i++)
        {
            int x, y;
            cin >> x >> y;
            --x;
            --y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        if (n == 2)
        {
            cout << 2 << '\n';
            continue;
        }
        const int inf = int(1e9);
        vector<array<array<int, 2>, 2>> dp(n);
        auto Dfs = [&](auto &&self, int v, int pr) -> void
        {
            array<array<int, 2>, 2> aux;
            for (int x = 0; x < 2; x++)
            {
                for (int y = 0; y < 2; y++)
                {
                    aux[x][y] = (y == 0 ? x : -inf);
                }
            }
            bool any = false;
            for (int u : g[v])
            {
                if (u == pr)
                {
                    continue;
                }
                self(self, u, v);
                any = true;
                array<array<int, 2>, 2> new_aux;
                for (int x = 0; x < 2; x++)
                {
                    for (int y = 0; y < 2; y++)
                    {
                        new_aux[x][y] = -inf;
                    }
                }
                for (int x = 0; x < 2; x++)
                {
                    for (int y = 0; y < 2; y++)
                    {
                        for (int xx = 0; xx < 2; xx++)
                        {
                            for (int yy = 0; yy < 2; yy++)
                            {
                                if (x + xx > 1 || y + yy > 1)
                                {
                                    continue;
                                }
                                new_aux[x][y + yy] = max(new_aux[x][y + yy], aux[x][y] + dp[u][xx][yy]);
                            }
                        }
                    }
                }
                swap(aux, new_aux);
            }
            if (!any)
            {
                for (int x = 0; x < 2; x++)
                {
                    for (int y = 0; y < 2; y++)
                    {
                        dp[v][x][y] = (x == 0 || y == 0 ? x + y : -inf);
                    }
                }
            }
            else
            {
                dp[v] = aux;
            }
        };
        int root = 0;
        while (g[root].size() == 1)
        {
            root += 1;
        }
        Dfs(Dfs, root, -1);
        int ans = 0;
        for (int x = 0; x < 2; x++)
        {
            for (int y = 0; y < 2; y++)
            {
                ans = max(ans, dp[root][x][y]);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
