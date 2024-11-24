#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long 
#define sz(a) ((int) (a).size())
#define pb emplace_back
#define me(a, x) memset(a, x, sizeof(a))
#define vi vector<int>
#define ull unsigned long long
#define i128 __int128
using namespace std;
const int N = 1e6 + 7, mod = 998244353, inv2 = (mod + 1) / 2;
struct mint {
	int x;
	inline mint(int o = 0) { x = o; }
	inline mint & operator = (int o) { return x = o, *this; }
	inline mint & operator += (mint o) { return (x += o.x) >= mod && (x -= mod), *this; }
	inline mint & operator -= (mint o) { return (x -= o.x) < 0 && (x += mod), *this; }
	inline mint & operator *= (mint o) { return x = (ll) x * o.x % mod, *this; }
	inline mint & operator ^= (int b) {
		mint w = *this;
		mint ret(1);
		for(; b; b >>= 1, w *= w) if(b & 1) ret *= w;
		return x = ret.x, *this;
	}
	inline mint & operator /= (mint o) { return *this *= (o ^= (mod - 2)); }
	friend inline mint operator + (mint a, mint b) { return a += b; }
	friend inline mint operator - (mint a, mint b) { return a -= b; }
	friend inline mint operator * (mint a, mint b) { return a *= b; }
	friend inline mint operator / (mint a, mint b) { return a /= b; }
	friend inline mint operator ^ (mint a, int b) { return a ^= b; }
};
inline mint qpow(mint x, int y = mod - 2) { return x ^ y; }
mint fac[N], ifac[N], inv[N];
void init(int x) {
	fac[0] = ifac[0] = inv[1] = 1;
	L(i, 2, x) inv[i] = (mod - mod / i) * inv[mod % i];
	L(i, 1, x) fac[i] = fac[i - 1] * i, ifac[i] = ifac[i - 1] * inv[i];
} 
mint C(int x, int y) {
	return x < y || y < 0 ? 0 : fac[x] * ifac[y] * ifac[x - y];
}
inline mint sgn(int x) {
	return (x & 1) ? mod - 1 : 1;
}
int n;
mint dp[N]; 
vi dv[N];
mint mut[N];
mint mu[N];
mint ns[N];
void Main() {
	cin >> n;
	cout << ns[n].x << '\n';
}
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int mx = 1e6;
	L(i, 1, mx)
		L(j, 1, mx / i)
			dv[i * j].pb(i);
	L(i, 1, mx)
		mu[i] = (i == 1);
	L(i, 1, mx)
		L(j, 2, mx / i)
			mu[i * j] -= mu[i];
	mint ans = 0;
	L(i, 1, mx) {
		for(int d : dv[i]) {
			mint qwq = 0;
			for(auto s : dv[d]) {
				qwq += mut[s];
			}
			qwq += dp[d];
			qwq += 1;
			qwq *= 2;
			dp[d] -= qwq;
			for(int nd : dv[i / d]) mut[d * nd] += qwq * mu[nd];
		}
		ans += dp[i] + 1;
		for(auto j : dv[i]) ans += mut[j];
		ns[i] = ans;
	}
	int t; cin >> t; while(t--) Main();
	return 0;
}