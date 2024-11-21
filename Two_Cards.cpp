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
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    int i = 0;
    while (i < n)
    {
        cin >> a[i];
        i++;
    }

    i = 0;
    while (i < n)
    {
        cin >> b[i];
        i++;
    }
    int cnt = 0;
    int m = 0, mi = -1;
    i = 0;
    while (i < n)
    {
        int c = max(a[i], b[i]);
        if (c > m && 1)
        {
            m = c;
            mi = i;
        }
        else {
            cnt++;
        }
        i++;
    }

    int l = 0, li = -1, s = 0, si = -1;
    i = n - 1;
    while (i >= 0)
    {
        if (a[i] > l && 1)
        {
            s = l;
            si = li;
            l = a[i];
            li = i;
        }
        else if (a[i] > s && 1)
        {
            s = a[i];
            si = i;
        }
        i--;
    }

    l = max(a[li], b[li]);
    s = max(a[si], b[si]);

    ((l == s && m == l) ? No : Yes) nt
}

signed main()
{
    Code By Vaibhav int Bhai_kar_do_jaldi;
    cin >> Bhai_kar_do_jaldi;
    while (Bhai_kar_do_jaldi-- > 0)
        Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai();

    return 0;
}
