#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

std::vector<int> construct(const std::string &s) {
    int n = s.size();
    std::vector<int> l, r;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'L') {
            l.push_back(i);
        } else {
            r.push_back(i);
        }
    }
    std::reverse(r.begin(), r.end());
    int i = 0, j = 0;
    
    std::vector<int> a(n, -1);
    std::set<int> sl, sr;
    int unkl = 0, unkr = 0;
    int curl = 0, curr = n - 1;
    while (i < l.size() && j < r.size()) {
        while (curl < l[i]) {
            if (a[curl] == -1) {
                unkl++;
            } else {
                sl.insert(a[curl]);
            }
            curl++;
        }
        while (curr > r[j]) {
            if (a[curr] == -1) {
                unkr++;
            } else {
                sr.insert(a[curr]);
            }
            curr--;
        }
        if (sl.size() + unkl < sr.size() + unkr) {
            a[l[i]] = sl.size() + unkl;
            if (l[i] > r[j]) {
                unkr--;
                sr.insert(a[l[i]]);
            }
            i++;
        } else {
            a[r[j]] = sr.size() + unkr;
            if (r[j] < l[i]) {
                unkl--;
                sl.insert(a[r[j]]);
            }
            j++;
        }
    }
    while (i < l.size()) {
        while (curl < l[i]) {
            if (a[curl] == -1) {
                unkl++;
            } else {
                sl.insert(a[curl]);
            }
            curl++;
        }
        a[l[i]] = sl.size() + unkl;
        i++;
    }
    while (j < r.size()) {
        while (curr > r[j]) {
            if (a[curr] == -1) {
                unkr++;
            } else {
                sr.insert(a[curr]);
            }
            curr--;
        }
        a[r[j]] = sr.size() + unkr;
        j++;
    }
    
    std::set<int> set;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'L' && a[i] != set.size()) {
            return {};
        }
        set.insert(a[i]);
    }
    set = {};
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 'R' && a[i] != set.size()) {
            return {};
        }
        set.insert(a[i]);
    }
    return a;
}

void solve() {
    int n;
    std::cin >> n;
    
    std::string s;
    std::cin >> s;
    
    int l = 0, r = n;
    while (l < n && s[l] == 'L') {
        l++;
    }
    while (r > 0 && s[r - 1] == 'R') {
        r--;
    }
    if (l != r && l == n - r) {
        std::vector<int> a(n);
        for (int i = 0; i < n; i++) {
            if (i < l) {
                a[i] = i;
            } else if (i >= r) {
                a[i] = n - 1 - i;
            } else {
                a[i] = l + 1;
            }
        }
        for (int i = 0; i < n; i++) {
            std::cout << a[i] << " \n"[i == n - 1];
        }
    } else {
        auto a = construct(s);
        if (a.empty()) {
            std::cout << -1 << "\n";
        } else {
            for (int i = 0; i < n; i++) {
                std::cout << a[i] << " \n"[i == n - 1];
            }
        }
    }
}

void brute(int n) {
    std::vector<int> a(n);
    std::map<std::string, int> possible;
    auto dfs = [&](this auto &&self, int i) -> void {
        if (i == n) {
            std::vector<bool> fl(n), fr(n);
            std::set<int> s;
            for (int i = 0; i < n; i++) {
                if (a[i] == s.size()) {
                    fl[i] = true;
                }
                s.insert(a[i]);
            }
            s = {};
            for (int i = n - 1; i >= 0; i--) {
                if (a[i] == s.size()) {
                    fr[i] = true;
                }
                s.insert(a[i]);
            }
            
            std::string S;
            auto dfs2 = [&](this auto &&self, int i) {
                if (i == n) {
                    // std::cerr << S << "\n";
                    // for (int i = 0; i < n; i++) {
                    //     std::cerr << a[i];
                    // }
                    // std::cerr << "\n";
                    // std::cerr << "\n";
                    
                    int l = 0, r = n;
                    while (l < n && S[l] == 'L') {
                        l++;
                    }
                    while (r > 0 && S[r - 1] == 'R') {
                        r--;
                    }
                    
                    int m = *std::max_element(a.begin(), a.end());
                    std::set s(a.begin(), a.end());
                    if (s.size() != m + 1) {
                        // std::cerr << S << "\n";
                        // for (int i = 0; i < n; i++) {
                        //     std::cerr << a[i];
                        // }
                        // std::cerr << "\n";
                        // std::cerr << "\n";
                        assert(l == n - r);
                    } else {
                        return;
                        assert(l != n - r || l == r);
                        std::cerr << S << "\n";
                        assert(!possible.contains(S));
                        possible[S]++;
                        for (int i = 0; i < n; i++) {
                            std::cerr << a[i];
                        }
                        std::cerr << "\n";
                        std::cerr << "\n";
                        
                        std::vector<int> ls, rs;
                        for (int i = 0; i < n; i++) {
                            if (S[i] == 'L') {
                                ls.push_back(a[i]);
                            } else {
                                rs.push_back(a[i]);
                            }
                        }
                        for (int i = 1; i < ls.size(); i++) {
                            assert(ls[i] > ls[i - 1]);
                        }
                        for (int i = 1; i < rs.size(); i++) {
                            assert(rs[i] < rs[i - 1]);
                        }
                        assert(construct(S) == a);
                    }
                    
                    return;
                }
                if (fl[i]) {
                    S += 'L';
                    self(i + 1);
                    S.pop_back();
                }
                if (fr[i]) {
                    S += 'R';
                    self(i + 1);
                    S.pop_back();
                }
            };
            dfs2(0);
            return;
        }
        for (int x = 0; x < n; x++) {
            a[i] = x;
            self(i + 1);
        }
    };
    dfs(0);
    
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    // for (int n = 1; n <= 8; n++) {
    //     brute(n);
    // }
    // return 0;
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}