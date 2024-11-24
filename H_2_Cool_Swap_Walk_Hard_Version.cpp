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
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    vector<pair<int, int>> ps(n);
    for (int i = 0; i < n; i++) {
      ps[i] = {arr[i], i};
    }
    sort(ps.begin(), ps.end());
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
      b[ps[i].second] = i;
    }
    vector<string> ops;
    auto Do = [&](string& s) {
      assert(int(s.size()) == 2 * n - 2);
      assert(int(count(s.begin(), s.end(), 'R')) == n - 1);
      assert(int(count(s.begin(), s.end(), 'D')) == n - 1);
      ops.push_back(s);
      int i = 0, j = 0;
      for (char c : s) {
        if (c == 'R') {
          j += 1;
        } else {
          i += 1;
        }
        swap(arr[i], arr[j]);
      }
    };
    if (n == 4) {
      auto init = arr;
      vector<string> options = {"RDRDRD", "RRDDRD", "RDRRDD", "RRDRDD", "RRRDDD"};
      map<vector<int>, vector<string>> was;
      was[arr] = {};
      vector<vector<int>> que(1, arr);
      vector<int> win;
      for (int it = 0; it < int(que.size()); it++) {
        if (is_sorted(que[it].begin(), que[it].end())) {
          win = que[it];
          break;
        }
        for (auto& s : options) {
          arr = que[it];
          Do(s);
          if (was.find(arr) == was.end()) {
            que.push_back(arr);
            ops = was[que[it]];
            ops.push_back(s);
            was[arr] = ops;
          }
        }
      }
      arr = init;
      ops.clear();
      assert(!win.empty());
      for (auto& s : was[win]) {
        Do(s);
      }
    } else {
      int ptr = n - 1;
      if (n % 2 == 0 && b[0] == 0) {
        rotate(b.begin(), b.begin() + 1, b.end());
        string op;
        for (int i = 0; i < n - 1; i++) {
          op += "RD";
        }
        Do(op);
      }
      while (!is_sorted(b.begin(), b.end())) {
        rotate(b.begin(), b.begin() + 1, b.end());
        string op;
        for (int i = 0; i < n - 1; i++) {
          op += "RD";
        }
        for (int i = 0; i < n - 2; i++) {
          if (i == ptr) {
            continue;
          }
          if (b[i] > b[i + 1]) {
            swap(b[i], b[i + 1]);
            swap(op[2 * i + 1], op[2 * i + 2]);
          }
        }
        ptr = (ptr + n - 2) % (n - 1);
        Do(op);
        assert(int(ops.size()) <= n + 4);
      }
    }
    assert(is_sorted(arr.begin(), arr.end()));
    cout << ops.size() << '\n';
    for (auto& s : ops) {
      cout << s << '\n';
    }
  }
  return 0;
}
