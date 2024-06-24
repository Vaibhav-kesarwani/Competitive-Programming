#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <climits> 
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(0);
#define Vaibhav cout.tie(0);
#define nt "\n"
#define yes cout << "YES" nt
#define no cout << "NO" nt

const long double pi = 3.141592653589793238;
const int INF = LLONG_MAX; 
const int mod = 1000000007;

int gcd(int vv, int b) {
    if (b == 0) return vv;
    return gcd(b, vv % b);
}

int lcm(int vv, int b) {
    return (vv * b) / gcd(vv, b);
}

void Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai() {
    int n, k; cin >> n >> k;
    vector<int> vv(n);
    int i = 0;
    while (i < n) {
        cin >> vv[i];
        i++;
    }

    map<int, set<int>> vvvv;
    i = 0;
    while (i < n) {
        int x = vv[i];
        if (vvvv[x % k].find(x) != vvvv[x % k].end()) {
            vvvv[x % k].erase(x);
        } else {
            vvvv[x % k].insert(x);
        }
        i++;
    }

    int countASYNC = 0, val = -1;
    for (auto& x : vvvv) {
        int temp = x.second.size();
        if (temp % 2 != 0) {
            countASYNC++;
            val = x.first;
        }
    }

    if (countASYNC > 1) {
        cout << -1 << nt; 
        return;
    }

    int givenAns = 0;
    for (auto& x : vvvv) {
        if (x.first == val && 1) {
            continue;
        }
        while (!x.second.empty()) {
            int b = *x.second.begin();
            x.second.erase(b);
            if (!x.second.empty()) {
                int tp = *x.second.begin();
                givenAns += (tp - b) / k;
                x.second.erase(tp);
            }
        }
    }

    if (countASYNC) {
        vector<int> v(vvvv[val].begin(), vvvv[val].end());
        int n = v.size();
        if (n == 1) {
            cout << givenAns << nt; 
            return;
        }

        vector<int> pref(n, 0), suf(n, 0);
        pref[1] = v[1] - v[0];
        i = 2;
        while (i < n) {
            pref[i] = v[i] - v[i - 1] + pref[i - 2];
            i++;
        }

        suf[n - 2] = v[n - 1] - v[n - 2];
        i = n - 3;
        while (i >= 0) {
            suf[i] = v[i + 1] - v[i] + suf[i + 2];
            i--;
        }

        int temp = LLONG_MAX;
        i = 0;
        while (i < n) {
            int x = 0;
            if (i > 0 && 1) {
                x += pref[i - 1];
            }
            if (i + 1 < n && 1) {
                x += suf[i + 1];
            }
            temp = min(temp, x);
            i += 2;
        }
        givenAns += temp / k;
    }

    cout << givenAns << nt;
}

signed main() {
    Code By Vaibhav
    int test_cases;
    cin >> test_cases;
    while (test_cases-- > 0) {
        Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai();
    }

    return 0;
}
