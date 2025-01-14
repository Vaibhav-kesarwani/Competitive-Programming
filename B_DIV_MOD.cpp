#include <bits/stdc++.h>

//#define int long long
#define mp make_pair
#define x first
#define y second
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("fast-math")

typedef long double ld;
typedef long long ll;

using namespace std;

mt19937 rnd(143);

const ll inf = 1e9;
const ll M = 1e9;
const ld pi = atan2(0, -1);
const ld eps = 1e-4;

void solve() {
    int l, r, x;
    cin >> l >> r >> x;
    int ans = r / x + r % x;
    int m = r / x * x - 1;
    if(m >= l)ans = max(ans, m / x + m % x);
    cout << ans;
}

bool multi = true;

signed main() {
    //freopen("in.txt", "r", stdin);
    //freopen("in.txt", "w", stdout);
    int t = 1;
    if (multi) {
        cin >> t;
    }
    for (; t != 0; --t) {
        solve();
        cout << "\n";
    }
    return 0;
}