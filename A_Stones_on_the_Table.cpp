#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main () {
    int n; cin >> n;
    string s;
    for (int i = 0; i < n; i++) {
        char c; cin >> c;
        s.push_back(c);
    }

    int cnt = 0;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) cnt++;
    }

    cout << cnt;

    return 0;
}