/*
 * Author        :         justDevil
 * Date          :         03-06-2026
 * Time          :         20:19
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
 
struct BIT {
    int n;
    vector<ll> bit;

    BIT(int n) : n(n), bit(n + 1, 0) {}

    void add(int idx, ll val) {
        for (; idx <= n; idx += idx & -idx)
            bit[idx] += val;
    }

    ll sum(int idx) const {
        ll res = 0;
        for (; idx > 0; idx -= idx & -idx)
            res += bit[idx];
        return res;
    }

    ll query(int l, int r) const {
        if (l > r) return 0;
        return sum(r) - sum(l - 1);
    }
};

struct Query {
    ll b;
    int l, r;
    ll w;
};

void solve() {
    int n; cin >> n;
    vll a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    ll ans = 0;
    for (int i = 1; i <= n; i++) ans += a[i] * 1LL * i * (n - i + 1);

    vll np(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        np[i] = np[i - 1];
        if (a[i] < 0) np[i] += -a[i];
    }

    vll x(n + 1);
    for (int i = 1; i <= n; i++) x[i] = np[i - 1];

    const ll N_INF = -(ll)4e18;

    vll b(n + 1, N_INF);
    for (int i = 1; i <= n; i++) {
        if (a[i] > 0) b[i] = np[i - 1] - a[i];
    }

    vi pg(n + 1), ng(n + 1);
    {
        vi st;
        for (int i = 1; i <= n; i++) {
            while (!st.empty() && b[st.back()] <= b[i]) st.pop_back();
            pg[i] = st.empty() ? 0 : st.back();
            st.pb(i);
        }
    }

    {
        vi st;
        for (int i = n; i >= 1; i--) {
            while (!st.empty() && b[st.back()] < b[i]) st.pop_back();
            ng[i] = st.empty() ? n + 1 : st.back();
            st.pb(i);
        }
    }

    vector<Query> q;

    for (int i = 1; i <= n; i++) {
        ll bb = b[i];
        if (bb <= 0) continue;
        int l = pg[i] + 1;
        int r = i;
        ll w = ng[i] - i;
        q.pb({bb, l, r, w});
    }

    vector<pair<ll, int>> vals;
    vals.reserve(n);
    for (int i = 1; i <= n; i++) vals.push_back({x[i], i});

    sort(all(vals));

    sort(all(q),
        [](const Query &a, const Query &b) {
            return a.b < b.b;
        }
    );

    BIT bitCnt(n), bitSum(n);

    int ptr = 0; ll extra = 0;

    for (auto &it : q) {
        while (ptr < n and vals[ptr].first < it.b) {
            int pos = vals[ptr].second;
            ll x = vals[ptr].first;
            
            bitCnt.add(pos, 1);
            bitSum.add(pos, x);
            ptr++;
        }

        ll cnt = bitCnt.query(it.l, it.r);
        ll sumX = bitSum.query(it.l, it.r);
        
        extra += it.w * (cnt * it.b - sumX);
    }

    ans += 2 * extra;
    cout << ans << '\n';
}
 
signed main() {
    Code By Vaibhav
    int t; cin >> t; while (t-- > 0)
        solve();
    return 0;
}