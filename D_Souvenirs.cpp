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
    vector<int> v(x);
    for (int i = 0; i < x; i++) cin >> v[i];

    vector<int> vv(y);
    for (int i = 0; i < y; i++) cin >> vv[i];

    sort(v.begin(), v.end(), greater<int>());
    sort(vv.begin(), vv.end(), greater<int>());

    priority_queue<int, vector<int>, greater<int>> pp;
    int total = 0;
    int chk = 0;

    for (int i = 0; i < y; i++) {
        while (chk < x && v[chk] >= vv[i]) {
            pp.push(v[chk]);
            chk++;
        }

        if (pp.empty()) {
            cout << -1 nt
            return;
        }

        total += pp.top();
        pp.pop();
    }

    cout << total nt
}

signed main () {
    Code By Vaibhav
    // int Bhai_Test_Case_Hai_Ya; cin >> Bhai_Test_Case_Hai_Ya; while (Bhai_Test_Case_Hai_Ya-- > 0)
        Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai();

    return 0;
}