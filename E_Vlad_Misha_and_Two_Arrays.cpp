/*
 * Author        :         justDevil
 * Date          :         07-06-2026
 * Time          :         21:09
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
 
const ll MOD = 1000000007LL;
const int MAXN = 500000;

struct ph {
    size_t operator()(const pii& p) const {
        return ((uint64_t)p.first << 32) ^ (uint64_t)p.second;
    }
};

ll modpow(ll a, ll e) {
    ll r = 1;
    while (e) {
        if (e & 1) r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

vll fact(MAXN + 1), invfact(MAXN + 1);

ll help(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invfact[r] % MOD * invfact[n - r] % MOD;
}

unordered_map<ll, vi> rot;
unordered_map<ll, ll> mo;

inline long long getKey(int l, int r) {
    return ((long long)l << 20) | r;
}

ll dfs(int l, int r) {
    if (l > r) return 1;

    long long k = getKey(l, r);

    auto it = mo.find(k);
    if (it != mo.end()) return it->second;

    ll ans = 0;

    auto rt = rot.find(k);

    if (rt != rot.end()) {
        for (int root : rt->second) {

            ll left = dfs(l, root - 1);
            ll right = dfs(root + 1, r);

            ll ways = left * right % MOD;
            ways = ways * help(r - l, root - l) % MOD;

            ans = (ans + ways) % MOD;
        }
    }

    return mo[k] = ans;
}

void solve() {
    int n; cin >> n;

    vll a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    rot.clear();
    mo.clear();

    rot.reserve(8 * n);
    mo.reserve(8 * n);
    
    rot.max_load_factor(0.7);
    mo.max_load_factor(0.7);

    for (int i = 1; i <= n; i++) {
        ll x = a[i];
        if (x > 1LL * n * n) continue;

        for (ll d = 1; d <= min((ll)n, (ll)sqrtl(x)); d++) {
            if (x % d) continue;
            ll e = x / d;

            auto add_interval = [&](ll u, ll v) {
                if (u > n || v > n) return;

                ll L = i - u + 1;
                ll R = i + v - 1;

                if (L < 1 || R > n) return;

                rot[getKey((int)L, (int)R)].push_back(i);
            };

            if (e <= n) {
                add_interval(d, e);
                if (d != e) add_interval(e, d);
            }
        }
    }

    for (auto &p : rot) {
        auto &v = p.second;
        sort(all(v));
        v.erase(unique(all(v)), v.end());
    }

    cout << dfs(1, n) << endl;
}
 
signed main() {
    Code By Vaibhav

    fact[0] = 1;
    for (int i = 1; i <= MAXN; i++) fact[i] = fact[i - 1] * i % MOD;

    invfact[MAXN] = modpow(fact[MAXN], MOD - 2);

    for (int i = MAXN; i >= 1; i--) invfact[i - 1] = invfact[i] * i % MOD;

    int t; cin >> t; while (t-- > 0)
        solve();
    return 0;
}