#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

void solve() {
    int n, k;
    std::cin >> n >> k;
    
    std::map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        cnt[a]++;
    }
    
    std::vector<int> c;
    for (auto [_, x] : cnt) {
        c.push_back(x);
    }
    std::sort(c.begin(), c.end());
    int ans = c.size();
    for (int i = 0; i < c.size() - 1; i++) {
        if (k >= c[i]) {
            ans--;
            k -= c[i];
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