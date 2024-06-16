#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define sz(a) ((int) (a).size())
#define vi vector < int >
#define me(a, x) memset(a, x, sizeof(a))
#define ull unsigned long long
#define ld __float128
#define pb emplace_back
using namespace std;
const int mod = 1e9 + 7;
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
const int N = 127;
mint fac[N], ifac[N], inv[N];
void init(int x) {
	fac[0] = ifac[0] = inv[1] = 1;
	L(i, 2, x) inv[i] = (mod - mod / i) * inv[mod % i];
	L(i, 1, x) fac[i] = fac[i - 1] * i, ifac[i] = ifac[i - 1] * inv[i];
}
inline mint sgn(int x) {
	return (x & 1) ? mod - 1 : 1;
}
int n;
int c[N];
mint dp[N][N][N];
string S;
mint iC[N][N], C[N][N];
mint cur[N][N][N];
mint suf[N][13][N][N];
mint gs[N], v1[N], v2[N];
mint hap[N][N];
mint f[N], nf[N];
void Main() {
	cin >> n;
	L(i, 1, n) {
		cin >> c[i];
	}
	cin >> S;
	int emp = 0;
	L(i, 1, n) {
		if(S[i - 1] == '0') {
			++emp;
		}
	}
	if(!emp) {
		cout << 1 << '\n';
		return;
	}
	if(*max_element(c + 1, c + n + 1) == 1) {
		cout << 0 << '\n';
		return;
	}
	L(i, 1, n + 1) L(k, 0, i - 1) suf[i][0][k][0] = 1;
	R(i, n, 1) {
		int pick = c[i];
		L(j, 0, i - 1) {
			if(pick > j + n - i + 1) continue;
			if(!pick) {
				dp[i][j][0] += 1;
				continue;
			}
			L(k, 0, j + 1) gs[k] = v1[k] = v2[k] = 0;
			L(rs, 0, min(pick, 12)) {
				int ls = pick - rs;
				mint prob = C[j + 1][ls] / C[j + n - i + 1][pick];
				if(!prob.x)continue;
				int e = j + 1 - ls;
				L(d, 0, e) gs[ls + d] += suf[i + 1][rs][e][d] * prob;
			}
			L(k, 0, j + 1) v1[k] += gs[k] * (1 - hap[j + 1][k]);
			L(k, 1, j + 1) v2[k - 1] += gs[k] * hap[j + 1][k];
			mint mul = 1 / (1 - v2[0]); // ?
			v2[0] = 0;
			L(k, 1, j) if(v2[k].x) {
				int emp = j - k;
				L(l, 0, emp) v1[l + k] += v2[k] * dp[i][emp][l];
			}
			L(k, 0, j) dp[i][j][k] += v1[k] * mul;
		}
		L(j, 1, min(12, n - i + 1)) {
			L(k, 0, i - 1) {
				L(l, 0, k) gs[l] = suf[i + 1][j - 1][k][l];
				L(l, 0, k + 1) {
					suf[i][j][k][l] += suf[i + 1][j][k + 1][l] * (1 - hap[k + 1][l]);
					if(l) gs[l - 1] += suf[i + 1][j][k + 1][l] * hap[k + 1][l];
				} 
				L(l, 0, k) if(gs[l].x) {
					int emp = k - l;
					L(s, 0, emp) suf[i][j][k][l + s] += gs[l] * dp[i][emp][s];
				} 
			}
		}
	}
	// R(i, n, 1) {
	// 	L(j, 0, i - 1) {
	// 		cout << i << ' ' << j << " : ";
	// 		L(k, 0, j) {
	// 			cout << dp[i][j][k].x << ' ';
	// 		}
	// 		cout << endl;
	// 	}
	// 	cout << endl;
	// }
	// L(i, 0, 4) {
	// 	cout << suf[4][1][3][i].x << ' ';
	// }
	// cout << endl;
	me(f, 0);
	f[0] = 1;
	R(i, n, 1) {
		if(S[i - 1] == '1') {
			me(nf, 0);
			L(j, 0, emp) 
				L(k, 0, emp - j) 
					nf[j + k] += f[j] * dp[i][emp - j][k];
			swap(f, nf);
		} else {
			me(nf, 0);
			L(j, 0, emp) nf[j] = f[j] * (1 - hap[emp][j]);
			L(j, 0, emp - 1) { 
				mint mul = hap[emp][j + 1] * f[j + 1];
				L(k, 0, emp - j - 1) 
					nf[j + k] += mul * dp[i][emp - j - 1][k];
			}
			swap(f, nf);
			--emp;
		}
	}
	cout << (1 - f[0]).x << '\n';
	L(i, 0, n + 1) L(j, 0, n + 1) L(k, 0, j + 1) dp[i][j][k] = 0;
	L(i, 0, n + 1) L(j, 0, 12) L(k, 0, n + 1) L(l, 0, n + 1) suf[i][j][k][l] = 0;
}
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	init(123);
	L(i, 0, 123) C[i][0] = 1;
	L(i, 1, 123) L(j, 1, i) C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
	L(i, 0, 123) L(j, 0, i) iC[i][j] = 1 / C[i][j];
	L(i, 0, 123) L(j, 1, i) hap[i][j] = C[i - 1][j - 1] / C[i][j];
	int t; cin >> t; while(t--) Main();
	return 0;
}
