#include<bits/stdc++.h>
using namespace std;

int main () {
    int t; cin >> t;
    while (t-- > 0) {
        int a, b; cin >> a >> b;
        cout << (a % b == 0 ? 0 : b - a % b) << endl;
    }

    return 0;
}