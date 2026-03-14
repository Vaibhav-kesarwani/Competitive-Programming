#include<bits/stdc++.h>
using namespace std;

int main () {
    int n; cin >> n;
    while (n++) {
        string s = to_string(n);
        set<char> st(s.begin(), s.end());

        if (st.size() == s.size()) {
            cout << n << endl;
            return 0;
        }
    }

    return 0;
}