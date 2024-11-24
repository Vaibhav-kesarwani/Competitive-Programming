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
    int x;
    int64_t m;
    cin >> x >> m;
    int ans = 0;
    for (int y = 1; y <= 10 * x && y <= m; y++) {
      int v = x ^ y;
      if (v != 0 && (x % v == 0 || y % v == 0)) {
        ans += 1;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
