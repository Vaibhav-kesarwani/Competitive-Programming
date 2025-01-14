 #include <bits/stdc++.h>
#define ALL(x) begin(x), end(x)
using namespace std;
void file() {
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);
}
using ll = long long;

const ll kInfl = 1e18;
const int kN = 2e5 + 5;
int n;
array<ll, kN> a, pre;
vector<ll> ans;

ll Query(int l, int r) { return pre[r] - pre[l - 1]; }

void Push(ll l, ll r) {
  for(ll i = l; i <= r; i++) {
    ans.push_back(i);
  }
}

void Case1(int l, int r) {
  ll mn, mx, ansl = 0, ansr = 0;
  mn = mx = pre[l - 1];
  for(int i = l; i <= r; i++) {
    ansl = min(ansl, pre[i] - mx);
    ansr = max(ansr, pre[i] - mn);
    mn = min(mn, pre[i]);
    mx = max(mx, pre[i]);
  }
  Push(ansl, ansr);
}

void Case2(int x) {
  ll lx, ln, rx, rn;
  lx = rx = -kInfl, ln = rn = kInfl;
  for(int i = x; i; i--) {
    ll val = Query(i, x);
    lx = max(lx, val), ln = min(ln, val);
  }
  for(int i = x; i <= n; i++) {
    ll val = Query(x, i);
    rx = max(rx, val), rn = min(rn, val);
  }
  Push(ln + rn - a[x], lx + rx - a[x]);
}

void Solve() {
  cin >> n, ans.clear();
  for(int i = 1; i <= n; i++) {
    cin >> a[i], pre[i] = pre[i - 1] + a[i];
  }
  int p = 1;
  for(int i = 1; i <= n; i++) {
    if(abs(a[i]) != 1) p = i;
  }
  Case1(1, p - 1), Case1(p + 1, n), Case2(p);
  sort(ALL(ans));
  ans.erase(unique(ALL(ans)), end(ans));
  cout << ans.size() << "\n";
  for(ll x : ans) cout << x << " ";
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