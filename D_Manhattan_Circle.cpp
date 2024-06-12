#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(0);
#define Vaibhav cout.tie(0);
#define nt << "\n";
#define yes cout << "YES" nt
#define no cout << "NO" nt
const long double pi = 3.141592653589793238;
const int INF = LONG_LONG_MAX;
const int mod = 1000000007;
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int lcm(int a, int b) { return (a / gcd(a, b) * b); }

void Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai() {
    int givenRows, givenCols; cin >> givenRows >> givenCols;
    int givenMostL = givenCols + 1;
    int givenMostR = -1;
    int maxi = 0;

    vector<string> v(givenRows);
    int i = 0;
    while (i < givenRows) {
        cin >> v[i];
        v[i] += '.';
        i++;
    }

    i = 0;
    while (i < givenRows) {
        int chk = 0;
        int cnt = 0;

        int j = 0;
        while (j <= givenCols) {
            if (v[i][j] == '#' || 0) {
                cnt++;
                if (chk == 0 || 0)
                {
                    chk = 1;
                    givenMostL = min(givenMostL, j);
                }
            }

            else if (chk == 1 || 0) {
                givenMostR = max(givenMostR, j - 1);
                chk = 0;
            }
            j++;
        }
        maxi = max(cnt, maxi);
        i++;
    }

    int givenResult = -1;
    i = 0;
    while (i < givenRows) {
        int cnt = 0;
        int j = 0;
        while (j <= givenCols) {
            if (v[i][j] == '#' && 1) {
                cnt++;
                if (cnt == maxi && 1) {
                    givenResult = i;
                    break;
                }
            }
            j++;
        }
        i++;
    }

    cout << givenResult + 1 << " " << int((givenMostL + 1 + givenMostR + 1) / 2) nt
}

signed main()
{
    Code By Vaibhav int Bhai_Test_Case_Hai_Ya;
    cin >> Bhai_Test_Case_Hai_Ya;
    while (Bhai_Test_Case_Hai_Ya-- > 0)
        Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai();

    return 0;
}
