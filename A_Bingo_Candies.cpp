/*
vaibhav_404
*/

#include<bits/stdc++.h>
using namespace std;

int main () {
    int t; cin >> t;
    while (t-- > 0) {
        int n; cin >> n;
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int x; cin >> x;
                mp[x]++;
            }
        }

        int limit = n * n - n;
        bool chk = 1;

        for (auto const& [it, cnt] : mp) {
            if (cnt > limit) {
                chk = 0;
                break;
            }
        }

        cout << (n == 1 ? "NO" : chk ? "YES" : "NO") << endl;
    }

    return 0;
}