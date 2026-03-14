#include<bits/stdc++.h>
using namespace std;

int main () {
    int n; cin >> n;
    double ans = 0; 

    for (int i = 0; i < n; i++) {
        double a; cin >> a;
        ans += a;
    }

    cout << ans / n << endl;

    return 0;
}