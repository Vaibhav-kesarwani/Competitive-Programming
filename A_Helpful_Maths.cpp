#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main () {
    string s; cin >> s;
    vector<int> v;
    int cnt = 0;
    for (int i = 0; i < s.size(); i++) {
        if (isdigit(s[i])) {
            v.push_back(s[i] - '0');
            cnt++;
        }
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i == cnt - 1) break;
        cout << "+";
    }

    return 0;
}