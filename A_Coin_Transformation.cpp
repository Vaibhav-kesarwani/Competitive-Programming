#include <bits/stdc++.h>
#define ALL(x) begin(x), end(x)
using namespace std;
void file() {
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);
}
using ll = long long;

map<ll, ll> mp;

ll Dfs(ll x) {
  if(x <= 3) return 1;
  if(mp.count(x)) return mp[x];
  return mp[x] = 2 * Dfs(x / 4);
}

void Solve() {
  ll n;
  cin >> n;
  cout << Dfs(n) << "\n";
}

int main() {
  // file();
  ios::sync_with_stdio(0), cin.tie(0);
  int T;
  cin >> T;
  while(T--) Solve();
  return 0;
}