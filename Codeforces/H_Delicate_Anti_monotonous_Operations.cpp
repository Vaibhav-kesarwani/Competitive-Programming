#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

void solve() {
    int n, w;
    std::cin >> n >> w;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    i64 sum = std::accumulate(a.begin(), a.end(), 0LL);
    if ([&] {
        for (int i = 1; i < n; i++) {
            if (a[i] == a[i - 1]) {
                return false;
            }
        }
        return true;
    } () || sum >= 1LL * n * w - 1) {
        std::cout << std::accumulate(a.begin(), a.end(), 0LL) << " " << 0 << "\n";
        return;
    }
    
    if (w >= 3) {
        std::cout << 1LL * n * w - 1 << " ";
        
        auto calc = [&]() {
            int ans = 1E9;
            int l = 0, r = n;
            while (a[l] == w) {
                l++;
            }
            while (a[r - 1] == w) {
                r--;
            }
            
            int cnt = (a[l] == w) * 2;
            int len = (a[l] == w);
            for (int i = l + 1; i < r; i++) {
                if (a[i] == w) {
                    len++;
                    if (len == 1) {
                        cnt += 2;
                    } else if (len == 2) {
                        cnt--;
                    } else if (len % 2 == 1) {
                        cnt++;
                    }
                } else {
                    len = 0;
                }
                if (a[i - 1] == a[i]) {
                    int res = (r - l - 1) + (r - i - 1) + cnt;
                    if (a[i] == w) {
                        res--;
                    } else if (i - 2 >= l && a[i - 2] == w && (i - 2 == l || a[i - 3] != w) && i + 1 < r && a[i + 1] != w) {
                        res--;
                    }
                    ans = std::min(ans, res);
                }
            }
            if (l >= 2 || r <= n - 2) {
                ans = std::min(ans, r - l + 1 + cnt);
            }
            return ans;
        };
        
        int ans = calc();
        std::reverse(a.begin(), a.end());
        ans = std::min(ans, calc());
        
        std::cout << ans << "\n";
    } else {
        int ans = 2 * n;
        int dis = 0;
        for (int l = 0, r = 0; l < n; l = r) {
            while (r < n && a[l] == a[r]) {
                r++;
            }
            if (a[l] == 1) {
                ans--;
                dis += r - l - 1;
            }
        }
        std::cout << ans << " " << dis << "\n";
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
