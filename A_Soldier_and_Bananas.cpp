#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main () {
    int k, n, w; cin >> k >> n >> w;
    int cost = 0;

    for (int i = 1; i <= w; i++) {
        cost += i * k;
    }

    if (cost > n) cout << cost - n;
    else cout << "0";

    return 0;
}