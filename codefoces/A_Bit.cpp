#include<bits/stdc++.h>
using namespace std;

int main () {
    int n; cin >> n;
    int ans = 0;
    while (n--) {
        string s; cin >> s;
        (s[1] == '+' ? ans++ : ans--);
    }

    cout << ans << endl;

    return 0;
}