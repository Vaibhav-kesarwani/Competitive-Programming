#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{

    // your code goes here

    int len;
    cin >> len;

    vector<int> v(len);

    for (int i = 0; i < len; i++)
        cin >> v[i];

    int res = 0, cnt = 0;

    for (int i = 0; i < len; i++)
    {

        if (v[i] == 1)
            cnt++;

        if (v[i] == 1)
            continue;

        int rt = 10;

        rt = rt + (i * i);

        int rg = 31;

        for (int j = 1; j <= min(rg, len); j++)
            res = res + (v[j - 1] >= pow(v[i], j));
    }

    res = (len * cnt) + res;

    cout << res << endl;
}

signed main()
{

    ios_base::sync_with_stdio(0);

    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)

        solve();

    return 0;
}
