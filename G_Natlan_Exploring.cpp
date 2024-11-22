#include <bits/stdc++.h>
using namespace std;
using db = double;
using lb = long double;
using ull = unsigned long long;
using uint = unsigned int;
using ll = long long;
//using i128 = __int128;
//using ui128 = unsigned __int128;
#define REP(i, first, last) for(int i = (first); i <= (last); ++ i)
#define DOW(i, first, last) for(int i = (first); i >= (last); -- i)
// #define int long long
#define pb emplace_back
#define ob pop_back
#define pii pair<int, int>
#define MPR make_pair
#define fi first
#define se second
#define tpl tuple<int, int, int>
#define MTP make_tuple
#define poly vector<int>
#define polyp vector<pii>
#define polyt vector<tpl>
#define all(x) x.begin(), x.end()
#define CVR(a, q) memset(a, q, sizeof a)
#define CLR(a) memset(a, 0, sizeof a)
#define CPY(a, q) memcpy(a, q, sizeof a)
#define PCT __builtin_popcount
const int N = 2e5 + 5, M = 1e6 + 5;
const int mod1 = 1e9 + 7, mod2 = 998244353, mod = mod2;
const long long inf = 1e18;
const int dx[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
int a[N], f[N], g[N * 10];
poly d[N], c[N];
void Solve() {
	int n; cin >> n;
	REP(i, 1, n) cin >> a[i];
	REP(i, 1, n) {
		d[i].pb(a[i]);
		int x = a[i];
		REP(j, 2, x / j) {
			if(x % j == 0) {
				d[i].pb(j);
				if(j * j != a[i]) d[i].pb(a[i] / j);
			}
		}
		REP(j, 2, x / j) {
			if(x % j == 0) {
				c[i].pb(j);
				while(x % j == 0) x /= j;
			}
		}
		if(x != 1) c[i].pb(x);
	}
	f[1] = 1;
	for(int j : d[1]) g[j] = (g[j] + 1) % mod;
	REP(i, 2, n) {
		REP(j, 1, (1 << c[i].size()) - 1) {
			int p = 1, r = 0;
			REP(k, 0, (int)c[i].size() - 1) 
				if(j >> k & 1)
					p = p * c[i][k];
			if(PCT(j) & 1) f[i] = (f[i] + g[p]) % mod;
			else f[i] = (f[i] - g[p] + mod) % mod;
		}
		for(int j : d[i]) g[j] = (g[j] + f[i]) % mod;
	}
	cout << f[n] << '\n';
}
signed main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int T = 1;
//	cin >> T;
	while (T --) {
		Solve();
	}
	return 0;
}
