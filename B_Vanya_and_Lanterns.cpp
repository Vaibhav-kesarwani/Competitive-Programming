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
int gcd(int a, int b){if (b == 0)return a;return gcd(b, a % b);}
int lcm(int a, int b){return (a/gcd(a,b)*b);}


void Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai() {
    int n, l, r;
    cin >> n >> l;
    int p[n];

    for (int i = 0; i < n; i++)
        cin >> p[i];

    sort(p, p + n);
    r = max(p[0], l - p[n - 1]) * 2;

    for (int i = 0; i < n - 1; i++)
        r = max(r, p[i + 1] - p[i]);

    cout.precision(20);
    cout << fixed << r / 2.0 << endl;
}

signed main () {
    Code By Vaibhav
    // int Bhai_Test_Case_Hai_Ya; cin >> Bhai_Test_Cse_Hai_Ya; while (Bhai_Test_Case_Hai_Ya-- > 0)
        Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai();

    return 0;
}