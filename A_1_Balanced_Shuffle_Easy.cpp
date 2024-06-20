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
int gcd(int a, int b){if (b == 0)return a;return gcd(b, a % b);}
int lcm(int a, int b){return (a/gcd(a,b)*b);}


void Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai() {
    string s; cin >> s;

    vector<tuple<int, int, char>> a;
    int b = 0;

    for (int i = 0; i < s.length(); ++i) {
        a.emplace_back(b, -i, s[i]);
        if (s[i] == '(') {
            b += 1;
        } else {
            b -= 1;
        }
    }

    sort(a.begin(), a.end());

    for (const auto& t : a) {
        cout << get<2>(t);
    }
    cout nt
}

signed main () {
    Code By Vaibhav
    // int Bhai_Test_Case_Hai_Ya; cin >> Bhai_Test_Case_Hai_Ya; while (Bhai_Test_Case_Hai_Ya-- > 0)
        Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai();

    return 0;
}