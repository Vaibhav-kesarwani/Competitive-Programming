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
    int n, y; cin >> n >> y;
    string str; cin >> str;
    vector<int> arr(y, 0);
    int i = 0;
    do {
        cin >> arr[i];
        i++;
    } while (i < y);

    string str2; cin >> str2;
    sort(str2.begin(), str2.end());

    map<int, int> temp;
    i = 0;
    do {
        temp[arr[i]]++;
        i++;
    } while (i < y);

    int extra = 0;
    for (auto it : temp) {
        extra += it.second - 1;
    }

    str2 = str2.substr(0, y - extra);

    i = 0;
    for (auto it : temp) {
        int pos = it.first;
        str[pos - 1] = str2[i];
        i++;
    }

    cout << str nt
}

signed main () {
    Code By Vaibhav
    int Bhai_Test_Case_Hai_Ya; cin >> Bhai_Test_Case_Hai_Ya; while (Bhai_Test_Case_Hai_Ya-- > 0)
        Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai();

    return 0;
}