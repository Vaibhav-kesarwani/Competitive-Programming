#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n, m;
    std::cin >> n >> m;

    std::vector a(n, std::vector<int>(m)), b(n, std::vector<int>(m));
    std::vector<int> row(n * m), col(n * m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cin >> a[i][j];
            a[i][j]--;
            row[a[i][j]] = i;
            col[a[i][j]] = j;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cin >> b[i][j];
            b[i][j]--;
        }
    }
    for (int i = 0; i < n; i++)
    {
        int r = row[b[i][0]];
        std::swap(a[i], a[r]);
        for (int j = 0; j < m; j++)
        {
            row[a[i][j]] = i;
            row[a[r][j]] = r;
        }
    }
    for (int j = 0; j < m; j++)
    {
        int c = col[b[0][j]];
        for (int i = 0; i < n; i++)
        {
            std::swap(a[i][c], a[i][j]);
            col[a[i][j]] = j;
            col[a[i][c]] = c;
        }
    }
    if (a == b)
    {
        std::cout << "YES\n";
    }
    else
    {
        std::cout << "NO\n";
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
