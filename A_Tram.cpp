#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main () {
    int n; cin >> n;
    int maxi = 0;
    int maxiie = 0;
    while (n-- > 0) {
        int x, y; cin >> x >> y;

        maxi = (maxi - x) + y;
        maxiie = max(maxiie, maxi);
    }
    cout << maxiie;

    return 0;
}