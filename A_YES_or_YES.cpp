#include<bits/stdc++.h>
using namespace std;

int main () {
    int t; cin >> t;
    while (t-- > 0) {
        string s; cin >> s;
        transform(s.begin(), s.end(), s.begin(), ::tolower);

        cout << (s == "yes" ? "YES" : "NO") << endl;
    }

    return 0;
}