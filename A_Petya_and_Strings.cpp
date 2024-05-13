#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main () {
    string s1, s2; cin >> s1 >> s2;
    
    for (int i = 0; i < s1.length(); i++) {
        if(s1[i] >= 'A' && s1[i] <= 'Z')
            s1[i] = s1[i] - 'A' + 97;

        if(s2[i] >= 'A' && s2[i] <= 'Z')
            s2[i] = s2[i] - 'A' + 97;
    }

    for (int i = 0; i < s1.length(); i++) {
        if (s1[i] > s2[i]) {
            cout << "1" << endl;
            return 0;
        }
        if (s2[i] > s1[i]) {
            cout << "-1" << endl;
            return 0;
        }   
    }

    cout << "0" << endl;

    return 0;
}