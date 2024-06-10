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
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            --a[i];
        }
        if (is_sorted(a.begin(), a.end()))
        {
            cout << n << '\n';
            cout << 0 << '\n';
            continue;
        }
        { // n-1?
            auto b = a;
            bool found = false;
            for (int i = 1; i < n; i++)
            {
                rotate(b.begin(), b.begin() + 1, b.end());
                if (is_sorted(b.begin(), b.end()))
                {
                    cout << n - 1 << '\n';
                    cout << i << '\n';
                    for (int j = 0; j < i; j++)
                    {
                        cout << "2 1" << '\n';
                    }
                    found = true;
                    break;
                }
            }
            if (found)
            {
                continue;
            }
        }
        vector<pair<int, int>> ops;
        int inv = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (a[i] > a[j])
                {
                    inv += 1;
                }
            }
        }
        int k = n - 2;
        if (inv % 2 == 1 && n % 2 == 0)
        {
            k = n - 3;
        }
        auto Do = [&](int x, int y)
        {
            ops.emplace_back(x, y);
            assert(x != y && 0 <= x && x <= n - k && 0 <= y && y <= n - k);
            vector<int> b(a.begin() + x, a.begin() + x + k);
            a.erase(a.begin() + x, a.begin() + x + k);
            a.insert(a.begin() + y, b.begin(), b.end());
        };
        if (k == n - 3)
        {
            if (a[n - 1] != n - 1)
            {
                if (a[n - 2] == n - 1)
                {
                    Do(1, 2);
                    assert(a[n - 2] != n - 1);
                }
                while (a[2] != n - 1)
                {
                    Do(1, 0);
                }
                Do(3, 2);
                assert(a[n - 1] == n - 1);
            }
            n -= 1;
        }
        assert(k == n - 2);
        for (int val = 1; val < n; val++)
        {
            int pos = int(find(a.begin(), a.end(), val) - a.begin());
            if (a[(pos + n - 1) % n] == val - 1)
            {
                continue;
            }
            while (a[0] != val && a[n - 1] != val)
            {
                Do(2, 0);
            }
            if (a[0] == val)
            {
                while (a[n - 1] != val - 1)
                {
                    Do(2, 1);
                }
            }
            else
            {
                while (a[n - 2] != val - 1)
                {
                    Do(1, 0);
                }
            }
        }
        while (a[0] != 0)
        {
            Do(2, 0);
        }
        assert(ops.size() <= 5 * a.size() * a.size());
        assert(is_sorted(a.begin(), a.end()));
        cout << k << '\n';
        cout << ops.size() << '\n';
        for (auto &op : ops)
        {
            cout << op.first + 1 << " " << op.second + 1 << '\n';
        }
    }
    return 0;
}
