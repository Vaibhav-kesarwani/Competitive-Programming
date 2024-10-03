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
    int n, a, b, c; cin >> n >> a >> b >> c;
    int dp[n+1];
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = -1;
        if (i - a >= 0) dp[i] = max(dp[i], dp[i-a]);
        if (i - b >= 0) dp[i] = max(dp[i], dp[i-b]);
        if (i - c >= 0) dp[i] = max(dp[i], dp[i-c]);
        if (dp[i] != -1) dp[i]++;
    }
    cout << dp[n] nt;
}

signed main () {
    Code By Vaibhav
    // int Bhai_Test_Case_Hai_Ya; cin >> Bhai_Test_Case_Hai_Ya; while (Bhai_Test_Case_Hai_Ya-- > 0)
        Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai();

    return 0;
}