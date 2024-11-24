/**
 *    author:  tourist
 *    created: 23.11.2024 06:49:02
**/
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
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (int i = 0; i < m; i++) {
      cin >> a[i];
    }
    sort(a.rbegin(), a.rend());
    vector<int> p(n + 1);
    iota(p.begin(), p.end(), 0);
    for (int i = 2; i <= n; i++) {
      if (p[i] == i) {
        for (int j = i + i; j <= n; j += i) {
          if (p[j] == j) {
            p[j] = i;
          }
        }
      }
    }
    bool fail = false;
    vector<int> cnt(n);
    for (int i = 0; i < n; i++) {
      int x = i + 1;
      while (x > 1) {
        cnt[i] += 1;
        x /= p[x];
      }
      if (cnt[i] >= m) {
        fail = true;
      }
    }
    if (fail) {
      cout << -1 << '\n';
    } else {
      for (int i = 0; i < n; i++) {
        cout << a[cnt[i]] << " \n"[i == n - 1];
      }
    }
  }
  return 0;
}
