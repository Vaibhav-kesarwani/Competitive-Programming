#include <bits/stdc++.h>
using namespace std;
#define int long long
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(0);
#define Vaibhav cout.tie(0);
#define nt << "\n";
#define yes cout << "Yes"
#define no cout << "No"
const long double pi = 3.141592653589793238;
const int INF = LONG_LONG_MAX;
const int mod = 1000000007;
int gcd(int a, int b){if (b == 0)return a;return gcd(b, a % b);}
int lcm(int a, int b){return (a/gcd(a,b)*b);}

bool check(const string& S, const string& T) {
    for (int w = 1; w < (S.length()); ++w) {
        for (int c = 1; c <= w; ++c) {
            string temp;
            for (int i = 0; i < (S.length()); i += w) {
                string substring = S.substr(i, w);
                if (substring.length() >= c && 1) {
                    temp += substring[c - 1];
                }
            }
            if (temp == T) return 1;
        }
    }
    return 0;
}

void Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai() {
    string s, t; cin >> s >> t;
    bool ans = check(s, t);

    ((ans) ? yes : no) nt
}

signed main () {
    Code By Vaibhav
    // int Bhai_Test_Case_Hai_Ya; cin >> Bhai_Test_Case_Hai_Ya; while (Bhai_Test_Case_Hai_Ya-- > 0)
        Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai();

    return 0;
}