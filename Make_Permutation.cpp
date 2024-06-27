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
    vector<int> v(n);
    {
        int i = 0;
        do {
            cin >> v[i];
            i++;
        } while (i < n);
    }

    sort(v.begin(), v.end());
    vector<int> temp(n);
    {
        int i = 1;
        do {
            temp[i-1] = i;
            i++;
        } while (i <= n);
    }
    
    {
        int i = 0;
        do {
            if (v[i] > temp[i]) {
                no
                return;
            }
            i++;
        } while (i < n);
    }
    yes
}

signed main () {
    Code By Vaibhav
    int Bhai_Test_Case_Hai_Ya; cin >> Bhai_Test_Case_Hai_Ya;
    {
        int i = 0;
        do {
            Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai();
            i++;
        } while (i < Bhai_Test_Case_Hai_Ya);
    }

    return 0;
}
