#include<bits/stdc++.h>
using namespace std;

int main () {
    string s; cin >> s;
    vector<char> a;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] != '+') a.push_back(s[i]);
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < a.size(); i++) {
        cout << a[i];
        if (i != a.size() - 1) cout << "+";
    }

    return 0;
}