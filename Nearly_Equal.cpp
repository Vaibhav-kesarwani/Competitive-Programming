#include <bits/stdc++.h>
using namespace std;
#define int long long
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(0);
#define Vaibhav cout.tie(0);
#define nt << "\n";
#define YES cout << "YES"
#define NO cout << "NO"
#define yes cout << "Yes"
#define No cout << "No"
const long double pi = 3.141592653589793238;
const int INF = LONG_LONG_MAX;
const int mod = 1000000007;
int gcd(int a, int b){if (b == 0)return a;return gcd(b, a % b);}
int lcm(int a, int b){return (a/gcd(a,b)*b);}


void Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai() {
    int n1, n2; cin >> n1 >> n2;
    string s1, s2; cin >> s1 >> s2;
    int cnt = 0;
    int possible_substring = (n1 - n2) + 1;
    int mini = INF;
    for (int i = 0; i <= n1 - n2; i++) {
        string temp = s1.substr(i, n2);
        int cnt = 0;
        for (int j = 0; j < n2; j++) {
            if (temp[j] != s2[j]) cnt++;
        }
        mini = min(mini, cnt);
    }

    cout << mini nt
}

signed main () {
    Code By Vaibhav
    int Bhai_Test_Case_Hai_Ya; cin >> Bhai_Test_Case_Hai_Ya; while (Bhai_Test_Case_Hai_Ya-- > 0)
        Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai();

    return 0;
}