#include<bits/stdc++.h>
using namespace std;

int main () {
    int n; cin >> n;
    string s; cin >> s;

    transform(s.begin(), s.end(), s.begin(), ::tolower);

    set<int> st;
    for (char i : s) st.insert(i);

    cout << (st.size() == 26 ? "YES" : "NO") << endl;

    return 0;
}