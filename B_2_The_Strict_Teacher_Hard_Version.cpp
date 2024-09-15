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
    int x, y, z; cin >> x >> y >> z;
    vector<int> v(y);
    for (int i = 0; i < y; i++) cin >> v[i];
    sort(v.begin(), v.end());

    while (z--) {
        int a; cin >> a;
        int res;

        int chk = (a < v[0]) ? 1 : (a > v.back()) ? 2 : 3;

        switch (chk) {
            case 1:
                res = v[0] - 1;
                break;
            case 2:
                res = x - v.back();
                break;
            case 3: {
                auto it = lower_bound(v.begin(), v.end(), a);
                auto it2 = it;
                it2--;
                res = min(abs(((*it + *it2) / 2) - *it), abs(((*it + *it2) / 2) - *it2));
                break;
            }
        }

        cout << res nt;
    }
}

signed main () {
    Code By Vaibhav
    int Bhai_Test_Case_Hai_Ya; cin >> Bhai_Test_Case_Hai_Ya; while (Bhai_Test_Case_Hai_Ya-- > 0)
        Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai();

    return 0;
}
