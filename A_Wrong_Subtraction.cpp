#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main () {
    int x, y; cin >> x >> y;

    for (int i = 1; i <= y; i++) {
        if (x % 10 != 0) x--;
        else {
            x /= 10;
        }
    }

    cout << x << "\n";

    return 0;
}