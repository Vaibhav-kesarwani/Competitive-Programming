 #include <bits/stdc++.h>
#define ALL(x) begin(x), end(x)
using namespace std;
void file() {
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);
}
using ll = long long;

void Solve() {
  int n, d;
  cin >> n >> d;
  vector<int> ans;
  ans.push_back(1);
  if((d % 3 == 0) || (n >= 3)) ans.push_back(3);
  if(d == 5) ans.push_back(5);
  if((d == 7) || (n >= 3)) ans.push_back(7);
  if(d % 9 == 0) ans.push_back(9);
  else if(d % 3 == 0) {
    if(n >= 3) ans.push_back(9);
  }else {
    if(n >= 6) ans.push_back(9);
  }
  for(int x : ans) cout << x << " ";
  cout << "\n";
}

int main() {
  // file();
  ios::sync_with_stdio(0), cin.tie(0);
  int T;
  cin >> T;
  while(T--) Solve();
  return 0;
}