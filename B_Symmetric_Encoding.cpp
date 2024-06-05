#include <bits/stdc++.h>
using namespace std;
#define int long long
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(0);
#define Vaibhav cout.tie(0);
#define nt << "\n";
#define yes cout << "YES" nt
#define no cout << "NO" nt
const long double pi = 3.141592653589793238;
const int INF = LONG_LONG_MAX;
const int mod = 1000000007;
int gcd(int a, int b){if (b == 0)return a;return gcd(b, a % b);}
int lcm(int a, int b){return (a/gcd(a,b)*b);}


void Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai() {
    int n; cin >> n;
    string s; cin >> s;

    set<char> st;

    for (int i = 0; i < n; i++) st.insert(s[i]);

    vector<int> v;
    for (auto &ch : st) {
        v.push_back(ch);
    }

    map<char, char> mp;

    for (int i = 0; i < v.size(); i++) {
        mp[v[i]] = v[v.size() - i - 1];
    }

    for (int i = 0; i < n; i++) {
        cout << mp[s[i]];
    }

    cout nt
}

signed main () {
    Code By Vaibhav
    int Bhai_Test_Case_Hai_Ya; cin >> Bhai_Test_Case_Hai_Ya; while (Bhai_Test_Case_Hai_Ya-- > 0)
        Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai();

    return 0;
}