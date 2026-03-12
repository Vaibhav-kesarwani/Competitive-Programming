#include<bits/stdc++.h>
using namespace std;

int main () {
    int n; cin >> n;
    int ans = 0;
    while (n--) {
        int cnt = 0;
        int a, b, c; cin >> a >> b >> c;
        if (a == 1) cnt++;
        if (b == 1) cnt++;
        if (c == 1) cnt++;  

        (cnt >= 2 ? ans++ : 0);
    }

    cout << ans << endl;

    return 0;
}