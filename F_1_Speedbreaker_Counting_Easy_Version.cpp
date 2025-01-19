#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#define L(i, j, k) for(int i = (j); i <= (k); i++)
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define pb emplace_back
#define ull unsigned long long 
#define sz(a) ((int) a.size())
#define vi vector<int>
#define me(a, x) memset(a, x, sizeof(a))
using namespace std;
const int N = 507;
int mod;
struct fastmod {
  typedef unsigned long long u64;
  typedef __uint128_t u128;

  int m;
  u64 b;

  fastmod(int m) : m(m), b(((u128)1 << 64) / m) {}
  int reduce(u64 a) {
    u64 q = ((u128)a * b) >> 64;
    int r = a - q * m;
    return r < m ? r : r - m;
  }
} z(2);
struct mint {
	int x;
	inline mint(int o = 0) { x = o; }
	inline mint & operator = (int o) { return x = o, *this; }
	inline mint & operator += (mint o) { return (x += o.x) >= mod && (x -= mod), *this; }
	inline mint & operator -= (mint o) { return (x -= o.x) < 0 && (x += mod), *this; }
	inline mint & operator *= (mint o) { return x = z.reduce((ll) x * o.x), *this; }
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
mint g[N][N][2];
mint val[N];
void Main() {
	cin >> n >> mod;
	z = fastmod(mod);
	L(i, 0, n) L(j, 0, n) L(o, 0, 1) g[i][j][o] = 0;
	L(d, 0, n - 1) {
		// L(i, 1, d) {
		// 	L(j, 0, i) {
		// 		L(k, 0, i - j) {
		// 			mint foo = dp[i - 1][j][k];
		// 			L(nj, j, i) {
		// 				mint cur = foo;
		// 				L(nk, k, i - nj) {
		// 					dp[i][nj][nk] += cur;
		// 					if(k != nk)
		// 						cur *= d - i + 1;
		// 				}
		// 				if(nj != j) foo *= d - i + 1;
		// 			}
		// 		}
		// 	}
		// }
		L(i, 0, d) L(j, 0, d) L(o, 0, 1) g[i][j][o] = 0;
		g[0][0][0] = g[0][0][1] = 1;
		L(s, 1, d) L(i, 0, s) {
			int j = s - i;
			if(i)g[i][j][0] += g[i - 1][j][0] * (d - s + 1), g[i][j][1] += g[i - 1][j][0];
			if(j)g[i][j][0] += g[i][j - 1][1] * (d - s + 1), g[i][j][1] += g[i][j - 1][1] * (d - s + 1);
			// if(s == 1 && i == 1) {
			// 	cout << g[i][j][0].x << endl;
			// }
		}
		int len = n - d;
		mint sum = 0;
		L(i, 0, d)
			sum += g[i][d - i][0];
		// L(i, 0, d) {
		// 	cout << g[i][d - i][0].x << ' ';
		// }
		// cout << endl;
		L(j, 0, len - 1) {
			sum *= n - max(j, len - j - 1);
		}
		val[len] = sum;
	}
	val[0] = qpow(n, n);
	R(i, n, 1) L(j, i + 1, n) val[i] -= val[j] * (j - i + 1);
	L(i, 1, n) val[0] -= val[i];
	L(i, 0, n) {
		cout << val[i].x << ' ';
	}
	cout << '\n';
	L(i, 0, n) val[i] = 0;
}
int main () { 
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie (0);
	int t; cin >> t; while(t--) Main();
	return 0;
}
