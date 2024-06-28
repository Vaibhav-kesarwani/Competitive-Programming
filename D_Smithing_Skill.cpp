#include <bits/stdc++.h>
using namespace std;
// #define int long long
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
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    int mx = *max_element(a.begin(), a.end());
    const int inf = int(1e9);
    vector<int> min_loss(mx + 1, inf);
    for (int i = 0; i < n; i++)
    {
        min_loss[a[i]] = min(min_loss[a[i]], a[i] - b[i]);
    }
    for (int i = 0; i < mx; i++)
    {
        min_loss[i + 1] = min(min_loss[i + 1], min_loss[i]);
    }
    vector<int> res(mx + 1);
    for (int i = 0; i <= mx; i++)
    {
        res[i] = (min_loss[i] <= i ? res[i - min_loss[i]] + 1 : 0);
    }
    int64_t ans = 0;
    for (int i = 0; i < m; i++)
    {
        int c;
        cin >> c;
        if (c > mx)
        {
            int diff = c - mx;
            int steps = (diff - 1) / min_loss[mx] + 1;
            ans += steps;
            c -= steps * min_loss[mx];
        }
        ans += res[c];
    }
    cout << 2 * ans nt
}

signed main()
{
    Code By Vaibhav
    // int Bhai_Test_Case_Hai_Ya; cin >> Bhai_Test_Case_Hai_Ya; while (Bhai_Test_Case_Hai_Ya-- > 0)
    Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai();

    return 0;
}