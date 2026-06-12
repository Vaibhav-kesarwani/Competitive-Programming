/*
 * Author        :         justDevil
 * Date          :         07-06-2026
 * Time          :         20:54
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
 
struct DSU {
    vi p;

    DSU(int n) {
        p.resize(n + 1);
        iota(all(p), 0);
    }

    int find(int x) {
        return p[x] == x ? x : p[x] = find(p[x]);
    }

    void unite(int a, int b, int c) {
        p[a] = c;
        p[b] = c;
        p[c] = c;
    }
};


void solve() {
    int n; cin >> n;
    vll h(n); cin >> h;

    vector<array<ll,3>> ed;

    for (int i = 0; i < n; i++) {
        int u = i + 1;
        int v = (i + 1) % n + 1;

        ed.pb({h[i], u, v});
    }

    sort(all(ed));

    int a = 2 * n + 5;

    vvi g(a);
    vll wg(a, 0);
    vi lg(a, 0);

    DSU dsu(2 * n + 2);
    int ptr = n;

    for (auto &[w, u, v] : ed) {
        int ru = dsu.find(u);
        int rv = dsu.find(v);

        if (ru == rv) continue;
        ptr++;

        wg[ptr] = w;

        g[ptr].push_back(ru);
        g[ptr].push_back(rv);

        dsu.unite(ru, rv, ptr);
    }

    int root = dsu.find(1);

    vll add(a, 0), ans(n + 1, 0);

    function<void(int)> dfs1 = [&](int u) {
        if (u <= n) {
            lg[u] = 1;
            return;
        }

        for (int v : g[u]) {
            dfs1(v);
            lg[u] += lg[v];
        }

        int L = g[u][0];
        int R = g[u][1];

        add[L] += wg[u] * 1LL * lg[R];
        add[R] += wg[u] * 1LL * lg[L];
    };

    dfs1(root);

    function<void(int, ll)> dfs2 = [&](int u, ll cur) {
        cur += add[u];

        if (u <= n) {
            ans[u] = cur;
            return;
        }

        for (int v : g[u]) {
            dfs2(v, cur);
        }
    };

    dfs2(root, 0);

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}
 
signed main() {
    Code By Vaibhav
    int t; cin >> t; while (t-- > 0)
        solve();
    return 0;
}