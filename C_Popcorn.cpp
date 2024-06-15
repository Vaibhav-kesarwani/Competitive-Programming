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
const int INF = INT_MAX;
const int mod = 1000000007;
int gcd(int a, int b){if (b == 0)return a;return gcd(b, a % b);}
int lcm(int a, int b){return (a/gcd(a,b)*b);}


void Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai() {
    int x, y; cin >> x >> y;
    vector<string> v(x);
    for (int i = 0; i < x; i++) cin >> v[i];

    vector<int> givenAns(1 << y, INF);
    givenAns[0] = 0;

    for (int i = 0; i < x; i++) {
        int given = 0;
        for (int j = 0; j < y; j++) {
            if (v[i][j] == 'o') {
                given |= (1 << j);
            }
        }

        for (int k = (1 << y) - 1; k >= 0; k--) {
            if (givenAns[k] != INT_MAX) {
                int bitCnt = k | given;
                givenAns[bitCnt] = min(givenAns[bitCnt], givenAns[k] + 1);
            }
        }
    }

    cout << givenAns[(1 << y) - 1] nt
}

signed main () {
    Code By Vaibhav
    // int Bhai_Test_Case_Hai_Ya; cin >> Bhai_Test_Case_Hai_Ya; while (Bhai_Test_Case_Hai_Ya-- > 0)
        Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai();

    return 0;
}