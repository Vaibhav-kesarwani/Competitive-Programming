#include<bits/stdc++.h>
using namespace std;

int main () {
    string a, b; cin >> a >> b;

    if (a.size() != b.size()) {
        cout << "NO" << endl;
        return 0;
    }

    for (int i = 0, j = a.size() - 1; i < a.size(); i++) {
        if (a[j--] != b[i]) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;

    return 0;
}