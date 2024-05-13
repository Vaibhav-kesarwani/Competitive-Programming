#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main () {
    int x, y; cin >> x >> y;
    int cnt = 1;
    int lexi = 3 * x;
    int lexy = 2 * y;

    for (int i = 1; i <= 1000; i++) {
        if (lexi > lexy) {
            cnt = i;
            break;
        }
        else {
            lexi *= 3;
            lexy *= 2;
        }
    }

    cout << cnt;

    return 0;
}