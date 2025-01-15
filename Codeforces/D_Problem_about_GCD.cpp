 #include <bits/stdc++.h>
#define ALL(x) begin(x), end(x)
using namespace std;
void file() {
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);
}
using ll = long long;

void Solve() {
  ll l, r, g;
  cin >> l >> r >> g;
  l = (l + g - 1) / g, r /= g;
  ll ans = -1, pl, pr;
  for(ll i = l; i <= r; i++) {
    if(r - i + 1 <= ans) break;
    for(ll j = r; j >= i; j--) {
      if(j - i + 1 <= ans) break;
      if(__gcd(i, j) == 1) {
        pl = i, pr = j, ans = j - i + 1;
        break;
      }
    }
  }
  if(ans == -1) cout << "-1 -1\n";
  else cout << pl * g << " " << pr * g << "\n";
}

int main() {
  // file();
  ios::sync_with_stdio(0), cin.tie(0);
  int T;
  cin >> T;
  while(T--) Solve();
  return 0;
}