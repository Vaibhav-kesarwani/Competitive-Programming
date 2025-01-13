#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)

vector<pair<char,int>> split(string s) {
    char c = s[0];
    int cnt = 1;
    vector<pair<char,int>> result;
    auto ss = s.c_str();
    for (int i = 1; i <= int(s.length()); i++) {
        if (ss[i] != c) {
            result.push_back({c, cnt});
            c = s[i];
            cnt = 1;
        } else
            cnt++;
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    forn(tt, n) {
        string s, t;
        cin >> s >> t;
        auto sa(split(s)), ta(split(t));
        bool ok = sa.size() == ta.size();
        if (ok)
            forn(i, sa.size())
                if (sa[i].first != ta[i].first || sa[i].second > ta[i].second)
                    ok = false;
        cout << (ok ? "YES" : "NO") << endl;
    }
}