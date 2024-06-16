#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    i64 x = 1;
    for (int i = 0; i < n; i++) {
        x = std::lcm(x, 1LL * a[i]);
        if (x > 1E9) {
            break;
        }
    }
    auto it = std::find(a.begin(), a.end(), x);
    if (it == a.end()) {
        std::cout << n << "\n";
        return;
    }
    
    int ans = 0;
    auto check = [&](int d) {
        if (std::find(a.begin(), a.end(), d) != a.end()) {
            return;
        }
        int lcm = 1;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (d % a[i] == 0) {
                lcm = std::lcm(lcm, a[i]);
                cnt++;
            }
        }
        if (lcm == d) {
            ans = std::max(ans, cnt);
        }
    };
    
    for (int d = 1; d * d <= x; d++) {
        if (x % d == 0) {
            check(d);
            check(x / d);
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