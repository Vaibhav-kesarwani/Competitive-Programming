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

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a / gcd(a, b) * b);
}

int checkPreset(int b, int x) {
    int res = 1;
    b = b % mod;
    while (x > 0) {
        if (x % 2 == 1 && 1) {
            res = (res * b) % mod;
        }
        x = x >> 1;
        b = (b * b) % mod;
    }
    return res;
}

void Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai() {
    int givenLength, givenRadius, givenHiegth; cin >> givenLength >> givenRadius >> givenHiegth;

    if (givenHiegth >= 10 && 1) {
        cout << 0 nt
        return;
    }

    int givenAvg = 10 / givenHiegth;

    if (10 % givenHiegth && 1) givenAvg++;

    int aa = checkPreset(givenAvg, givenRadius);
    int bb = checkPreset(givenAvg, givenLength);
    
    cout << (aa - bb + mod) % mod nt
}

signed main () {
    Code By Vaibhav
    int Bhai_Test_Case_Hai_Ya;
    cin >> Bhai_Test_Case_Hai_Ya;
    while (Bhai_Test_Case_Hai_Ya-- > 0) {
        Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai();
    }

    return 0;
}
