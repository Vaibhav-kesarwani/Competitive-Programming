#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n, k; cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    long long ans = -1e12;
    int l = max(1, n - 2 * k);
    for (int i = l; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
        ans = max(ans, 1LL * i * j - 1LL * k * (a[i] | a[j]));
      }
    }
    cout << ans << '\n';
  }
  return 0;
}