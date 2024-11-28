#include <bits/stdc++.h>

using namespace std;

const int N = 1001;

int main() {
  vector<int> d(N, N);
  d[1] = 0;
  for (int i = 1; i < N; ++i) {
    for (int x = 1; x <= i; ++x) {
      int j = i + i / x;
      if (j < N) d[j] = min(d[j], d[i] + 1);
    }
  }
  
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> b(n), c(n);
    for (int &x : b) cin >> x;
    for (int &x : c) cin >> x;
    int sum = 0;
    for (int x : b) sum += d[x];
    k = min(k, sum);
    vector<int> dp(k + 1, 0);
    for (int i = 0; i < n; ++i) {
      for (int j = k - d[b[i]]; j >= 0; j--) {
        dp[j + d[b[i]]] = max(dp[j + d[b[i]]], dp[j] + c[i]);
      }
    }
    cout << *max_element(dp.begin(), dp.end()) << '\n';
  }
}