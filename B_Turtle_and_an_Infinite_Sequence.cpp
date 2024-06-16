#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    
    int l = std::max(0, n - m), r = n + m;
    
    int ans = 0;
    for (int i = 0; i <= 30; i++) {
        int u = l;
        if (~u >> i & 1) {
            u |= 1 << i;
            u &= ~((1 << i) - 1);
        }
        if (u <= r) {
            ans |= 1 << i;
        }
    }
    std::cout << ans << "\n";
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