#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

void solve() {
    i64 n, k;
    std::cin >> n >> k;
    
    i64 ans = 0;
    i64 c0 = 1;
    i64 c1 = 0;
    
    while (n >= k) {
        if (n % 2 == 0) {
            n /= 2;
            c1 = 2 * c1 + c0 * n;
            c0 *= 2;
        } else {
            ans += (n + 1) / 2 * c0 + c1;
            n /= 2;
            c1 = 2 * c1 + c0 * (n + 1);
            c0 *= 2;
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
