#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main () {
    int x; cin >> x;
    int cnt = 0;

    while (x != 0) {
        if (x % 10 == 4 || x % 10 == 7) cnt++;
        x /= 10;
    }
    if (cnt == 4 || cnt == 7) cout << "YES";
    else cout << "NO";

    return 0;
}