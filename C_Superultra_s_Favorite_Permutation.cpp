#include <bits/stdc++.h>
using namespace std;
#define int long long
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(0);
#define Vaibhav cout.tie(0);
#define nt << "\n";
#define yes cout << "YES"
#define no cout << "NO"
#define Yes cout << "Yes"
#define No cout << "No"
const long double pi = 3.141592653589793238;
const int INF = LONG_LONG_MAX;
const int mod = 1000000007;
int gcd(int a, int b){if (b == 0)return a;return gcd(b, a % b);}
int lcm(int a, int b){return (a/gcd(a,b)*b);}

void Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai() {
    int n;
    cin >> n;

    switch (n <= 4) {
        case true:
            cout << -1 << "\n";
            return;
    }

    vector<int> evens, odds;

    int i = 1;
    while (i <= n) {
        switch (i % 2) {
            case 0: evens.push_back(i); break;
            default: odds.push_back(i); break;
        }
        i++;
    }

    reverse(evens.begin(), evens.end());
    reverse(odds.begin(), odds.end());

    vector<int> res;
    int j = 0;
    while (j < odds.size()) {
        switch (odds[j] != 5) {
            case true: res.push_back(odds[j]); break;
        }
        j++;
    }

    switch (n >= 5) {
        case true:
            res.push_back(5);
            res.push_back(4);
            break;
    }

    int k = 0;
    while (k < evens.size()) {
        switch (evens[k] != 4) {
            case true: res.push_back(evens[k]); break;
        }
        k++;
    }

    int x = 0;
    while (x < res.size()) {
        cout << res[x] << " ";
        x++;
    }
    cout nt
}

signed main () {
    Code By Vaibhav
    int Bhai_Test_Case_Hai_Ya; cin >> Bhai_Test_Case_Hai_Ya; while (Bhai_Test_Case_Hai_Ya-- > 0)
        Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai();

    return 0;
}

