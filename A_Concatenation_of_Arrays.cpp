#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<std::array<int, 2>> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i][0] >> a[i][1];
    }
    
    std::sort(a.begin(), a.end(),
        [&](auto x, auto y) {
            return x[0] + x[1] < y[0] + y[1];
        });
    for (int i = 0; i < n; i++) {
        std::cout << a[i][0] << " " << a[i][1] << " \n"[i == n - 1];
    }
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