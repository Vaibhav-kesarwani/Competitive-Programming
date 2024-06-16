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
    int foo;
    cin >> foo;
    string s;
    cin >> s;
    auto Dfs = [&](auto&& self, vector<int> a, int x) -> vector<int> {
      int n = int(a.size());
      if (n == 0) {
        return vector<int>();
      }
      sort(a.begin(), a.end());
      if (x == a[n - 1]) {
        int sz = 1;
        for (int i = n - 2; i >= 0; i--) {
          if (a[i] == a[n - 1]) {
            sz += 1;
          } else {
            break;
          }
        }
        if (sz == 1) {
          return vector<int>(1, a[n - 1]);
        }
        vector<vector<int>> b;
        int rest = n - sz;
        if (rest >= sz - 1) {
          b.assign(sz, vector<int>(1, a[n - 1]));
          int start = 1;
          int ptr = 1;
          for (int i = 0; i < rest; i++) {
            b[ptr].push_back(a[i]);
            if (i > 0 && a[i] != a[i - 1]) {
              start = ptr;
            }
            ptr += 1;
            if (ptr == sz) {
              ptr = start;
            }
          }
          vector<int> c(b.size());
          vector<int> any;
          for (int i = 0; i < int(b.size()); i++) {
            if (i == 0 || b[i] != b[i - 1]) {
              any.push_back(i);
            }
            c[i] = int(any.size()) - 1;
          }
          c.erase(c.begin());
          auto got = self(self, c, c.empty() ? -1 : c.back());
          got.push_back(0);
          vector<int> res;
          for (int x : got) {
            for (int y : b[any[x]]) {
              res.push_back(y);
            }
          }
          return res;
        }
        b.resize(rest + 1);
        for (int i = 0; i < sz; i++) {
          b[i % (rest + 1)].push_back(a[n - 1]);
        }
        if (sz % (rest + 1) == 1) {
          return b[0];
        }
        for (int i = 0; i < rest; i++) {
          b[i + 1].push_back(a[i]);
        }
        if (sz % (rest + 1) == 0) {
          vector<int> c(b.size());
          vector<int> any;
          for (int i = 0; i < int(b.size()); i++) {
            if (i == 0 || b[i] != b[i - 1]) {
              any.push_back(i);
            }
            c[i] = int(any.size()) - 1;
          }
          c.erase(c.begin());
          auto got = self(self, c, c.empty() ? -1 : c.back());
          got.push_back(0);
          vector<int> res;
          for (int x : got) {
            for (int y : b[any[x]]) {
              res.push_back(y);
            }
          }
          return res;
        }
        assert(sz % (rest + 1) >= 2);
        int skipped = (rest + 1) - (sz % (rest + 1));
        rotate(b.begin(), b.begin() + sz % (rest + 1), b.end());
        vector<int> c(b.size());
        vector<int> any;
        for (int i = 0; i < int(b.size()); i++) {
          if (i == 0 || b[i] != b[i - 1]) {
            any.push_back(i);
          }
          c[i] = int(any.size()) - 1;
        }
        auto got = self(self, c, c[skipped]);
        vector<int> res;
        for (int x : got) {
          for (int y : b[any[x]]) {
            res.push_back(y);
          }
        }
        return res;
      }
      // x != a[n - 1]
      int sz = 1;
      for (int i = n - 2; i >= 0; i--) {
        if (a[i] == a[n - 1]) {
          sz += 1;
        } else {
          break;
        }
      }
      vector<vector<int>> b;
      int rest = n - sz;
      if (rest >= sz) {
        b.assign(sz, vector<int>(1, a[n - 1]));
        int start = 0;
        int ptr = 0;
        for (int i = 0; i < rest; i++) {
          b[ptr].push_back(a[i]);
          if (i > 0 && a[i] != a[i - 1]) {
            start = ptr;
          }
          if (a[i] == x && ptr == sz - 1) {
            break;
          }
          ptr += 1;
          if (ptr == sz) {
            ptr = start;
          }
        }
        vector<int> c(b.size());
        vector<int> any;
        int last = -1;
        for (int i = 0; i < int(b.size()); i++) {
          if (i == 0 || b[i] != b[i - 1]) {
            any.push_back(i);
          }
          c[i] = int(any.size()) - 1;
          if (b[i].back() == x) {
            last = c[i];
          }
        }
        auto got = self(self, c, last);
        vector<int> res;
        for (int x : got) {
          for (int y : b[any[x]]) {
            res.push_back(y);
          }
        }
        return res;
      }
      b.resize(rest);
      for (int i = 0; i < sz; i++) {
        b[i % rest].push_back(a[n - 1]);
      }
      for (int i = 0; i < rest; i++) {
        b[i].push_back(a[i]);
      }
      rotate(b.begin(), b.begin() + sz % rest, b.end());
      vector<int> c(b.size());
      vector<int> any;
      int last = -1;
      for (int i = 0; i < int(b.size()); i++) {
        if (i == 0 || b[i] != b[i - 1]) {
          any.push_back(i);
        }
        c[i] = int(any.size()) - 1;
        if (b[i].back() == x) {
          last = c[i];
        }
      }
      auto got = self(self, c, last);
      vector<int> res;
      for (int x : got) {
        for (int y : b[any[x]]) {
          res.push_back(y);
        }
      }
      return res;
    };
    vector<int> a(foo);
    for (int i = 0; i < foo; i++) {
      a[i] = int(s[i] - 'a');
    }
    auto res = Dfs(Dfs, a, *max_element(a.begin(), a.end()));
    for (int x : res) {
      cout << char(x + 'a');
    }
    cout << '\n';
  }
  return 0;
}
