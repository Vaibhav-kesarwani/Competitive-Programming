#include <bits/stdc++.h>

using i64 = long long;

constexpr int C = 210000;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::cout << std::fixed << std::setprecision(10);

    int n;
    std::cin >> n;
    
    std::vector<int> a[100];
    i64 sum = 0;
    
    for (int i = 0; i < n; i++) {
        int p, w;
        std::cin >> p >> w;
        if (p == 100) {
            sum += w;
        } else {
            a[p].push_back(w);
        }
    }
    
    std::vector<double> dp(C);
    dp[0] = 1;
    
    for (int p = 1; p < 100; p++) {
        std::sort(a[p].begin(), a[p].end(), std::greater());
        for (int i = 0; i < a[p].size() && i < 100 / (100 - p); i++) {
            int w = a[p][i];
            for (int j = C - 1; j >= w; j--) {
                dp[j] = std::max(dp[j], dp[j - w] * (p / 100.0));
            }
        }
    }
    
    double ans = 0;
    for (int i = 0; i < C; i++) {
        ans = std::max(ans, (i + sum) * dp[i]);
    }
    std::cout << ans << "\n";

    return 0;
}