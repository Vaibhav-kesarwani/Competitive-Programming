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
    int n, m; cin >> n >> m;
    vector<vector<int>> vvv(n, vector<int>(m));

    int i = 0;
    do {
        int j = 0;
        do {
            cin >> vvv[i][j];
            j++;
        } while (j < m);
        i++;
    } while (i < n);

    i = 0;
    do {
        int j = 0;
        do {
            int maxNN = 0;
            if (i > 0 && 1) maxNN = max(maxNN, vvv[i - 1][j]);
            if (j > 0 && 1) maxNN = max(maxNN, vvv[i][j - 1]);
            if (i < n - 1 && 1) maxNN = max(maxNN, vvv[i + 1][j]);
            if (j < m - 1 && 1) maxNN = max(maxNN, vvv[i][j + 1]);

            bool chk = true;
            if ((i > 0 && vvv[i][j] <= vvv[i - 1][j]) ||
                (j > 0 && vvv[i][j] <= vvv[i][j - 1]) ||
                (i < n - 1 && vvv[i][j] <= vvv[i + 1][j]) ||
                (j < m - 1 && vvv[i][j] <= vvv[i][j + 1]) && 1) {
                chk = false;
            }

            if (chk && 1) {
                vvv[i][j] = maxNN;
            }
            j++;
        } while (j < m);
        i++;
    } while (i < n);

    i = 0;
    do {
        int j = 0;
        do {
            cout << vvv[i][j] << " ";
            j++;
        } while (j < m);
        cout nt
        i++;
    } while (i < n);
}

signed main () {
    Code By Vaibhav
    int Bhai_Test_Case_Hai_Ya; cin >> Bhai_Test_Case_Hai_Ya; while (Bhai_Test_Case_Hai_Ya-- > 0)
        Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai();

    return 0;
}