#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

constexpr int dx[] = {1, 0, -1, 0};
constexpr int dy[] = {0, 1, 0, -1};

void solve() {
    int n, m;
    std::cin >> n >> m;
    
    std::vector<std::string> s(n);
    for (int i = 0; i < n; i++) {
        std::cin >> s[i];
    }
    
    int tot = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '#') {
                tot++;
                for (int k = 0; k < 4; k++) {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if (x < 0 || x >= n || y < 0 || y >= m || s[x][y] != '#') {
                        tot++;
                    }
                }
            }
        }
    }
    
    for (int t = 0; t < 5; t++) {
        auto a = s;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((2 * i + j) % 5 == t && a[i][j] == '#') {
                    a[i][j] = 'S';
                    cnt++;
                }
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == '#') {
                    bool ok = false;
                    for (int k = 0; k < 4; k++) {
                        int x = i + dx[k];
                        int y = j + dy[k];
                        if (0 <= x && x < n && 0 <= y && y < m && a[x][y] == 'S') {
                            ok = true;
                        }
                    }
                    if (!ok) {
                        a[i][j] = 'S';
                        cnt++;
                    }
                }
            }
        }
        
        if (cnt * 5 <= tot) {
            for (int i = 0; i < n; i++) {
                std::cout << a[i] << "\n";
            }
            return;
        }
    }
    assert(false);
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