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
    string s; cin >> s;
    
    bool cnt = (sqrt(n) * sqrt(n) == n);
    
    if (cnt) {
        int i = 0;
        do {
            switch (s[i] == '1' && s[n - sqrt(n) + i] == '1') {
                case true:
                    cnt = true;
                    break;
                case false:
                    cnt = false;
                    break;
            }
            if (!cnt) break;
            i++;
        } while (i < sqrt(n));

        if (cnt) {
            i = 1;
            do {
                switch (s[i * sqrt(n)] == '1' && s[i * sqrt(n) + sqrt(n) - 1] == '1') {
                    case true:
                        cnt = true;
                        break;
                    case false:
                        cnt = false;
                        break;
                }
                if (!cnt) break;

                if (sqrt(n) > 2) {
                    int j = 1;
                    do {
                        switch (s[i * sqrt(n) + j] == '0') {
                            case true:
                                cnt = true;
                                break;
                            case false:
                                cnt = false;
                                break;
                        }
                        if (!cnt) break;
                        j++;
                    } while (j < sqrt(n) - 1);
                }
                i++;
            } while (i < sqrt(n) - 1);
        }
    }

    ((cnt) ? Yes : No) nt
}

signed main () {
    Code By Vaibhav
    int Bhai_Test_Case_Hai_Ya; cin >> Bhai_Test_Case_Hai_Ya; while (Bhai_Test_Case_Hai_Ya-- > 0)
        Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai();

    return 0;
}
