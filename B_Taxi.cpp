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
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == 1) cnt1++;
        else if (v[i] == 2) cnt2++;
        else if (v[i] == 3) cnt3++;
        else cnt4++;
    }
    int ans = 0;
    ans += cnt4;
    if (cnt3 >= cnt1) {
        ans += cnt3;
        cnt1 = 0;
    } else {
        ans += cnt3;
        cnt1 -= cnt3;
    }
    ans += cnt2 / 2;
    cnt2 %= 2;
    if (cnt2 == 1) {
        ans++;
        cnt1 -= 2;
    }
    if (cnt1 > 0) {
        ans += (cnt1 + 3) / 4;
    }
    cout << ans nt;
}

signed main () {
    Code By Vaibhav
    // int Bhai_Test_Case_Hai_Ya; cin >> Bhai_Test_Case_Hai_Ya; while (Bhai_Test_Case_Hai_Ya-- > 0)
        Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai();

    return 0;
}