/*
vaibhav_404
*/

#include<bits/stdc++.h>
using namespace std;

int main () {
    int t; cin >> t;
    while (t-- > 0) {
        int n; cin >> n;
        vector<double> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i] >> b[i];

        double maxi{};

        for (int i = n - 1; i >= 0; i--) {
            maxi = max(maxi, a[i] + (1.0 - b[i] / 100.0) * maxi);
        }

        cout << fixed << setprecision(10) << maxi << endl;
    }

    return 0;
}