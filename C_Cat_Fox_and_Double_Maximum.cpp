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
    vector<int> p(n);
    for (int i = 0; i < n; i++)
        cin >> p[i];
    vector<int> q(n);
    int nid = find(p.begin(), p.end(), n) - p.begin();
    if (!(nid & 1)) // maximums will be on the even positions
    {
        vector<pair<int, int>> v;
        for (int i = 1; i < n; i += 2)
            v.push_back({p[i], i});
        v.push_back({p[0], 0});
        for (int i = 2; i < n; i += 2)
            v.push_back({p[i], i});
        sort(v.begin(), v.begin() + (n / 2), greater<pair<int, int>>());
        sort(v.begin() + (n / 2) + 1, v.begin() + n, greater<pair<int, int>>());
        for (int i = 0; i < n; i++)
            q[v[i].second] = i + 1;
    }
    else // maximums will be on the odd positions
    {
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i += 2)
            v.push_back({p[i], i});
        v.push_back({p[n - 1], n - 1});
        for (int i = 1; i < n - 1; i += 2)
            v.push_back({p[i], i});
        sort(v.begin(), v.begin() + (n / 2), greater<pair<int, int>>());
        sort(v.begin() + (n / 2) + 1, v.begin() + n, greater<pair<int, int>>());
        for (int i = 0; i < n; i++)
            q[v[i].second] = i + 1;
    }
    for (int i = 0; i < n; i++)
        cout << q[i] << " \n"[i == n - 1];
}

signed main()
{
    Code By Vaibhav int Bhai_Test_Case_Hai_Ya;
    cin >> Bhai_Test_Case_Hai_Ya;
    while (Bhai_Test_Case_Hai_Ya-- > 0)
        Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai();

    return 0;
}