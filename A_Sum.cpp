#include<bits/stdc++.h>
using namespace std;

int main () {
    int t; cin >> t;
    while (t-- > 0) {
        int a, b, c; cin >> a >> b >> c;
        int maxi = max({a, b, c});

        if (maxi == a) {
            if (a == b + c) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
        else if (maxi == b) {
            if (b == a + c) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
        else {
            if (c == a + b) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }

    return 0;
}