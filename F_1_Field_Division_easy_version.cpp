#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<std::array<int, 3>> f(k);
    for (int i = 0; i < k; i++)
    {
        int r, c;
        std::cin >> r >> c;
        c--;
        f[i] = {c, r, i};
    }
    std::sort(f.begin(), f.end());

    i64 ans = 0;
    std::vector<i64> a(k);
    int x = 0, y = 0;
    std::vector<int> v(k);
    for (auto [c, r, i] : f)
    {
        if (r > x)
        {
            ans += 1LL * (r - x) * c;
            x = r;
            y = c;
            v[i] = 1;
        }
    }
    ans += 1LL * (n - x) * m;

    for (int j = 0; j < k; j++)
    {
        auto [c, r, i] = f[j];
        if (!v[i])
        {
            continue;
        }
        int L = j - 1, R = j + 1;
        while (L >= 0 && !v[f[L][2]])
        {
            L--;
        }
        while (R < k && !v[f[R][2]])
        {
            R++;
        }
        int x = L >= 0 ? f[L][1] : 0;
        int y = L >= 0 ? f[L][0] : 0;
        int rx = R < k ? f[R][1] : n;
        int ry = R < k ? f[R][0] : m;
        i64 res = 0;
        res -= 1LL * (r - x) * c;
        res -= 1LL * (rx - r) * ry;
        for (int u = j + 1; u < R; u++)
        {
            auto [c, r, _] = f[u];
            if (r > x)
            {
                res += 1LL * (r - x) * c;
                x = r;
                y = c;
            }
        }
        res += 1LL * (rx - x) * ry;
        a[i] = res;
    }
    std::cout << ans << "\n";
    for (int i = 0; i < k; i++)
    {
        std::cout << a[i] << " \n"[i == k - 1];
    }
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
