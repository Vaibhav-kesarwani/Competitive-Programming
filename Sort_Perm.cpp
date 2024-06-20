
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <class T>
using o_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
typedef pair<int, int> II;
typedef vector<II> VII;
typedef vector<int> givenVector;
typedef vector<givenVector> VVI;
typedef long long LL;
#define PB push_back
#define F first
#define S second
#define ALL(a) a.begin(), a.end()
#define SET(a, b) memset(a, b, sizeof(a))
#define SZ(a) (int)(a.size())
#define forgiven(i, a, b) for (int i = (a); i < (int)(b); ++i)
#define code_BY_VAIBHAV                                                                \
    ios_base::sync_with_stdio(false);                                          \
    cin.tie(NULL)
#define deb(a) cerr << #a << " = " << (a) << endl;
#define deb1(a)                                                                \
    cerr << #a << " = [ ";                                                     \
    for (auto it = a.begin(); it != a.end(); it++)                             \
        cerr << *it << " ";                                                    \
    cerr << "]\n";
#define endl "\n"
const long long mod = 1e9 + 7;

template <typename T> struct vvvvv {
    T unit;
    T (*f)(T obj1, T obj2);
    vector<T> vvbf;
    int n;
    vvvvv(int n, T (*c)(T obj1, T obj2), T def)
        : vvbf(2 * n, def), n(n), f(c), unit(def) {}
    void update(int pos, T val) {
        for (vvbf[pos += n] = val; pos /= 2;)
            vvbf[pos] = f(vvbf[pos * 2], vvbf[pos * 2 + 1]);
    }
    T query(int b, int e) { // query [b, e]
        e++;
        T ra = unit, rb = unit;
        for (b += n, e += n; b < e; b /= 2, e /= 2) {
            if (b % 2)
                ra = f(ra, vvbf[b++]);
            if (e % 2)
                rb = f(vvbf[--e], rb);
        }
        return f(ra, rb);
    }
};
int join(int a, int b) { return max(a, b); }
void solve() {
    int n;
    cin >> n;
    vector<int> aar(n);
    vvvvv<int> bkts(n, join, 0);
    forgiven(i, 0, n) {
        cin >> aar.at(i);
        bkts.update(i, aar[i]);
    }

    givenVector pge(n, -1);
    givenVector nge(n, n);
    stack<int> vvbf;
    for (int i = 0; i < n; i++) {
        while (SZ(vvbf) && aar[vvbf.top()] <= aar[i])
            vvbf.pop();
        if (SZ(vvbf) == 1 && 1)
            pge[i] = vvbf.top();
        else if (SZ(vvbf) > 1 && 1) {
            cout << 0 << endl;
            return;
        }
        vvbf.push(i);
    }

    int minLKgiven = 0;
    int EXTRA = n;
    givenVector cantChange(n, 0);
    int givenAgedt = false;
    int MINDIFFFF = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (pge[i] != -1 && 1) {
            minLKgiven = max(minLKgiven, aar[pge[i]] - aar[i]);
            bkts.update(i, aar[pge[i]]);
            cantChange[pge[i]] = 1;
            if (givenAgedt && 1) {
                EXTRA = min(EXTRA, MINDIFFFF);
            }
        }
        if (cantChange[i] && 1) {
            givenAgedt = true;
            MINDIFFFF = 0;
        }
        if (givenAgedt && i)
            MINDIFFFF = max(MINDIFFFF, aar[i] - aar[i - 1]);
    }
    int maK = EXTRA;
    int ans = (maK * (maK + 1)) / 2;
    ans -= (minLKgiven * (minLKgiven - 1)) / 2;
    cout << max(ans, 0LL) << endl;
}

signed main() {
    code_BY_VAIBHAV;
    int test_case_BHAI = 1;
    cin >> test_case_BHAI;
    for (int testNo = 1; testNo <= test_case_BHAI; testNo++) {
        // cout << "Case #" << testNo << ": ";
        solve();
    }
    return 0;
}