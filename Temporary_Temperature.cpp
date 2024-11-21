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
const int INF = 1e9;
const int mod = 1000000007;
int gcd(int a, int b) { return (b == 0) ? a : gcd(b, a % b); }
int lcm(int a, int b) { return (a / gcd(a, b) * b); }

bool help(vector<int>& a, int n, int k, int maxi) {
    int chg = 0;
    int cl = a[0] - maxi;
    int ch = a[0] + maxi;

    int i = 0;
    while (i < n) {
        int nl = a[i] - maxi;
        int nh = a[i] + maxi;

        (ch < nl || nh < cl) ? (++chg, cl = nl, ch = nh) : (cl = max(cl, nl), ch = min(ch, nh));
        i++;
    }

    return chg <= k;
}

void Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai() {
    int n, x; cin >> n >> x;
    vector<int> v(n);

    int i = 0;
    while (i < n) cin >> v[i], i++;

    int l = 0, r = INF, ans = INF;

    while (l <= r) {
        int mid = l + (r - l) / 2;

        help(v, n, x, mid) ? (ans = mid, r = mid - 1) : (l = mid + 1);
    }

    cout << ans nt
}

signed main() {
    Code By Vaibhav
    int Bhai_Test_Case_Hai_Ya; cin >> Bhai_Test_Case_Hai_Ya; 
    while (Bhai_Test_Case_Hai_Ya-- > 0)
        Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai();

    return 0;
}
