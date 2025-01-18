#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;


int S(int n, int m) {
    if (m == 0) {
        return (n == 0);
    }
    int a = n - m;
    int b = (m + 1) / 2;
    return ((b - 1) & (a + b - 1)) == (b - 1);
}

void solve() {
    int k, m;
    std::cin >> k >> m;
    
    std::string s;
    std::cin >> s;
    
    k = std::count(s.begin(), s.end(), '1');
    
    int ans = 0;
    for (int i = 0; i < k; i++) {
        if (!S(k, i + 1)) {
            continue;
        }
        for (int d = 0; d < 30; d++) {
            int x = i | (1 << d);
            if (x < m) {
                int t = ~x & (-~x);
                int u = m - 1 - x;
                int v = u & x;
                if (v) {
                    int l = std::__lg(v);
                    u &= ~((1 << l + 1) - 1);
                    u |= ~x & ((1 << l) - 1);
                }
                if (~u & t) {
                    ans ^= 1 << d;
                }
            }
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