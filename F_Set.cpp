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
  int n;
  cin >> n;
  vector<int> v(1 << n);
  for (int i = 1; i < (1 << n); i++) {
    cin >> v[i];
  }
  v[0] = 1;
  vector<vector<int>> a(n + 1);
  a[0] = v;
  for (int i = 1; i <= n; i++) {
    a[i].resize(1 << (n - i));
  }
  vector<int> res;
  auto Dfs = [&](auto&& self, int b, int num) {
    if (b == n) {
      if (a[b][0] > 0) {
        res.push_back(num);
      }
      return;
    }
    for (int val = 0; val < 2; val++) {
      for (int i = 0; i < (1 << (n - b - 1)); i++) {
        a[b + 1][i] = a[b][2 * i] & (a[b][2 * i + 1] >> val);
      }
      self(self, b + 1, num + (val << b));
    }
  };
  Dfs(Dfs, 0, 0);
  sort(res.begin(), res.end());
  cout << res.size() << '\n';
  for (int x : res) {
    cout << x << '\n';
  }
  return 0;
}
