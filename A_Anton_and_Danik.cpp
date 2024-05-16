#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main () {
    int n; cin >> n;
    string s; cin >> s;
    int anton = 0, danik = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'A') anton++;
        else danik++;
    }
    if (anton > danik) cout << "Anton";
    else if (anton < danik) cout << "Danik";
    else cout << "Friendship";

    return 0;
}