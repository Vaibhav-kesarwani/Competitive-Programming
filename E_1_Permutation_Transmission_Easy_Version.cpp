/*
 * Author        :         justDevil
 * Date          :         09-06-2026
 * Time          :         20:39
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
 
struct State {
    vvi A, B;
    vi ua, ub;
};

long long dfs(const vvi &origBits, const vvi &recvBits, State st) {
    int m = st.ua.size();
    if (m == 0) return 1;

    vvi sigA(m), sigB(m);

    for (int id = 0; id < m; id++) {
        int bit = st.ua[id];
        sigA[id].reserve(st.A.size());

        for (auto &cell : st.A) {
            int c = 0;
            for (int x : cell) c += origBits[bit][x];
            sigA[id].pb(c);
        }
    }

    for (int id = 0; id < m; id++) {
        int bit = st.ub[id];
        sigB[id].reserve(st.B.size());

        for (auto &cell : st.B) {
            int c = 0;
            for (int x : cell) c += recvBits[bit][x];
            sigB[id].pb(c);
        }
    }

    int pick = -1;
    vi cand;
    int best = 1e9;

    for (int i = 0; i < m; i++) {
        vi cur;

        for (int j = 0; j < m; j++) {
            if (sigA[i] == sigB[j]) cur.pb(j);
        }

        if (cur.empty()) return 0;

        if ((int)cur.size() < best) {
            best = (int)cur.size();
            pick = i;
            cand = move(cur);
        }
    }

    ll ans = 0;

    for (int jj : cand) {
        int ba = st.ua[pick];
        int bb = st.ub[jj];

        State nxt;

        vi nua, nub;

        for (int i = 0; i < m; i++) if (i != pick) nua.pb(st.ua[i]);
        for (int i = 0; i < m; i++) if (i != jj) nub.pb(st.ub[i]);

        nxt.ua = move(nua);
        nxt.ub = move(nub);

        bool ok = 1;

        for (int id = 0; id < (int)st.A.size(); id++) {
            vi a0, a1, b0, b1;

            for (int x : st.A[id]) {
                if (origBits[ba][x]) a1.pb(x);
                else a0.pb(x);
            }

            for (int x : st.B[id]) {
                if (recvBits[bb][x]) b1.pb(x);
                else b0.pb(x);
            }

            if (a0.size() != b0.size() || a1.size() != b1.size()) {
                ok = 0;
                break;
            }

            if (!a0.empty()) {
                nxt.A.pb(move(a0));
                nxt.B.pb(move(b0));
            }

            if (!a1.empty()) {
                nxt.A.pb(move(a1));
                nxt.B.pb(move(b1));
            }
        }

        if (ok) ans += dfs(origBits, recvBits, move(nxt));
    }

    return ans;
}

void solve() {
    int n; cin >> n;

    int m = 0;
    while ((1 << m) < n + 1) m++;

    vs rows(m); cin >> rows;

    vi cols(n, 0);

    for (int b = 0; b < m; b++) {
        for (int i = 0; i < n; i++) {
            if (rows[b][i] == '1')
                cols[i] |= (1 << b);
        }
    }

    vi tmp = cols;
    sort(all(tmp));

    for (int i = 0; i < n; i++) {
        if (tmp[i] == 0) {
            cout << 0 << endl;
            return;
        }
        if (i && tmp[i] == tmp[i - 1]) {
            cout << 0 << endl;
            return;
        }
    }

    vvi origBits(m, vi(n));
    vvi recvBits(m, vi(n));

    for (int x = 1; x <= n; x++) {
        for (int b = 0; b < m; b++) {
            origBits[b][x - 1] = (x >> b) & 1;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int b = 0; b < m; b++) {
            recvBits[b][i] = (cols[i] >> b) & 1;
        }
    }

    State st;
    st.A.pb(vi(n));
    st.B.pb(vi(n));

    iota(all(st.A[0]), 0);
    iota(all(st.B[0]), 0);

    st.ua.resize(m);
    st.ub.resize(m);

    iota(all(st.ua), 0);
    iota(all(st.ub), 0);

    cout << dfs(origBits, recvBits, move(st)) << endl;
}
 
signed main() {
    Code By Vaibhav
    int t; cin >> t; while (t-- > 0)
        solve();
    return 0;
}