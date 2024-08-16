#include <bits/stdc++.h>
using namespace std;
// #define int long long
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
    int a, b;
    cin >> a >> b;
    int c, d;
    cin >> c >> d;
    
    int flags[105] = {0}; 
    int intersection = min(b, d) - max(a, c);
    
    if (b > d) flags[d] = 1;
    if (c < a) flags[a - 1] = 1;
    if (d > b) flags[b] = 1;
    if (a < c) flags[c - 1] = 1;

    int total = 0;
    for (int i = 1; i <= 101; i++) total += flags[i];

    if (intersection < 0) total = 0;
    cout << max(total + max(0, intersection), 1) nt
}



signed main () {
    Code By Vaibhav
    int Bhai_Test_Case_Hai_Ya; cin >> Bhai_Test_Case_Hai_Ya; while (Bhai_Test_Case_Hai_Ya-- > 0)
        Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai();

    return 0;
}