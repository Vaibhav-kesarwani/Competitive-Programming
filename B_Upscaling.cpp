#include <bits/stdc++.h>
using namespace std;
#define int long long
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(NULL);
#define Vaibhav cout.tie(NULL);
#define nt <<"\n";
#define yes cout << "YES" nt
#define no cout << "NO" nt
const long double pi = 3.141592653589793238;
const long long INF = LONG_LONG_MAX;
const long long mod = 1000000007;


void Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai() {
    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        int t = 2;
        char first = '#';
        char second = '.';
        if (i % 2 == 1) {
            first = '.';
            second = '#';
        }
        while (t--) {
            for (int j = 0; j < n; j++) {
                int p = 2;
                while (p--) {
                    if (j % 2 == 1) {
                        cout << second;
                    }
                    else {
                        cout << first;
                    }
                }
            }

            cout << "\n";
        }
    }

    // if (n == 1) {
        // cout << "##" nt
        // cout << "##" nt
    // }
}

signed main () {
    Code By Vaibhav
    int Bhai_Test_Case_Hai_Ya; cin >> Bhai_Test_Case_Hai_Ya; while (Bhai_Test_Case_Hai_Ya-- > 0)
        Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai();

    return 0;
}