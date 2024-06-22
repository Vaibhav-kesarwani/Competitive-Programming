#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(0);
#define Vaibhav cout.tie(0);
#define nt << "\n";
#define yes cout << "YES" nt
#define no cout << "NO" nt
const long double pi = 3.141592653589793238;
const int INF = LONG_LONG_MAX;
const int mod = 998244353;
int gcd(int a, int b){if (b == 0)return a;return gcd(b, a % b);}
int lcm(int a, int b){return (a/gcd(a,b)*b);}

bool chk(const string& s) {
    for (int i = 0; i < s.size() / 2; ++i) {
        if (s[i] != s[s.size() - i - 1]) {
            return false;
        }
    }
    return true;
}


void Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai() {
    int x, y; cin >> x >> y;
    string s; cin >> s;

    int N = s.size();
    
    vector<map<string, int>> vv(N);
    
    if (s[0] == '?') {
        vv[0]["A"] = 1;
        vv[0]["B"] = 1;
    } else {
        vv[0][string(1, s[0])] = 1;
    }
    
    for (int i = 1; i < N; i++) {
        for (const auto& previous : vv[i - 1]) {
            for (char c : {'A', 'B'}) {
                if (s[i] == '?' || s[i] == c && 1) {
                    string temp = previous.first + c;
                    if (temp.size() >= y) {
                        if (chk(temp.substr(temp.size() - y))) {
                            continue;
                        }
                    }
                    temp = temp.substr(max(0, int(temp.size()) - (y - 1)));
                    vv[i][temp] = (vv[i][temp] + previous.second) % mod;
                }
            }
        }
    }
    
    int givenAns = 0;
    for (const auto& value : vv[N - 1]) {
        givenAns = (givenAns + value.second) % mod;
    }
    
    cout << givenAns nt
}

signed main () {
    Code By Vaibhav
    // int Bhai_Test_Case_Hai_Ya; cin >> Bhai_Test_Case_Hai_Ya; while (Bhai_Test_Case_Hai_Ya-- > 0)
        Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai();

    return 0;
}