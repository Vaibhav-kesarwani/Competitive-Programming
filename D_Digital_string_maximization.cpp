#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s; cin >> s;
    for (int i = 0; i < s.size(); i++) {
        int best = s[i] - '0', pos = i;
        for (int j = i; j < min(i + 10, (int) s.size()); j++) {
            if (s[j] - '0' - (j - i) > best) {
                best = s[j] - '0' - (j - i);
                pos = j;
            }
        }
        while (pos > i) {
            swap(s[pos], s[pos - 1]);
            pos--;
        }
        s[i] = char(best + '0');
    }
    cout << s;
}

int main() {
    int TESTS = 1; cin >> TESTS;
    while (TESTS --> 0) {
        solve();
        cout << '\n';
    }
    return 0;
}