#include <iostream>
#include <algorithm>

static const int inf = 1e9;

void solve() {
    std::string a, b, res;
    std::cin >> a >> b >> res;
    int n = (int) a.size(), m = (int) b.size();
    int dp[n + 1][m + 1];
    std::fill(&dp[0][0], &dp[0][0] + (n + 1) * (m + 1), inf);
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        dp[i + 1][0] = dp[i][0] + (a[i] != res[i]);
    }
    for (int j = 0; j < m; j++) {
        dp[0][j + 1] = dp[0][j] + (b[j] != res[j]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = std::min(dp[i - 1][j] + (a[i - 1] != res[i + j - 1]),
                                dp[i][j - 1] + (b[j - 1] != res[i + j - 1]));
        }
    }
    std::cout << dp[n][m] << std::endl;
}

int main() {
    int tests;
    std::cin >> tests;
    while (tests--) {
        solve();
    }
}