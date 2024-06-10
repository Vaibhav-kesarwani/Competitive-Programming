#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#else
#define debug(...) 42
#endif

template <typename T>
vector<int> y_function(int n, const T &s) {
  vector<int> y(n, n);
  int l = 0, r = 0;
  for (int i = 1; i < n; i++) {
    y[i] = (i > r ? 0 : min(r - i + 1, y[i - l]));
    while (i + y[i] < n && s[y[i]] == s[i + y[i]]) {
      y[i]++;
    }
    if (i + y[i] - 1 > r) {
      l = i;
      r = i + y[i] - 1;
    }
  }
  return y;
}

template <typename T>
vector<int> y_function(const T &s) {
  return y_function((int) s.size(), s);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    int n = int(s.size());
    vector<int> cnt(26);
    for (int i = 0; i < n; i++) {
      cnt[int(s[i] - 'a')] += 1;
    }
    if (cnt[0] == n) {
      cout << n - 1 << '\n';
      continue;
    }
    vector<int> pos;
    for (int i = 0; i < n; i++) {
      if (s[i] != 'a') {
        pos.push_back(i);
      }
    }
    int sz = int(pos.size());
    string ss = s.substr(pos[0]);
    auto y = y_function(ss);
    int64_t ans = 0;
    for (int x = 1; x <= sz; x++) {
      if (sz % x == 0) {
        int until = pos[x - 1];
        int len = until - pos[0] + 1;
        bool ok = true;
        for (int i = x; i < sz; i += x) {
          if (y[pos[i] - pos[0]] < len) {
            ok = false;
            break;
          }
        }
        if (ok) {
          int max_l = pos[0];
          int max_r = n - 1 - pos[sz - 1];
          int max_sum = n + 1;
          for (int i = x; i < sz; i += x) {
            max_sum = min(max_sum, pos[i] - pos[i - 1] - 1);
          }
          for (int l = 0; l <= max_l; l++) {
            int lim = min(max_r, max_sum - l);
            if (lim >= 0) {
              ans += lim + 1;
            }
          }
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
