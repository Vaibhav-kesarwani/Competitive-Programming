/*
 * Author        :         vaibhav_404
 * Date          :         15-03-2026
 * Time          :         12:04
*/
 
#include <bits/stdc++.h>
using namespace std;
 
// Loop Macros
#define for0(i,n) for(int i = 0; i < (n); i++)
#define for1(i,l,r) for(int i = (l); i <= (r); i++)
#define rev(i,n) for(int i = (n)-1; i >= 0; i--)
#define forall(x,a) for(auto &x : a)
 
// Shorthand Macros
#define pb push_back
#define fi first
#define se second
#define nt << "\n";
#define YES cout << "YES"
#define NO cout << "NO"
#define yes cout << "yes"
#define no cout << "no"
#define Yes cout << "Yes"
#define No cout << "No"
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b)))
#define sz(a) int((a).size())
#define tr(c,i) for(__typeof__((c)).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
 
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
 
void solve() {
    int n; cin >> n;
    vi a(n); cin >> a;

    sort(all(a));
    int ans{};

    for0(i, n) {
        ll x = -a[i];
        usll seen;

        forall(i, a) {
            ll shift = i + x;
            if (shift >= 0) seen.insert(shift);
        }

        int maxi = 0;
        while (seen.count(maxi)) maxi++;
        ans = max(ans, maxi);
    }

    cout << ans nt
}
 
signed main() {
    Code By Vaibhav
    int t; cin >> t; while (t-- > 0)
        solve();
    return 0;
}