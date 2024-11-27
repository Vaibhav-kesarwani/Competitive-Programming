#include <bits/stdc++.h>

using namespace std;

using li = long long;

int main() {
  int n;
  cin >> n;
  vector<li> a(n), b(n);
  for (auto& x : a) cin >> x;
  for (auto& x : b) cin >> x;
  vector<li> pr(n + 1, 0);
  for (int i = 0; i < n; ++i)
    pr[i + 1] = pr[i] + a[i] * b[i];
  li ans = pr[n];
  for (int c = 0; c < n; ++c) {
    li cur = a[c] * b[c];
    for (int l = c - 1, r = c + 1; l >= 0 && r < n; --l, ++r) {
      cur += a[l] * b[r];
      cur += a[r] * b[l];
      ans = max(ans, cur + pr[l] + (pr[n] - pr[r + 1]));
    }
    cur = 0;
    for (int l = c, r = c + 1; l >= 0 && r < n; --l, ++r) {
      cur += a[l] * b[r];
      cur += a[r] * b[l];
      ans = max(ans, cur + pr[l] + (pr[n] - pr[r + 1]));
    }
  }
  cout << ans << endl;
}