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
    int n, x, y; cin >> n >> x >> y;
    string s; cin >> s;
    
    int ax = 0, ay = 0;
    
    int i = 1;
    
    while (i <= n) {
        switch(s[i-1]) {
            case 'U': 
                ay++; 
                break;
            case 'D': 
                ay--; 
                break;
            case 'L': 
                ax--; 
                break;
            case 'R': 
                ax++; 
                break;
        }
        
        int dis = abs(x - ax) + abs(y - ay);
        if(dis <= i && dis % 2 == i % 2) {
            Yes nt
            return;
        }
        
        i++;
    }
    
    No nt
}

signed main () {
    Code By Vaibhav
    int Bhai_Test_Case_Hai_Ya; cin >> Bhai_Test_Case_Hai_Ya; while (Bhai_Test_Case_Hai_Ya-- > 0)
        Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai();

    return 0;
}