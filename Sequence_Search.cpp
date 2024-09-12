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
int gcd(int x, int b) { if (b == 0) return x; return gcd(b, x % b); }
int lcm(int x, int b) { return (x / gcd(x, b) * b); }

void Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai() {
    int x, y, z; cin >> x >> y >> z;
    
    switch (z) {
        case 1:
            cout << 0 nt
            return;
        case 2:
            cout << min(x, y) nt
            return;
        default:
            if (x <= y) {
                int ans = ((z / 2) - 1) * y;
                ((z & 1) ? ans += x : ans += y);
                return;
            }

            int ob = x / y;
            if (z <= ob + 1) {
                cout << y * (z - 1) nt
                return;
            }

            z -= (ob + 1);
            ((z & 1) ? cout << (int)(x + (z / 2) * y) : cout << (ob + z / 2) * y) nt
    }
}

signed main() {
    Code By Vaibhav
    int Bhai_Test_Case_Hai_Ya; cin >> Bhai_Test_Case_Hai_Ya; while (Bhai_Test_Case_Hai_Ya-- > 0)
        Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai();

    return 0;
}
