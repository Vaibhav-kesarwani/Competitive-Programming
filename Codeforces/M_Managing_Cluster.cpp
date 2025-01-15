#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for (int i = a; i < n; i++)
#define per(i, a, n) for (int i = n - 1; i >= a; i--)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef basic_string<int> BI;
typedef long long ll;
typedef pair<int, int> PII;
typedef double db;
mt19937 mrand(random_device{}());
const ll mod = 1000000007;
int rnd(int x) { return mrand() % x; }
ll powmod(ll a, ll b)
{
    ll res = 1;
    a %= mod;
    assert(b >= 0);
    for (; b; b >>= 1)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
    }
    return res;
}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
// head

const int N = 201000;
int n, a[N], mx[N], vis[N], opm[N], fix[N];
VI e[N];
vector<PII> mat;
set<int> pos[N];
int dfs(int u, int f)
{
    int mu = 0;
    for (auto v : e[u])
        if (v != f)
        {
            int mv = dfs(v, u);
            if (mv == 0 && mu == 0)
            {
                mat.pb(mp(u, v));
                mx[u] = mx[v] = SZ(mat) - 1;
                mu = 1;
            }
        }
    return mu;
}
void solve()
{
    scanf("%d", &n);
    rep(i, 1, n + 1)
    {
        pos[i].clear();
    }
    rep(i, 1, 2 * n + 1)
    {
        scanf("%d", &a[i]);
        e[i].clear();
        pos[a[i]].insert(i);
        mx[i] = -1;
        fix[i] = 0;
    }
    rep(i, 1, 2 * n)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        e[u].pb(v);
        e[v].pb(u);
    }
    mat.clear();
    dfs(1, 0);
    VI unm;
    rep(i, 1, 2 * n + 1) if (mx[i] == -1)
    {
        unm.pb(i);
    }
    for (int i = 0; i < SZ(unm); i += 2)
    {
        int u = unm[i], v = unm[i + 1];
        mat.pb(mp(u, v));
        mx[u] = mx[v] = SZ(mat) - 1;
    }
    rep(i, 0, n)
    {
        auto [u, v] = mat[i];
        // printf("mat %d %d\n",u,v);
        opm[u] = v;
        opm[v] = u;
        vis[i] = 0;
    }
    vector<PII> ret;
    rep(i, 0, n) if (!vis[i])
    {
        auto [u, v] = mat[i];
        fix[u] = 1;
        auto addswap = [&](int x, int y)
        {
            assert(!fix[x] && !fix[y]);
            fix[x] = 1;
            fix[y] = 1;
            ret.pb(mp(x, y));
            pos[a[x]].erase(x);
            pos[a[y]].erase(y);
            swap(a[x], a[y]);
            pos[a[x]].insert(x);
            pos[a[y]].insert(y);
        };
        while (1)
        {
            vis[mx[u]] = 1;
            int w = -1;
            for (auto y : pos[a[u]])
                if (y != u)
                {
                    w = y;
                    break;
                }
            if (w == v)
                break;
            addswap(w, v);
            u = w;
            v = opm[w];
        }
    }
    printf("%d\n", SZ(ret));
    for (auto [x, y] : ret)
        printf("%d %d\n", x, y);
}

int _;
int main()
{
    for (scanf("%d", &_); _; _--)
    {
        solve();
    }
}
