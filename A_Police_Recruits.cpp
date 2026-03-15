#include<bits/stdc++.h>
using namespace std;

int main () {
    int n; cin >> n;
    int sum = 0, ans = 0;
    
    while (n--) {
        int x; cin >> x;

        if (x == -1) {
            if (!sum) ans++;
            else sum--;
        }
        else sum += x;
    }

    cout << ans << endl;

    return 0;
}