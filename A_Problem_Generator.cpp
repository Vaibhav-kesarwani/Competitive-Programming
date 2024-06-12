#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n, m;
    std::cin >> n >> m;

    std::string S;
    std::cin >> S;

    int cnt[7]{};
    for (auto c : S)
    {
        cnt[c - 'A']++;
    }
    int ans = 0;
    for (int i = 0; i < 7; i++)
    {
        ans += std::max(0, m - cnt[i]);
    }
    std::cout << ans << "\n";
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
