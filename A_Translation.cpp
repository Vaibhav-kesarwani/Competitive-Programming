#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main () {
    string s1, s2; cin >> s1 >> s2;

    reverse(s2.begin(), s2.end());

    if (s1 != s2) cout << "NO";
    else cout << "YES";

    return 0;
}