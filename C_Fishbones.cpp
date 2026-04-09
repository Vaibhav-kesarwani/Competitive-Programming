/*
 * Author        :         vaibhav_404
 * Date          :         09-04-2026
 * Time          :         16:26
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
    int n; cin >> n;
    vi a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];

    int m; cin >> m;
    vs given_string(m);
    unordered_map<char, set<pii>> mp;
    for (int i = 0; i < m; i++) {
        string s; cin >> s;
        given_string[i] = s;

        for (int j = 0; j < sz(s); j++) {
            mp[s[j]].insert({sz(s), j + 1});
        }
    }

    for (int i = 0; i < m; i++) {
        bool chk = 1;

        if (given_string[i].size() != n) {
            cout << "No" << endl;
            continue;
        }

        for (int j = 0; j < given_string[i].size(); j++) {
            if (mp[given_string[i][j]].find({a[j], b[j]}) == mp[given_string[i][j]].end()) {
                chk = 0;
            }
        }

        cout << (!chk ? "No" : "Yes") << endl;
    }
}
 
signed main() {
    Code By Vaibhav
    // int t; cin >> t; while (t-- > 0)
        solve();
    return 0;
}