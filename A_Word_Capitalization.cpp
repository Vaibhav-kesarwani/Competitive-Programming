#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    // your code goes here
    string s; cin >> s;

    if (!isupper(s[0])) {
        s[0] = toupper(s[0]);
    }

    cout << s << endl;
}
signed main(){
    // int t; cin >> t; while (t--)
    solve();

    return 0;
}