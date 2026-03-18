/*
 * Author        :         vaibhav_404
 * Date          :         18-03-2026
 * Time          :         20:38
*/
 
#include <bits/stdc++.h>
using namespace std;
 
// Shorthand Macros
#define pb push_back
#define fi first
#define se second
#define endl "\n";
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b)))
#define sz(a) int((a).size())
#define tr(c,i) for(__typeof__((c)).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
 
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
 
const int MOD = 998244353;

void solve() {
    int n; cin >> n;

    vi pre(n + 1);
    vector<bool> chk(n + 1, false);

    for (int i = 1; i <= n; i++) {
        cin >> pre[i];
        if (pre[i] != -1) chk[pre[i]] = true;
    }

    vi unseen(n + 1, 0);
    for (int i = 1; i <= n; i++)  unseen[i] = unseen[i - 1] + (!chk[i]);

    vi x(n + 1, 0), y(n + 1, 0), z(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        x[i] = x[i - 1] + (pre[i] == -1);
        y[i] = y[i - 1];

        if (pre[i] != -1) y[i] = max(y[i], pre[i]);

        int l = 1;
        while (l <= n && unseen[l] < x[i]) l++;

        z[i] = max(y[i], l);
    }

    vll dp(n + 1, 0), pref(n + 1, 0);
    dp[0] = 1;

    for (int i = 0; i <= n; i++) pref[i] = 1;

    for (int i = 1; i <= n; i++) {
        vll forw(n + 1, 0);

        if (pre[i] != -1) {
            if (pre[i] >= z[i])
                forw[pre[i]] = (forw[pre[i]] + pref[pre[i] - 1]) % MOD;

            for (int j = z[i]; j <= n; j++) forw[j] = (forw[j] + dp[j]) % MOD;
        } else {
            for (int j = z[i]; j <= n; j++) {
                forw[j] = (forw[j] + dp[j]) % MOD;

                if (!chk[j]) forw[j] = (forw[j] + pref[j - 1]) % MOD;
            }
        }

        dp = forw;

        pref[0] = dp[0];
        for (int j = 1; j <= n; j++) pref[j] = (pref[j - 1] + dp[j]) % MOD;
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++) ans = (ans + dp[i]) % MOD;

    cout << ans << endl;
}
 
signed main() {
    Code By Vaibhav
    int t; cin >> t; while (t-- > 0)
        solve();
    return 0;
}