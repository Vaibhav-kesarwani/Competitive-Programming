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

void Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai() {
    auto help = [](int m_num) {
        vector<bool> chkPrime(m_num + 1, true);
        chkPrime[0] = chkPrime[1] = false; 
        for (int i = 2; i * i <= m_num; ++i) {
            if (chkPrime[i]) {
                for (int j = i * i; j <= m_num; j += i) {
                    chkPrime[j] = false;
                }
            }
        }
        return chkPrime;
    };

    vector<bool> chkPrime = help(200); 

    int x;
    cin >> x;
    vector<int> terms(101, 0); 
    vector<int> v(x);

    for (int i = 0; i < x; ++i) {
        cin >> v[i];
        terms[v[i]]++;
    }

    int chk = 0; 

    for (int i = 1; i <= 100 && !chk; ++i) {
        for (int j = i; j <= 100 && !chk; ++j) {
            if (terms[i] > 0 && terms[j] > 0) {
                if (i != j || terms[i] > 1) {
                    int sum = i + j;
                    if (!chkPrime[sum]) { 
                        int vv = -1, vvv = -1;
                        for (int k = 0; k < x; ++k) {
                            if (v[k] == i && vv == -1) {
                                vv = k + 1; 
                            } else if (v[k] == j && (vvv == -1 || vvv == vv)) {
                                vvv = k + 1; 
                            }
                            if (vv != -1 && vvv != -1 && vv != vvv) {
                                cout << vv << " " << vvv nt
                                chk = 1;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }

    if (!chk) cout << -1 nt
}

signed main () {
    Code By Vaibhav
    int Bhai_Test_Case_Hai_Ya; 
    cin >> Bhai_Test_Case_Hai_Ya;
    while (Bhai_Test_Case_Hai_Ya-- > 0)
        Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai();

    return 0;
}
