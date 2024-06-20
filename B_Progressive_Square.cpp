#include <bits/stdc++.h>
using namespace std;
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(0);
#define Vaibhav cout.tie(0);
#define nt << "\n";
#define yes cout << "YES" nt
#define no cout << "NO" nt
#define all(x) (x).begin(), (x).end() 
using ll = signed long long int;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
const long double pi = 3.141592653589793238;
const int INF = LONG_LONG_MAX;
const int mod = 1000000007;
int gcd(int a, int b){if (b == 0)return a;return gcd(b, a % b);}
int lcm(int a, int b){return (a/gcd(a,b)*b);}


void Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai() {
    int n;
    ll c, d;
    cin >> n >> c >> d;
    vl a(n * n);
    for (int i = 0; i < n * n; ++i) {
        cin >> a[i];
    }
    sort(all(a));
    vl b(n * n);
    b[0] = a[0];
    for (int i = 1; i < n; ++i) {
        b[i] = b[i - 1] + c;
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            b[i * n + j] = b[(i - 1) * n + j] + d;
        }
    }
    sort(all(b));
    cout << (a == b ? "YES" : "NO") nt
}

signed main () {
    Code By Vaibhav
    int Bhai_Test_Case_Hai_Ya; cin >> Bhai_Test_Case_Hai_Ya; while (Bhai_Test_Case_Hai_Ya-- > 0)
        Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai();

    return 0;
}