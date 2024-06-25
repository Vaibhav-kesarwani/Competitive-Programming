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
    int m, X;
    cin >> m >> X;

    vector<int> dp(1);

    for (int i = 0, sum = 0; i < m; i++)
    {
        int c, h;
        cin >> c >> h;
        sum += h;
        dp.resize(sum + 1, -1);

        for (int j = sum; j >= h; j--)
        {
            if (dp[j - h] >= c)
            {
                dp[j] = max(dp[j], dp[j - h] - c);
            }
        }

        for (int j = 0; j <= sum; j++)
        {
            if (dp[j] >= 0)
            {
                dp[j] += X;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < dp.size(); i++)
    {
        if (dp[i] >= 0)
        {
            ans = i;
        }
    }

    cout << ans nt
}

signed main()
{
    Code By Vaibhav int Bhai_Test_Case_Hai_Ya;
    cin >> Bhai_Test_Case_Hai_Ya;
    while (Bhai_Test_Case_Hai_Ya-- > 0)
        Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai();

    return 0;
}