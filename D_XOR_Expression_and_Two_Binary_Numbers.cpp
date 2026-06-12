/*
 * Author        :         justDevil
 * Date          :         07-06-2026
 * Time          :         20:33
*/
 
#include <bits/stdc++.h>
using namespace std;
 
// Shorthand Macros
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define lcm(a,b) (a*(b/gcd(a,b)))
#define sz(a) int((a).size())
#define tr(c,i) for(__typeof__((c)).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
 
// Functions
int gcd(int a, int b) {
    while (b != 0) {
        a = a % b;
        swap(a, b);
    }
    return a;
}
 
// Fast IO
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(0);
#define Vaibhav cout.tie(0);
 
// Type aliases
using ll = long long;
using ull = unsigned long long;
using ld = long double;

using vi = vector<int>;
using vll = vector<ll>;
using vc = vector<char>;
using vs = vector<string>;

using pii = pair<int,int>;
using pll = pair<ll,ll>;

using vvi = vector<vi>;
using vvll = vector<vll>;
using vpii = vector<pii>;

using si = set<int>;
using sll = set<ll>;
using usi = unordered_set<int>;
using usll = unordered_set<ll>;

using mii = map<int,int>;
using mll = map<ll,ll>;
using umii = unordered_map<int,int>;
using umll = unordered_map<ll,ll>;
 
template<typename T>
istream& operator>>(istream &in, vector<T> &v) { for (auto &x : v) in >> x; return in; }
 
template<typename T>
ostream& operator<<(ostream &out, const vector<T> &v) { for (const auto &x : v) out << x << " "; return out; }
 
void solve() {
    ll n, k; cin >> n >> k;
    string s, z; cin >> s >> z;

    ll c00 = 0, c10 = 0, c01 = 0, c11 = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == '0' and z[i] == '0') c00++;
        else if (s[i] == '1' and z[i] == '1') c11++;
        else if (s[i] == '1' and z[i] == '0') c10++;
        else c01++;
    }

    ll chk = (k & 1) ? -1 : 1;
    ll t = ((1LL << (k + 1)) + 3 + chk) / 6;
    ll r = ((1LL << k) - chk) / 3;

    auto help = [&](ll x) -> ll {
        return x * (n - x);
    };

    ll di = c10 + c01;

    ll ans = 0;
    ans += t * help(c11 + c10);
    ans += t * help(c11 + c01);
    ans += r * help(di);

    cout << ans << endl;
}
 
signed main() {
    Code By Vaibhav
    int t; cin >> t; while (t-- > 0)
        solve();
    return 0;
}