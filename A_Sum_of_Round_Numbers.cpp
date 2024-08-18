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
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int lcm(int a, int b) { return (a / gcd(a, b) * b); }

void Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai()
{
    int n;
    int aa[100000];
    int d = 0, rem = 0;
    cin >> n;
    if (n >= 1000)
    {
        rem = n % 1000;
        aa[d++] = n - rem;
        n %= 1000;
    }
    if (n >= 100)
    {
        rem = n % 100;
        aa[d++] = n - rem;
        n %= 100;
    }
    if (n >= 10)
    {
        rem = n % 10;
        aa[d++] = n - rem;
        n %= 10;
    }
    if (n < 10 && n > 0)
    {
        aa[d++] = n;
    }
    vector<int> va;
    for (int i = 0; i < d; i++)
    {
        va.push_back(aa[i]);
    }
    cout << va.size() << endl;
    for (int i = 0; i < va.size(); i++)
    {
        cout << va[i] << " ";
    }
    cout nt
}

signed main()
{
    Code By Vaibhav int Bhai_Test_Case_Hai_Ya;
    cin >> Bhai_Test_Case_Hai_Ya;
    while (Bhai_Test_Case_Hai_Ya-- > 0)
        Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai();

    return 0;
}