#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    i64 ans = 0;
    for (int x = 0; x < 3; x++) {
        for (int y = x + 1; y < 3; y++) {
            std::map<std::pair<int, int>, int> cnt;
            for (int i = 0; i + 2 < n; i++) {
                ans += cnt[{a[i + x], a[i + y]}]++;
            }
        }
    }
    
    std::map<std::tuple<int, int, int>, int> cnt;
    for (int i = 0; i + 2 < n; i++) {
        ans -= 3 * cnt[{a[i], a[i + 1], a[i + 2]}]++;
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