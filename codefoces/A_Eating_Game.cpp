#include<bits/stdc++.h>
using namespace std;

int main () {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        int maxi = 0, ans = 0;
        for (int i : a) maxi = max(maxi, i);
        for (int i : a) ans += i == maxi;

        cout << ans << endl;
    }

    return 0;
}