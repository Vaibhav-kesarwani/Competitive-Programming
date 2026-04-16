/*
 * Author        :         justDevil
 * Date          :         15-04-2026
 * Time          :         20:45
*/
 
#include <bits/stdc++.h>
using namespace std;
 
// Shorthand Macros
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define lcm(a,b) (a*(b/gcd(a,b)))
#define sz(a) int((a).size())
#define tr(c,i) for(__typeof__((c)).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
 
// Functions
int gcd(int a, int b) {
    while (b != 0) {
        a = a % b;
        swap(a, b);
    }
    return a;
}
 
// Fast IO
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(0);
#define Vaibhav cout.tie(0);
 
// Type aliases
using ll = long long;
using ull = unsigned long long;
using ld = long double;

using vi = vector<int>;
using vll = vector<ll>;
using vc = vector<char>;
using vs = vector<string>;

using pii = pair<int,int>;
using pll = pair<ll,ll>;

using vvi = vector<vi>;
using vvll = vector<vll>;
using vpii = vector<pii>;

using si = set<int>;
using sll = set<ll>;
using usi = unordered_set<int>;
using usll = unordered_set<ll>;

using mii = map<int,int>;
using mll = map<ll,ll>;
using umii = unordered_map<int,int>;
using umll = unordered_map<ll,ll>;
 
template<typename T>
istream& operator>>(istream &in, vector<T> &v) { for (auto &x : v) in >> x; return in; }
 
template<typename T>
ostream& operator<<(ostream &out, const vector<T> &v) { for (const auto &x : v) out << x << " "; return out; }

int MAX = 505;

void solve() {
    int n; cin >> n;
    vi a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    // vector<vector<int>> prev(MAX, vector<int> (MAX));
    int prev[MAX][MAX];
    memset(prev, 0, sizeof(prev));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            prev[j][i] = prev[j][i - 1];
        }

        prev[a[i]][i]++;
    }

    bool b[MAX][MAX];
    memset(b, false, sizeof(b));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j + i - 1 <= n; j++) {
            int r = j + i - 1;
            for (int k = j; k <= r; k++) {
                int x = a[k];
                if (prev[x][r] - prev[x][j - 1] == 1 and
                    (k == j or b[j][k - 1]) and
                    (k == r or b[k + 1][r])) {
                    b[j][r] = 1;
                    break;
                }
            }
        }
    }

    vi dp(MAX);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1];
        for (int j = 1; j <= i; j++) {
            if (b[j][i]) {
                int prev = (j >= 2) ? dp[j - 2] : 0;
                dp[i] = max(dp[i], prev + (i - j + 1));
            }
        }
    }

    cout << n - dp[n] << endl;
}
 
signed main() {
    Code By Vaibhav
    int t; cin >> t; while (t-- > 0)
        solve();
    return 0;
}