 #include <bits/stdc++.h>
#define ALL(x) begin(x), end(x)
using namespace std;
void file() {
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);
}
using ll = long long;

const int kInf = 1e9;
const int kMod = 998244353;
void Add(int& x, int y) { ((x += y) >= kMod) && (x -= kMod); }

const int kN = 1e5 + 5, kV = 64;
int n, q;
array<int, kN> a;
array<array<int, kN>, kV> pre;

struct Info {
  int mn, c;
  Info() { mn = kInf, c = 0; }
  Info(int _mn, int _c) { mn = _mn, c = _c; }
};
array<array<Info, kV>, kV> dp;

Info operator + (Info x, Info y) {
  if(x.mn == y.mn) return Add(x.c, y.c), x;
  return (x.mn < y.mn) ? x : y;
}

void Query(int l, int r) {
  int len = r - l + 1;
  array<int, kV> cnt;
  for(int i = 0; i < kV; i++) {
    cnt[i] = pre[i][r] - pre[i][l - 1];
  }
  if(cnt[0]) return void(cout << len - 1 << " " << cnt[0] << "\n");
  if(*max_element(ALL(cnt)) >= 2) {
    ll sum = 0;
    for(int i = 0; i < kV; i++) {
      sum += (ll)cnt[i] * (cnt[i] - 1) / 2;
    }
    return void(cout << len - 2 << " " << sum % kMod << "\n");
  }
  for(auto& k : dp) k.fill(Info());
  for(int i = 1; i < kV; i++) {
    if(!cnt[i]) { dp[i] = dp[i - 1]; continue; }
    dp[i] = dp[i - 1];
    dp[i][i] = dp[i][i] + Info(1, 1);
    for(int j = 0; j < kV; j++) dp[i - 1][j].mn++;
    for(int j = 0; j < kV; j++) {
      dp[i][j] = dp[i][j] + dp[i - 1][i ^ j];
    }
  }
  if(dp[kV - 1][0].mn == kInf) return void(cout << "-1\n");
  cout << len - dp[kV - 1][0].mn << " " << dp[kV - 1][0].c << "\n";
}

void Solve() {
  cin >> n >> q;
  for(int i = 1; i <= n; i++) cin >> a[i];
  for(int i = 0; i < kV; i++) {
    for(int j = 1; j <= n; j++) {
      pre[i][j] = pre[i][j - 1] + (a[j] == i);
    }
  }
  for(int l, r; q--; ) cin >> l >> r, Query(l, r);
}

int main() {
  // file();
  ios::sync_with_stdio(0), cin.tie(0);
  int T = 1;
  // cin >> T;
  while(T--) Solve();
  return 0;
}