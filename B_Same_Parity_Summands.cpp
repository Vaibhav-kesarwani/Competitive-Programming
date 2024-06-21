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
    int n , k ; cin >> n >> k;
    
    if(k > n) {
        no
        return ;
    }

    if( (n - k + 1) & 1) {
        yes
        for(int i = 1 ; i < k ; i++) cout << 1 << " ";
        cout << n - k + 1 nt;
    }
    
    else if((n - 2 * (k - 1)) % 2 == 0 && (n - 2 * (k - 1)) > 0 ){
        yes
        for(int i = 1; i < k; i++)cout << 2 << " ";
        cout << n - 2 * (k - 1) nt;
    }

    else no
}

signed main () {
    Code By Vaibhav
    int Bhai_Test_Case_Hai_Ya; cin >> Bhai_Test_Case_Hai_Ya; while (Bhai_Test_Case_Hai_Ya-- > 0)
        Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai();

    return 0;
}