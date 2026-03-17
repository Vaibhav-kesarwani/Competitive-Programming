/*
 * Author        :         vaibhav_404
 * Date          :         16-03-2026
 * Time          :         20:29
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
 
void solve() {
    int n, m; cin >> n >> m;
    vvi a(n + 1);

    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        a[x].pb(y);
        a[y].pb(x);
    }

    vi curr(n + 1, -1);
    ll ans = 0;

    for (int i = 1; i <= n; i++) {
        if (curr[i] != -1) continue;

        queue<int> q; q.push(i);
        curr[i] = 0;

        int cnt1 = 0, cnt2 = 1; bool chk = 1;

        while (!q.empty()) {
            int x = q.front(); q.pop();
            for (int it : a[x]) {
                if (curr[it] == -1) {
                    curr[it] = curr[x] ^ 1;
                    (curr[it] ? cnt1++ : cnt2++);
                    q.push(it);
                }
                else if (curr[x] == curr[it]) chk = 0;
            }
        }

        (chk ? ans += max(cnt1, cnt2) : 0);
    }

    cout << ans << endl;
}
 
signed main() {
    Code By Vaibhav
    int t; cin >> t; while (t-- > 0)
        solve();
    return 0;
}