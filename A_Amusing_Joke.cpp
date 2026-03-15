#include<bits/stdc++.h>
using namespace std;

int main () {
    string a, b, s; cin >> a >> b >> s;
    string temp = a + b;
    sort(temp.begin(), temp.end());
    sort(s.begin(), s.end());

    cout << (temp == s ? "YES" : "NO") << endl;

    return 0;
}