/*
 * Author        :         vaibhav_404
 * Date          :         18-03-2026
 * Time          :         20:33
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
 
void toggle(string &s, int l, int r) {
    for (int i = l; i <= r; i++) s[i] = (s[i] == '0' ? '1' : '0');
}

vector<pii> ans(string s) {
    vector<pii> ops;
    int n = sz(s);

    auto apply = [&](int l, int r) {
        if (!ops.empty() && ops.back() == make_pair(l, r))
            ops.pop_back();
        else ops.pb({l, r});
        toggle(s, l, r);
    };

    while (1) {
        int l = -1, r = -1;

        for (int i = 0; i < n; i++)
            if (s[i] == '1') { l = i; break; }

        for (int i = n - 1; i >= 0; i--)
            if (s[i] == '0') { r = i; break; }

        if (l != -1 && r != -1 && l < r) apply(l, r);
        else break;
    }

    int z = count(all(s), '0');
    if (z > 1) {
        apply(0, n - 1);
        apply(1, n - 1);
        apply(0, z - 1);
    }

    return ops;
}

void solve() {
    int n; cin >> n;
    string a, b; cin >> a >> b;

    if (a == b) {
        cout << "0\n0\n";
        return;
    }

    bool a0 = 0, a1 = 0, b0 = 0, b1 = 0;

    for (char c : a) (c == '0' ? a0 : a1) = 1;
    for (char c : b) (c == '0' ? b0 : b1) = 1;

    bool pa = !(a0 && a1), pb = !(b0 && b1);

    if (pa && pb) {
        cout << "1\n1\n1 " << n << endl;
        return;
    }

    vector<pii> res;

    auto add = [&](int l, int r) {
        if (!res.empty() && res.back() == make_pair(l, r))
            res.pop_back();
        else res.pb({l, r});
    };

    string ta = a, tb = b;

    if (pa) {
        add(0, 0);
        ta[0] = (ta[0] == '0' ? '1' : '0');
    }

    if (pb)
        tb[0] = (tb[0] == '0' ? '1' : '0');

    auto it1 = ans(ta);
    auto it2 = ans(tb);

    for (auto &p : it1) add(p.fi, p.se);

    for (int i = sz(it2) - 1; i >= 0; i--)
        add(it2[i].fi, it2[i].se);

    if (pb) add(0, 0);

    cout << (pa || pb) << endl;
    cout << sz(res) << endl;

    for (auto &p : res) cout << p.fi + 1 << " " << p.se + 1 << endl;
}
 
signed main() {
    Code By Vaibhav
    int t; cin >> t; while (t-- > 0)
        solve();
    return 0;
}