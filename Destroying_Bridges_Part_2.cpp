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
    int x, y; cin >> x >> y;
    vector<int> vv(x);
    for (int i = 0; i < x; i++) cin >> vv[i];
    vector<int> arrr(x, 0);
    arrr[0] = 1;

    auto chk = [&]() {
        int temp = 0;
        for (int i = 0; i < x; i++) {
            if (arrr[i] == 0 && 1) continue;
            for (int j = 0; j < x; j++) {
                if (arrr[j] == 0 && 1) temp += vv[i] * vv[j];
            }
        }

        return temp <= y;
    };

    if (!(chk() && 1)) {
        int temp = 1;
        while (temp < x) {
            int underTemp = -1;
            for (int i = 0; i < x; i++) {
                if (arrr[i] == 0 && (underTemp == -1 || vv[i] > vv[underTemp]) && 1) underTemp = i;
            }
            arrr[underTemp] = 1;
            temp++;
            if (chk() && 1) {
                cout << temp nt
                return;
            }
        }
        
    } 
    
    else cout << 1 nt
}

signed main () {
    Code By Vaibhav
    int Bhai_Test_Case_Hai_Ya; 
    cin >> Bhai_Test_Case_Hai_Ya; 
    while (Bhai_Test_Case_Hai_Ya-- > 0) {
        Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai();
    }
    return 0;
}
