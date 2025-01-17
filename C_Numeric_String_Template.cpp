#include <bits/stdc++.h>
 
using namespace std;
 
#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<int> as = a;
    ranges::sort(as);
    as.resize(unique(as.begin(), as.end()) - as.begin());
    int cnt = int(as.size());
    for (int i = 0; i < n; i++) {
      a[i] = int(lower_bound(as.begin(), as.end(), a[i]) - as.begin());
    }
    int m;
    cin >> m;
    while (m--) {
      string s;
      cin >> s;
      if (int(s.size()) != n) {
        cout << "NO" << '\n';
        continue;
      }
      string mp(cnt, ' ');
      bool ok = true;
      for (int i = 0; i < n; i++) {
        if (mp[a[i]] == ' ') {
          mp[a[i]] = s[i];
        } else {
          ok &= (mp[a[i]] == s[i]);
        }
      }
      sort(mp.begin(), mp.end());
      for (int i = 0; i < cnt - 1; i++) {
        ok &= (mp[i] != mp[i + 1]);
      }
      cout << (ok ? "YES" : "NO") << '\n';
    }
  }
  return 0;
}