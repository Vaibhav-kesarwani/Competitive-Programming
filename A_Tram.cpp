#include<bits/stdc++.h>
using namespace std;

int main () {
    int n; cin >> n;
    int maxi = 0, cnt = 0;

    while (n--) {
        int a, b; cin >> a >> b;
        cnt -= a; cnt += b;
        maxi = max(maxi, cnt);
    }

    cout << maxi << endl;

    return 0;
}