#include<bits/stdc++.h>
using namespace std;

int main () {
    unordered_map<int, int> mp;

    for (int i = 0; i < 4; i++) {
        int n; cin >> n;
        mp[n]++;
    }

    cout << 4 - mp.size() << endl;

    return 0;
}