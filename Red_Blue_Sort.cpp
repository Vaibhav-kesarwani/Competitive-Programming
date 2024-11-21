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
int gcd(int a, int b){return (b == 0) ? a : gcd(b, a % b);}
int lcm(int a, int b){return (a/gcd(a,b)*b);}

void S() {
    int n; 
    cin >> n; 
    vector<int> p(n); 
    bool a = true; 
    int i = 0;

    while (i < n) { 
        cin >> p[i]; 
        a = (p[i] != i + 1) ? false : a; 
        i++;
    } 

    if (!(a)) {
        bool b = false; 
        i = 0;

        while (i < n) { 
            b = (p[i] == i + 1) ? true : b; 
            if (b) break; 
            i++;
        } 

        if (!(b)) {
            cout << n - 2 nt;
        } else {
            cout << n - 1 nt;
        }
        
    } else {
        cout << n nt;
    }
}

signed main () {
    Code By Vaibhav
    int t; 
    cin >> t; 
    while (t-- > 0)
        S();

    return 0;
}
