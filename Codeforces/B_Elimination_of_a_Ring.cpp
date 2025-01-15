
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
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
        }
        bool c = true;
        for (int i = 0; i < n; i++)
        {
            if (a[i] != a[i % 2])
            {
                c = false;
                break;
            }
        }
        if (c)
        {
            cout << n / 2 + 1 << '\n';
        }
        else
        {
            cout << n << '\n';
        }
    }
    return 0;
}
