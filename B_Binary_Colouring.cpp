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
    int x;
    cin >> x;
    vector<int> a;
    while (x > 0) {
      if (x % 2 == 0) {
        a.push_back(0);
      } else {
        if ((x - 1) / 2 % 2 == 0) {
          a.push_back(1);
          x -= 1;
        } else {
          a.push_back(-1);
          x += 1;
        }
      }
      x /= 2;
    }
    cout << a.size() << '\n';
    for (int i = 0; i < int(a.size()); i++) {
      cout << a[i] << " \n"[i == int(a.size()) - 1];
    }
  }
  return 0;
}
