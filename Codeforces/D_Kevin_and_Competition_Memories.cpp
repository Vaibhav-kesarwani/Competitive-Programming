#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

constexpr int inf = 1E9;

void solve()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        a[i] = std::max(a[i], a[0]);
    }
    std::sort(a.begin(), a.end());

    std::vector<int> b(m);
    for (int i = 0; i < m; i++)
    {
        std::cin >> b[i];
        if (b[i] <= a[0])
        {
            b[i] = inf + 1;
        }
    }
    std::sort(b.begin(), b.end(), std::greater());
    for (int i = 0; i < m; i++)
    {
        b[i] = a.end() - std::lower_bound(a.begin(), a.end(), b[i]);
    }

    for (int k = 1; k <= m; k++)
    {
        i64 ans = 0;
        for (int i = k - 1; i < m; i += k)
        {
            ans += b[i] + 1;
        }
        std::cout << ans << " \n"[k == m];
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