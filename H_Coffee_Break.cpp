#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<i64> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    auto work = [&]() {
        std::vector<i64> ans(n);
        std::priority_queue<int> q;
        i64 x = 0;
        for (int i = 1; i <= n; i++) {
            i64 y = 0;
            if (i - 1 > 0) {
                q.push(i - 1);
            }
            while (!q.empty()) {
                int u = q.top();
                q.pop();
                
                if (i - u <= x) {
                    y += i - u - 1;
                    x -= i - u;
                } else {
                    y += x;
                    q.push(u + x);
                    x = 0;
                    break;
                }
            }
            if (q.empty()) {
                i64 t = x / i;
                y += t * (i - 1);
                x -= t * i;
                if (x > 0) {
                    y += x;
                    q.push(x);
                }
            }
            x = y;
            ans[i - 1] = x;
            x += a[i - 1];
        }
        return ans;
    };
    
    auto ans = work();
    std::reverse(a.begin(), a.end());
    auto ans2 = work();
    std::reverse(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        ans[i] += ans2[n - 1 - i];
        ans[i] += a[i];
        std::cout << ans[i] << " \n"[i == n - 1];
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