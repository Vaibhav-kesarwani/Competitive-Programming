#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    std::string s;
    std::cin >> s;
    
    const int n = s.size();
    
    std::vector<int> pre(n + 1);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + (s[i] == '(' ? 1 : -1);
    }
    
    std::set<int> high;
    std::vector<std::vector<int>> vec(n + 1);
    for (int i = 0; i <= n; i++) {
        vec[pre[i]].push_back(i);
    }
    i64 ans = 0;
    for (int i = n, j = n; i >= 0; i--) {
        while (j > 2 * i) {
            for (auto x : vec[j]) {
                high.insert(x);
            }
            j--;
        }
        int cnt = 1;
        for (int k = 1; k < vec[i].size(); k++) {
            auto it = high.lower_bound(vec[i][k - 1]);
            if (it != high.end() && *it < vec[i][k]) {
                cnt = 0;
            }
            ans += cnt;
            cnt++;
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