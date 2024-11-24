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
    string s;
    cin >> s;
    int n = int(s.size());
    string res = "-1";
    for (int i = 0; i < n - 1; i++) {
      if (s[i] == s[i + 1]) {
        res = s.substr(i, 2);
        break;
      }
    }
    for (int i = 0; i < n - 2; i++) {
      if (res == "-1" && s[i] != s[i + 2]) {
        res = s.substr(i, 3);
        break;
      }
    }
    cout << res << '\n';
  }
  return 0;
}
