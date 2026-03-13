#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main () {
    ll n, k; cin >> n >> k;

    while (k--) {
        int last = n % 10;

        if (last > 0) n--;
        else n /= 10;
    }

    cout << n << endl;

    return 0;
}