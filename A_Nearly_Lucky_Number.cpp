#include<bits/stdc++.h>
using namespace std;

int main () {
    string s; cin >> s;
    int cnt = 0;

    for (char it : s) (it == '4' || it == '7' ? cnt++ : 0);

    cout << (cnt == 4 || cnt == 7 ? "YES" : "NO") << endl;

    return 0;
}