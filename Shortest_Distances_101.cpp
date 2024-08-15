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
const int INF = 5e5 + 5;
const int mod = 1000000007;
int gcd(int a, int b){if (b == 0)return a;return gcd(b, a % b);}
int lcm(int a, int b){return (a/gcd(a,b)*b);}
const int LOG = 20;
#define inf 1e9

void Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai() {
    int a, b; 
    cin >> a >> b;
    int pchk[LOG][a+1]; 
    int valchk[a+1];    
    pair<int, int> stem[4*a+1]; 

    function<void(int, int, int)> help = [&](int l, int r, int x) {
        if (l == r) {
            stem[x] = {valchk[l], l};
            return;
        }
        int mid = (l + r) >> 1;
        help(l, mid, 2*x);
        help(mid + 1, r, 2*x + 1);
        stem[x] = max(stem[2*x], stem[2*x + 1]);
    };

    
    function<pair<int, int>(int, int, int, int, int)> help2 = [&](int l, int r, int x, int lx, int rx) -> pair<int, int> {
        if (l > rx || r < lx) return {-inf, -1};
        if (l >= lx && r <= rx) return stem[x];
        int mid = (l + r) >> 1;
        return max(help2(l, mid, 2*x, lx, rx), help2(mid + 1, r, 2*x + 1, lx, rx));
    };

    for (int i = 1; i <= a; i++) {
        cin >> valchk[i];
        valchk[i] = valchk[i] + i;
    }

    help(1, a, 1);

    for (int i = 1; i <= a; i++) {
        pchk[0][i] = help2(1, a, 1, i, valchk[i]).second;
    }

    for (int i = 1; i < LOG; i++) {
        for (int j = 1; j <= a; j++) {
            pchk[i][j] = pchk[i - 1][pchk[i - 1][j]];
        }
    }

    while (b--) {
        int x, y;
        cin >> x >> y;
        if (valchk[x] >= y) {
            cout << 1 nt
            continue;
        }
        int cnt = 0;
        for (int i = LOG - 1; i >= 0; i--) {
            if (valchk[pchk[i][x]] >= y) continue;
            x = pchk[i][x];
            cnt += (1LL << i);
        }
        if (valchk[pchk[0][x]] < y) {
            cout << -1 nt
            continue;
        }
        cout << cnt + 2 nt
    }
}

signed main () {
    Code By Vaibhav
    int Bhai_Test_Case_Hai_Ya; cin >> Bhai_Test_Case_Hai_Ya; while (Bhai_Test_Case_Hai_Ya-- > 0)
        Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai();

    return 0;
}
