#include<bits/stdc++.h>
using namespace std;

int main () {
    string s; cin >> s;
    unordered_map<char, int> mp;
    for (int i = 0; i < s.size(); i++) mp[s[i]]++;

    cout << (mp.size() % 2 == 0 ? "CHAT WITH HER!" : "IGNORE HIM!") << endl;

    return 0;
}