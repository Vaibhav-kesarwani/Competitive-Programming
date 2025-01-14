#include <bits/stdc++.h>
 
using namespace std;

using li = long long;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<li> a(n), b(n);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;
    li mnA = *min_element(a.begin(), a.end());
    li sA = accumulate(a.begin(), a.end(), 0LL);
    li mnB = *min_element(b.begin(), b.end());
    li sB = accumulate(b.begin(), b.end(), 0LL);
    li ans = min(mnA * n + sB, mnB * n + sA);
    cout << ans << '\n';
  }
}