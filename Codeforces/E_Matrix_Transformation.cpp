 #include <bits/stdc++.h>
#define ALL(x) begin(x), end(x)
using namespace std;
void file() {
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);
}
using ll = long long;

const int kN = 1005;
int n, m;
array<array<int, kN>, kN> tmpA, tmpB;
array<array<bool, kN>, kN> a, b;
array<array<int, 3>, kN> cntR, cntC;
array<bool, kN> fR, fC;

void DfsR(int) ;
void DfsC(int) ;

void DfsR(int r) {
  fR[r] = 1;
  for(int i = 1; i <= m; i++) cntC[i][b[r][i]]--;
  for(int i = 1; i <= m; i++) {
    if(!fC[i] && !cntC[i][0]) DfsC(i);
  }
}

void DfsC(int c) {
  fC[c] = 1;
  for(int i = 1; i <= n; i++) cntR[i][b[i][c]]--;
  for(int i = 1; i <= n; i++) {
    if(!fR[i] && !cntR[i][1]) DfsR(i);
  }
}

bool Check() {
  fR.fill(0), fC.fill(0);
  for(int i = 1; i <= n; i++) cntR[i].fill(0);
  for(int i = 1; i <= m; i++) cntC[i].fill(0);
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      cntR[i][b[i][j]]++;
      cntC[j][b[i][j]]++;
    }
  }
  for(int i = 1; i <= n; i++) {
    if(!fR[i] && !cntR[i][1]) DfsR(i);
  }
  for(int i = 1; i <= m; i++) {
    if(!fC[i] && !cntC[i][0]) DfsC(i);
  }
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      if((a[i][j] != b[i][j]) && !fR[i] && !fC[j]) {
        return 0;
      }
    }
  }
  return 1;
}

void Solve() {
  cin >> n >> m;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) cin >> tmpA[i][j];
  }
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) cin >> tmpB[i][j];
  }
  for(int w = 0; w < 31; w++) {
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= m; j++) {
        a[i][j] = ((tmpA[i][j] >> w) & 1);
        b[i][j] = ((tmpB[i][j] >> w) & 1);
      }
    }
    if(!Check()) return void(cout << "No\n");
  }
  cout << "Yes\n";
}

int main() {
  // file();
  ios::sync_with_stdio(0), cin.tie(0);
  int T;
  cin >> T;
  while(T--) Solve();
  return 0;
}