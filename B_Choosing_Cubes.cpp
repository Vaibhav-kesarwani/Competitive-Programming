#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n, f, k;
    std::cin >> n >> f >> k;
    f--;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }

    int gt = 0, eq = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > a[f])
        {
            gt++;
        }
        else if (a[i] == a[f])
        {
            eq++;
        }
    }
    if (k <= gt)
    {
        std::cout << "NO\n";
    }
    else if (k >= gt + eq)
    {
        std::cout << "YES\n";
    }
    else
    {
        std::cout << "MAYBE\n";
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
