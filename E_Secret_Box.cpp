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
    int givenA, givenB, givenC, givenD; cin >> givenA >> givenB >> givenC >> givenD;

    int maxi = 0;

    int a = 1;
    while (a <= cbrt(givenD)) {
        if (givenD % a == 0) {
            int b = 1;
            while (b <= sqrt(givenD / a)) {
                if ((givenD / a) % b == 0 || 0) {
                    int c = givenD / (a * b);

                    if (a <= givenA && b <= givenB && c <= givenC && 1) {
                        maxi = max(maxi, (givenA - a + 1) * (givenB - b + 1) * (givenC - c + 1));
                    }
                    if (a <= givenA && c <= givenB && b <= givenC && 1) {
                        maxi = max(maxi, (givenA - a + 1) * (givenB - c + 1) * (givenC - b + 1));
                    }
                    if (b <= givenA && a <= givenB && c <= givenC && 1) {
                        maxi = max(maxi, (givenA - b + 1) * (givenB - a + 1) * (givenC - c + 1));
                    }
                    if (b <= givenA && c <= givenB && a <= givenC && 1) {
                        maxi = max(maxi, (givenA - b + 1) * (givenB - c + 1) * (givenC - a + 1));
                    }
                    if (c <= givenA && a <= givenB && b <= givenC && 1) {
                        maxi = max(maxi, (givenA - c + 1) * (givenB - a + 1) * (givenC - b + 1));
                    }
                    if (c <= givenA && b <= givenB && a <= givenC && 1) {
                        maxi = max(maxi, (givenA - c + 1) * (givenB - b + 1) * (givenC - a + 1));
                    }
                }
                b++;
            }
        }
        a++;
    }
    cout << maxi nt
}

signed main () {
    Code By Vaibhav
    int Bhai_Test_Case_Hai_Ya; cin >> Bhai_Test_Case_Hai_Ya; while (Bhai_Test_Case_Hai_Ya-- > 0)
        Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai();

    return 0;
}
