/*
 * Author        :         justDevil
 * Date          :         14-04-2026
 * Time          :         17:13
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
 
struct FenwickTree {
    int n;
    vector<ll> bit;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n + 1, 0);
    }

    void update(int i, ll val) {
        for (; i <= n; i += i & -i) {
            bit[i] += val;
        }
    }

    ll query(int i) {
        ll sum = 0;
        for (; i > 0; i -= i & -i) {
            sum += bit[i];
        }
        return sum;
    }

    void range_update(int l, int r, ll val) {
        update(l, val);
        if (r + 1 <= n) {
            update(r + 1, -val);
        }
    }
};

void solve() {
    ll n, q; cin >> n >> q;
    vll a(n + 1); 
    for (int i = 1; i <= n; i++) cin >> a[i];

    FenwickTree fen(n);

    while (q--) {
        int type; cin >> type;
        if (type == 1) {
            ll l, r, x; cin >> l >> r >> x;

            fen.range_update(l, r, x);
        }
        else if (type == 2) {
            int chk; cin >> chk;

            cout << a[chk] + fen.query(chk) << endl;
        }
    }
}
 
signed main() {
    Code By Vaibhav
    // int t; cin >> t; while (t-- > 0)
        solve();
    return 0;
}