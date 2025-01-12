#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    i64 s = std::accumulate(a.begin(), a.end(), 0LL);
    i64 l = 0, r = 0;
    int ans = n;
    
    for (int i = 0; i < n; i++) {
        l += a[i];
        r += a[i];
        if (l > s) {
            ans++;
            l = a[i];
            r = s;
        } else if (r < 0) {
            ans++;
            l = 0;
            r = s + a[i];
        } else {
            l = std::max(l, 0LL);
            r = std::min(r, s);
        }
    }
    if (s > r) {
        ans++;
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
