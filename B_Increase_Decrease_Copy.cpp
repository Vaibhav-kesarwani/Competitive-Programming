#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n), b(n + 1);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i <= n; i++) {
        std::cin >> b[i];
    }
    
    i64 ans = 1E9;
    for (int i = 0; i < n; i++) {
        ans = std::min<int>(ans, std::abs(a[i] - b[n]));
        ans = std::min<int>(ans, std::abs(b[i] - b[n]));
        if (std::min(a[i], b[i]) <= b[n] && b[n] <= std::max(a[i], b[i])) {
            ans = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        ans += std::abs(a[i] - b[i]);
    }
    std::cout << ans + 1 << "\n";
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