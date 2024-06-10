#include <bits/stdc++.h>

using i64 = long long;

std::pair<int, int> query(int d)
{
    std::cout << "? " << d << std::endl;
    int v, w;
    std::cin >> v >> w;
    return std::make_pair(v, w);
}

void solve()
{
    int n;
    std::cin >> n;

    std::deque<int> a;
    auto rec = [&](auto &&self, int n)
    {
        if (n == 2)
        {
            int x = query(0).first;
            int y = query(0).first;
            a = {x, y};
            return;
        }
        if (n == 1)
        {
            int x = query(0).first;
            a = {x};
            return;
        }
        auto [x, y] = query(n - 2);
        if (y == 0)
        {
            int z = query(0).first;
            self(self, n - 2);
            a.push_back(x);
            a.push_back(z);
        }
        else
        {
            self(self, n - 1);
            if (a[0] == y)
            {
                a.push_back(x);
            }
            else
            {
                a.push_front(x);
            }
        }
    };
    rec(rec, n);
    std::cout << "!";
    for (int i = 0; i < n; i++)
    {
        std::cout << " " << a[i];
    }
    std::cout << std::endl;
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