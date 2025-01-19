#include <bits/stdc++.h>

using i64 = long long;

constexpr i64 inf = 1E18;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    std::vector<int> b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
        b[i]--;
    }
    
    std::vector<i64> dp(n, inf);
    
    std::priority_queue<std::pair<i64, int>, std::vector<std::pair<i64, int>>, std::greater<>> q;
    q.emplace(0LL, 0);
    
    while (!q.empty()) {
        auto [d, i] = q.top();
        q.pop();
        
        if (dp[i] != inf) {
            continue;
        }
        dp[i] = d;
        
        q.emplace(d + a[i], b[i]);
        if (i > 0) {
            q.emplace(d, i - 1);
        }
    }
    
    i64 ans = 0;
    i64 sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        ans = std::max(ans, sum - dp[i]);
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