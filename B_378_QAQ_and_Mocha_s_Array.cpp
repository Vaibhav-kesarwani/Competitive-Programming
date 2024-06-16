#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    int g = 0;
    for (int i = 1; i < n; i++) {
      if (a[i] % a[0] != 0) {
        g = __gcd(g, a[i]);
      }
    }
    bool found = false;
    for (int i = 1; i < n; i++) {
      if (g % a[i] == 0) {
        found = true;
        break;
      }
    }
    cout << (found ? "YES" : "NO") << '\n';
  }
  return 0;
}
