#include <bits/stdc++.h>

using i64 = long long;

int query(int a, int b) {
    std::cout << "? " << a + 1 << " " << b + 1 << std::endl;
    std::string res;
    std::cin >> res;
    return res == "YES";
}

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> stk {0};
    for (int i = 1; i < n; i++) {
        if (query(stk.back(), i)) {
            stk.back() = i;
        } else if (stk.size() == 1 || query(stk[stk.size() - 2], i)) {
            stk.push_back(i);
        } else {
            int x = stk[stk.size() - 2] + 2;
            while (x < stk.back() && query(x, i)) {
                x++;
            }
            stk.back() = x - 1;
            stk.push_back(i - 1);
            stk.push_back(i);
        }
    }
    
    std::vector<int> c(n);
    int res = 0;
    for (int i = 0, j = 0; i < n; i++) {
        c[i] = res;
        if (j < stk.size() && stk[j] == i) {
            res ^= 1;
            j++;
        }
    }
    std::cout << "!";
    for (int i = 0; i < n; i++) {
        std::cout << " " << c[i];
    }
    std::cout << std::endl;
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