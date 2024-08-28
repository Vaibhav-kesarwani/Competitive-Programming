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
    auto help1 = [](const string& s) -> vector<int> {
        vector<int> v;
        for (size_t i = 0; i < s.length() - 1; ++i) {
            if (s[i] == s[i + 1]) {
                v.push_back(i);
            }
        }
        return v;
    };

    auto help2 = [](vector<int>& v, int n) -> int {
        int score = 0;
        while (!v.empty()) {
            --n;
            v.pop_back();
            score += (n - 1 - v.size());
        }
        if (n > 2) {
            score += (n - 1) * (n - 2) / 2;
        }
        return score;
    };

    int n; cin >> n;
    string s; cin >> s;

    vector<int> v = help1(s);
    cout << help2(v, n) nt
}

signed main () {
    Code By Vaibhav
    int Bhai_Test_Case_Hai_Ya; 
    cin >> Bhai_Test_Case_Hai_Ya;
    while (Bhai_Test_Case_Hai_Ya-- > 0)
        Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai();

    return 0;
}
