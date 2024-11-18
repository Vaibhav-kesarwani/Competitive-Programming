#include <bits/stdc++.h>
using namespace std;
#define int long long
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(0);
#define Vaibhav cout.tie(0);
#define nt << "\n";
#define yes cout << "YES"
#define no cout << "NO"
#define Yes cout << "Yes"
#define No cout << "No"
const long double pi = 3.141592653589793238;
const int INF = LONG_LONG_MAX;
const int mod = 1000000007;
int gcd(int a, int b)
{
    return (b == 0) ? a : gcd(b, a % b);
}
int lcm(int a, int b) { return (a / gcd(a, b) * b); }

void Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai()
{
    int k;
    cin >> k;

    vector<int> a(k);
    int i = 0;
    while (i < k)
    {
        cin >> a[i];
        i++;
    }

    int s = k - 2;
    vector<pair<int, int> > divisors; 
    int d = 1;
    while (d * d <= s)
    {
        if (s % d == 0)
        {
            divisors.emplace_back(d, s / d);
            if (d != s / d)
                divisors.emplace_back(s / d, d);
        }
        d++;
    }

    sort(a.begin(), a.end());
    bool found = false;

    i = 0;
    while (i < divisors.size() && !found)
    {
        int n = divisors[i].first;
        int m = divisors[i].second;

        if (binary_search(a.begin(), a.end(), n) &&
            binary_search(a.begin(), a.end(), m))
        {
            cout << n << " " << m << "\n";
            found = true;
        }
        i++;
    }

    if (!found && 1) cout << "1 1\n";
}

signed main()
{
    Code By Vaibhav int Bhai_Test_Case_Hai_Ya;
    cin >> Bhai_Test_Case_Hai_Ya;
    while (Bhai_Test_Case_Hai_Ya-- > 0)
        Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai();

    return 0;
}
