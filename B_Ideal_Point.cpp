#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    int L = 0, R = 55;
    while (n--) {
      int l, r;
      cin >> l >> r;
      if (l <= k && k <= r)
        L = max(L, l), R = min(R, r);
    }
    cout << (L == R ? "YES\n" : "NO\n");
  }
}