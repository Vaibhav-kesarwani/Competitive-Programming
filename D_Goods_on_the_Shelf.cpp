/*
 * Author        :         justDevil
 * Date          :         09-06-2026
 * Time          :         20:21
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
 
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM =
            chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};


void solve() {
    int n; cin >> n;
    vll a(n); cin >> a;

    unordered_map<ll, int, custom_hash> runs;
    runs.reserve(n * 2);

    vector<pii> segs;

    int l = 0;
    for (int i = 1; i <= n; i++) {
        if (i == n || a[i] != a[i - 1]) {
            segs.pb({l, i - 1});
            runs[a[l]]++;
            l = i;
        }
    }

    int excess = 0;
    int badCnt = 0;

    for (auto &p : runs) {
        excess += p.second - 1;
        if (p.second != 1) badCnt++;
    }

    if (badCnt == 0) {
        cout << "YES\n";
        return;
    }

    if (excess > 4) {
        cout << "NO\n";
        return;
    }

    unordered_set<ll, custom_hash> badVals;
    badVals.reserve(runs.size() * 2);

    for (auto &p : runs) {
        if (p.second > 1) badVals.insert(p.first);
    }

    vi cand;

    for (auto &[s, e] : segs) {
        if (!badVals.count(a[s])) continue;

        for (int x : {s - 1, s, s + 1, e - 1, e, e + 1}) {
            if (0 <= x && x < n) cand.pb(x);
        }
    }

    sort(all(cand));
    cand.erase(unique(all(cand)), cand.end());

    auto startOld = [&](int p) {
        return p == 0 || a[p] != a[p - 1];
    };

    auto goodAfterSwap = [&](int i, int j) -> bool {
        vll vals;
        vals.reserve(6);

        auto addVal = [&](int p) {
            if (0 <= p && p < n) vals.pb(a[p]);
        };

        for (int p : {i - 1, i, i + 1, j - 1, j, j + 1})
            addVal(p);

        sort(all(vals));
        vals.erase(unique(all(vals)), vals.end());

        unordered_map<ll, int, custom_hash> delta;
        delta.reserve(16);

        vi pos = {i, i + 1, j, j + 1};
        sort(all(pos));
        pos.erase(unique(all(pos)), pos.end());

        auto getNew = [&](int idx) -> ll {
            if (idx == i) return a[j];
            if (idx == j) return a[i];
            return a[idx];
        };

        for (int p : pos) {
            if (p < 0 || p >= n) continue;

            if (startOld(p))
                delta[a[p]]--;

            ll cur = getNew(p);

            bool st;
            if (p == 0)
                st = true;
            else
                st = (cur != getNew(p - 1));

            if (st)
                delta[cur]++;
        }

        int curBad = badCnt;

        for (ll v : vals) {
            int oldRuns = runs.find(v)->second;

            auto it = delta.find(v);
            int d = (it == delta.end() ? 0 : it->second);

            bool oldBad = (oldRuns != 1);
            bool newBad = (oldRuns + d != 1);

            if (oldBad) curBad--;
            if (newBad) curBad++;
        }

        return curBad == 0;
    };

    bool ok = false;

    for (int x : cand) {
        if (goodAfterSwap(x, x)) {
            ok = true;
            break;
        }
    }

    for (int i = 0; i < (int)cand.size() && !ok; i++) {
        for (int j = i + 1; j < (int)cand.size(); j++) {
            if (goodAfterSwap(cand[i], cand[j])) {
                ok = true;
                break;
            }
        }
    }

    cout << (ok ? "YES" : "NO") << '\n';
}


signed main() {
    Code By Vaibhav
    int t; cin >> t; while (t-- > 0)
        solve();
    return 0;
}