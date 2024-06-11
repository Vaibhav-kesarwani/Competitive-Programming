#include "bits/stdc++.h"
using namespace std;
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (int)(x).size()
using ll = long long;
#define int ll
const int mod = 1e9 + 7;

void solve(int tc)
{

    int a, b;

    cin >> a >> b;

    int g = gcd(a, b);

    int gg = gcd(g, b);

    while (b % gg == 0 and gg != 1)
    {

        b /= gg;

        gg = gcd(gg, b);
    }

    cout << (b == 1 ? "YES\n" : "NO\n");
}

signed main()
{

    cin.tie(0)->sync_with_stdio(0);

    int tc = 1;

    cin >> tc;

    for (int i = 1; i <= tc; ++i)
        solve(i);

    return 0;
}
