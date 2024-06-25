#include <bits/stdc++.h>
using namespace std;
#define int long long
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(0);
#define Vaibhav cout.tie(0);
#define nt << "\n";
#define yes cout << "YES" nt
#define no cout << "NO" nt
const long double pi = 3.141592653589793238;
const int INF = LONG_LONG_MAX;
const int mod = 1000000007;
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int lcm(int a, int b) { return (a / gcd(a, b) * b); }

void Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai()
{
    int a, b, n, m;
    cin >> a >> b >> n >> m;

    set<pair<int, int>> xy, yx;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        xy.emplace(x, y);
        yx.emplace(y, x);
    }

    int u = 1, d = a, l = 1, r = b;
    vector<int> ans(2);

    for (int i = 0; i < m; i++)
    {
        char ch;
        int k;
        cin >> ch >> k;

        if (ch == 'U')
        {
            u += k;
            while (!xy.empty())
            {
                auto [x, y] = *xy.begin();
                if (x >= u)
                {
                    break;
                }
                xy.erase({x, y});
                yx.erase({y, x});
                ans[i % 2]++;
            }
        }
        else if (ch == 'D')
        {
            d -= k;
            while (!xy.empty())
            {
                auto [x, y] = *xy.rbegin();
                if (x <= d)
                {
                    break;
                }
                xy.erase({x, y});
                yx.erase({y, x});
                ans[i % 2]++;
            }
        }
        else if (ch == 'L')
        {
            l += k;
            while (!xy.empty())
            {
                auto [y, x] = *yx.begin();
                if (y >= l)
                {
                    break;
                }
                xy.erase({x, y});
                yx.erase({y, x});
                ans[i % 2]++;
            }
        }
        else if (ch == 'R')
        {
            r -= k;
            while (!xy.empty())
            {
                auto [y, x] = *yx.rbegin();
                if (y <= r)
                {
                    break;
                }
                xy.erase({x, y});
                yx.erase({y, x});
                ans[i % 2]++;
            }
        }
    }

    cout << ans[0] << ' ' << ans[1] nt
}

signed main()
{
    Code By Vaibhav int Bhai_Test_Case_Hai_Ya;
    cin >> Bhai_Test_Case_Hai_Ya;
    while (Bhai_Test_Case_Hai_Ya-- > 0)
        Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai();

    return 0;
}