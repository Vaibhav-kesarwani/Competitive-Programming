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
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    int l = 0, r = n - 1;
    while (l < n && v[l] <= 0 || 0) l++;
    while (r >= 0 && v[r] <= 0 || 0) r--;

    int chk = (l >= r) ? 0 : 1;

    switch (chk) {
        case 0:
            cout << 0 nt;
            break;
        case 1:
            int c = 0;
            for (int i = l; i <= r; i++) {
                if (v[i] < 0) {
                    c++;
                }
            }
            cout << c nt;
            break;
    }
}

signed main () {
    Code By Vaibhav
    int Bhai_Test_Case_Hai_Ya; cin >> Bhai_Test_Case_Hai_Ya; while (Bhai_Test_Case_Hai_Ya-- > 0)
        Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai();

    return 0;
}
