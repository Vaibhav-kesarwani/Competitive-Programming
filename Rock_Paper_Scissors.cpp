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
    int n;
    cin >> n;

    string str;
    cin >> str;

    map<char, int> last;
    last['R'] = n;
    last['P'] = n;
    last['S'] = n;

    vector<char> ans(n);
    ans[n - 1] = str[n - 1];
    last[str[n - 1]] = n - 1;

    for (int i = n - 2; i >= 0; i--)
    {
        if (str[i] == 'R')
        {
            if (last['P'] != n)
            {
                ans[i] = ans[last['P']];
            }
            else
                ans[i] = str[i];
        }
        if (str[i] == 'P')
        {
            if (last['S'] != n)
            {
                ans[i] = ans[last['S']];
            }
            else
                ans[i] = str[i];
        }
        if (str[i] == 'S')
        {
            if (last['R'] != n)
            {
                ans[i] = ans[last['R']];
            }
            else
                ans[i] = str[i];
        }
        last[str[i]] = i;
    }

    for (int i = 0; i < n; i++)
        cout << ans[i];
    cout << endl;
}

signed main()
{
    Code By Vaibhav int Bhai_Test_Case_Hai_Ya;
    cin >> Bhai_Test_Case_Hai_Ya;
    while (Bhai_Test_Case_Hai_Ya-- > 0)
        Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai();

    return 0;
}