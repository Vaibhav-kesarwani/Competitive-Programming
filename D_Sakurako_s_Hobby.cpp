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
    int n; cin >> n;

    vector<int> p(n);
    vector<int> F(n, 0);
    vector<bool> visited(n, false);
    string s;

    int i = 0;
    do {
        cin >> p[i];
        p[i]--;
        i++;
    } while (i < n);

    cin >> s;

    i = 0;
    do {
        if (!visited[i]) {
            vector<int> cycle;
            int black_count = 0;
            int x = i;

            do {
                visited[x] = true;
                cycle.push_back(x);
                switch (s[x]) {
                    case '0':
                        black_count++;
                        break;
                }
                x = p[x];
            } while (!visited[x]);

            int idx = 0;
            do {
                F[cycle[idx]] = black_count;
                idx++;
            } while (idx < cycle.size());
        }
        i++;
    } while (i < n);

    i = 0;
    do {
        cout << F[i] << " ";
        i++;
    } while (i < n);
    cout << endl;
}

signed main () {
    Code By Vaibhav
    int Bhai_Test_Case_Hai_Ya; cin >> Bhai_Test_Case_Hai_Ya; do {
        Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai();
        Bhai_Test_Case_Hai_Ya--;
    } while (Bhai_Test_Case_Hai_Ya > 0);

    return 0;
}
