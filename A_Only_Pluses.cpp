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
    int x, y, z; cin >> x >> y >> z;
    vector<int> v(3);
    v[0] = x, v[1] = y, v[2] = z;
    sort(v.begin(), v.end());

    for (int i = 0; i < 5; i++) {
        if (v[0] + 1 <= v[1]) v[0]++;
        else if (v[1] + 1 <= v[2]) v[1]++;
        else v[2]++;
    }

    cout << v[0] * v[1] * v[2] nt
}

signed main() {
    Code By Vaibhav 
    int Bhai_Test_Case_Hai_Ya; cin >> Bhai_Test_Case_Hai_Ya; while (Bhai_Test_Case_Hai_Ya-- > 0)
        Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai();

    return 0;
}