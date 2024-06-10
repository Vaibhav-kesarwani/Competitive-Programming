#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    
    std::string s;
    std::cin >> s;
    
    std::vector<int> pre(n + 1);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + s[i] - '0';
    }
    std::vector<int> f(n + 1);
    f[n] = 1;
    for (int i = n - 1; i >= 0; i--) {
        int j = std::min(n, i + k);
        f[i] = f[j] && (pre[j] - pre[i] == j - i || pre[j] - pre[i] == 0) && (j == n || s[i] != s[j]);
    }
    
    for (int p = 1; p <= n; p++) {
        if (s[p - 1] != (((p - 1) / k % 2) ^ s[0])) {
            break;
        }
        if (f[p] && (p == n || s[p] == (((n - 1) / k % 2) ^ s[0]))) {
            std::cout << p << "\n";
            return;
        }
    }
    std::cout << -1 << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}