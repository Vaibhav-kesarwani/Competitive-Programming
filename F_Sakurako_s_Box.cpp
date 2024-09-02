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
const int MOD = 1000000007;
int gcd(int a, int b) { 
    switch (b) {
        case 0: return a;
        default: return gcd(b, a % b);
    }
}
int lcm(int a, int b) { 
    return (a / gcd(a, b) * b); 
}

int fastadd(int x, int y) {
    return (MOD + (x % MOD) + (y % MOD)) % MOD;
}

int fastmul(int x, int y) {
    return ((x % MOD) * (y % MOD)) % MOD;
}

int binpow(int x, int y) {
    switch (y) {
        case 0: return 1LL;
        default: 
            int powa = binpow(x, y / 2);
            powa = fastmul(powa, powa);
            return (y % 2 == 1) ? fastmul(powa, x) : powa;
    }
}

void Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai() {
    int n;
    cin >> n;
    vector<int> v(n);
    int summ = 0;
    int i = 0;
    do {
        cin >> v[i];
        summ = fastadd(summ, v[i]);
        i++;
    } while (i < n);

    int sol = 0;
    i = 0;
    do {
        sol = fastadd(sol, fastmul(summ - v[i], v[i]));
        i++;
    } while (i < n);

    cout << fastmul(sol, binpow(fastmul(n, n - 1), MOD - 2)) nt
}

signed main () {
    Code By Vaibhav
    int Bhai_Test_Case_Hai_Ya; cin >> Bhai_Test_Case_Hai_Ya;
    while (Bhai_Test_Case_Hai_Ya-- > 0) {
        Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai();
    }

    return 0;
}
