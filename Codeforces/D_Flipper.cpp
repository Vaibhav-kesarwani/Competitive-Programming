#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define sz(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define eb emplace_back



void solve() {
    int n; cin >> n;
    vector<int> p(n);
    for (auto &e : p) cin >> e;

    int r = 0;
    for (int i = 0; i < n; ++i) {
        if (p[min(n-1, r+1)] <= p[min(n-1, i+1)]) {
            r = i;
        }
    }
    vector<int> ans;
    for (int i = r + 1; i < n; ++i) ans.eb(p[i]);
    ans.eb(p[r]);
    for (int i = r-1; i >= 0; --i) {
        if (p[i] > p[0]) {
            ans.eb(p[i]);
        } else {
            for (int j = 0; j <= i; ++j) {
                ans.eb(p[j]);
            }
            break;
        }
    }
    for (auto e : ans) cout << e << ' ';
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    forn(tt, t) {
        solve();
    }
}