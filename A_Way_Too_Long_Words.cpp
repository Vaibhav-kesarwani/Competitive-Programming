#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t; cin >> t;

    while (t--) {
        string s; cin >> s;
        int len = s.length();

        if (len > 10) {
            cout << s[0] << len - 2 << s[len - 1] << endl;
        }

        else cout << s << endl;
    }   

    return 0;
}