#include <bits/stdc++.h>
using namespace std;
#define int long long
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(0);
#define Vaibhav cout.tie(0);
#define nt << "\n";
#define mt cout << "! IMPOSSIBLE"
#define no cout << "NO"
#define Yes cout << "Yes"
#define No cout << "No"
const long double pi = 3.141592653589793238;
const int INF = LONG_LONG_MAX;
const int mod = 1000000007;
int gcd(int a, int b){if (b == 0)return a;return gcd(b, a % b);}
int lcm(int a, int b){return (a/gcd(a,b)*b);}

int help(int l, int r) {
    cout << "? " << l << " " << r nt
    cout.flush();
    int y;
    cin >> y;
    return y;
}

void Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai() {
    int n;
    cin >> n;
    string ans;
    int prev = 0;
    int cnt0 = 0;
    int i = 1;
    while (i < n) {
        int x = help(1, i + 1);
        if (prev == 0) {
            if (x == 0) {
                i++;
                continue;
            } else {
                if (x > i) {
                    mt nt
                    return;
                } else {
                    int j = 0;
                    while (j < i - x) {
                        ans.push_back('1');
                        j++;
                    }
                    j = 0;
                    while (j < x) {
                        ans.push_back('0');
                        j++;
                    }
                }
            }
            ans.push_back('1');
            cnt0 = x;
            prev = x;
        } else {
            if (x > prev) {
                if (x - prev == cnt0) {
                    ans.push_back('1');
                    prev = x;
                } else {
                    mt nt
                    return;
                }
            } else if (x == prev) {
                ans.push_back('0');
                cnt0++;
            } else {
                mt nt
                return;
            }
        }
        i++;
    }
    
    if (ans.size() < n) {
        mt nt
        return;
    }
    cout << "! " << ans nt
    cout.flush();
}

signed main () {
    Code By Vaibhav
    int Bhai_Test_Case_Hai_Ya; cin >> Bhai_Test_Case_Hai_Ya; 
    while (Bhai_Test_Case_Hai_Ya-- > 0)
        Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai();

    return 0;
}
