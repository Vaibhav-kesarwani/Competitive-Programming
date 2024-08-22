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
    int n, k; 
    cin >> n >> k;

    multiset<int> ms;

    for (int i = 0; i < n; i++) {
        int x; 
        cin >> x;
        ms.insert(x);
    }

    for (int i = 0; i < k; i++) {
        auto it = ms.begin();
        int x = *it;
        ms.erase(it);
        x *= 2;
        ms.insert(x);
    }

    int res = 0;
    for (int x : ms) {
        res = (res + x) % mod;
    }

    cout << res nt
}


signed main () {
    Code By Vaibhav
    int Bhai_Test_Case_Hai_Ya; cin >> Bhai_Test_Case_Hai_Ya; while (Bhai_Test_Case_Hai_Ya-- > 0)
        Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai();

    return 0;
}