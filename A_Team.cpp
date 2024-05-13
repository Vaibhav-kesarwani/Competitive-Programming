#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main () {
    int t; cin >> t;
    int cnt = 0;

    while (t--) {
        int chk = 0;
        int a[3];
        for (int i = 0; i < 3; i++) cin >> a[i];

        for (int i = 0; i < 3; i++) {
            if (a[i] == 1) {
                chk++;
            }
        }

        if (chk >= 2) {
            cnt++;
        }
    }

    cout << cnt << "\n";

    return 0;
}