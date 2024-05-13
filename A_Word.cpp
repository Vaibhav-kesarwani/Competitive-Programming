#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    string s;
    cin >> s;
    int lower = 0, upper = 0;
    int len = s.length();

    for (int i = 0; i < len; i++) {
        if (islower(s[i]))
            lower++;
        else
            upper++;
    }

    if (upper > lower)
        for (int i = 0; i < len; i++)
            s[i] = toupper(s[i]);
    else
        for (int i = 0; i < len; i++)
            s[i] = tolower(s[i]);

    cout << s;

    return 0;
}