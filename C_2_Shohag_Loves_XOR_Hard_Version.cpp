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
    int64_t ans = 0;
    for (int y = 1; y <= 10 * x && y <= m; y++) {
      int v = x ^ y;
      if (v % x == 0 || v % y == 0) {
        ans += 1;
      }
    }
    int64_t low = 10 * x + 1;
    int64_t high = m;
    if (low <= high) {
      int64_t k_low = max<int64_t>(low / x - 10, 2);
      int64_t k_high = high / x + 10;
      auto Check = [&](int64_t k) {
        int64_t u = (k * x) ^ x;
        if (u >= low && u <= high) {
          ans += 1;
        }
      };
      while (k_low <= k_high && k_low * x < low + x) {
        Check(k_low);
        k_low += 1;
      }
      while (k_low <= k_high && k_high * x > high - x) {
        Check(k_high);
        k_high -= 1;
      }
      if (k_low <= k_high) {
        ans += k_high - k_low + 1;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
