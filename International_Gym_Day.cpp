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

int gcd(int a, int b) {
    switch(b == 0) {
        case 1: return a;
        case 0: return gcd(b, a % b);
    }
    return 0;
}

int lcm(int a, int b) { 
    return (a / gcd(a, b) * b); 
}

void Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai() {
    int a, b, c;
    cin >> a >> b >> c;

    switch (c >= b) {
        case 1:
            cout << 0 nt
            return;
        default:
            break;
    }

    int low = 0, high = c;
    int answer = -1;

    for (; low <= high;) {
        int mid = (low + high) / 2;
        double ab = (100 - a * mid) * b / 100.0;
        int ba = c - mid;

        switch (ab <= ba) {
            case 1:
                answer = mid;
                high = mid - 1;
                break;
            case 0:
                low = mid + 1;
                break;
        }
    }

    cout << (answer != -1 ? answer : -1) nt
}

signed main() {
    Code By Vaibhav int Bhai_Test_Case_Hai_Ya;
    cin >> Bhai_Test_Case_Hai_Ya;
    for (; Bhai_Test_Case_Hai_Ya-- > 0;)
        Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai();

    return 0;
}
