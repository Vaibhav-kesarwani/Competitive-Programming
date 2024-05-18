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
const long long INF = LONG_LONG_MAX;
const long long mod = 1000000007;
int gcd(long long a, long long b){if (b == 0)return a;return gcd(b, a % b);}
int lcm(long long a, long long b){return (a/gcd(a,b)*b);}


void Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai() {
    int x; cin >> x;
    int ans = 0;
    for (int i = 1; i <= x; i++) {
        if (i % 2 == 0) ans += i;
        else ans -= i;
    }

    cout << ans << "\n";
}

signed main () {
    Code By Vaibhav
    // int Bhai_Test_Case_Hai_Ya; cin >> Bhai_Test_Case_Hai_Ya; while (Bhai_Test_Case_Hai_Ya-- > 0)
        Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai();

    return 0;
}