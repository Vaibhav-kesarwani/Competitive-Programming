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
int lim;
bool Prime[N];
int p[N], tot;
void xxs(int x) {
	L(i, 2, x) {
		if(!Prime[i]) p[++tot] = i;
		for(int j = 1; p[j] * i <= x && j <= tot; ++j) {
			Prime[p[j] * i] = true;
			if(i % p[j] == 0) break;
		} 
	}
}
int calc_prm(int x) {
	x = min(x, lim);
	return upper_bound(p + 1, p + tot + 1, x) - p - 1;
}
int mx_prm(int x) {
	return upper_bound(p + 1, p + tot + 1, x) - p - 1;
}
template < int MX > struct Min_25 {
	function < mint(int, int)> fun; // rem
	vector < mint > buff; // rem
	int n, sq;
	bool Prime[N];
	int p[N], tot;
	ll w[N], id1[N], id2[N], tp;
	inline int getid(ll x) {
		return x <= sq ? id1[x] : id2[n / x];
	}
	void xxs(int x) {
		L(i, 2, x) {
			if(!Prime[i]) p[++tot] = i;
			for(int j = 1; p[j] * i <= x && j <= tot; ++j) {
				Prime[p[j] * i] = true;
				if(i % p[j] == 0) break;
			} 
		}
	}
	mint f[N], g[N];
	void solve(int NN) {
		n = NN;
		sq = sqrt(n);
		xxs(sq);
		for(ll l = 1, r; l <= n; l = r + 1) {
			r = n / (n / l);
			w[++tp] = n / l;
			if(w[tp] <= sq) id1[w[tp]] = tp;
			else id2[n / w[tp]] = tp;
		}
		L(kd, 0, sz(buff) - 1) {
			vector<mint>pd(kd + 2);
			L(i, 1, kd + 1) 
				pd[i] = qpow(i, kd);
			L(i, 1, kd + 1)
				pd[i] += pd[i - 1];
			L(i, 0, kd + 1) 
				L(j, 0, kd + 1) if(i != j) pd[i] /= i - j;
			L(i, 1, tp) {
				mint cur = 0, mul = 1;
				L(j, 0, kd + 1) {
					cur *= w[i] - j;
					cur += mul * pd[j];
					mul *= w[i] - j;
				}
				f[i] = cur - 1;
			}
			vector<mint>pref(tot + 1), V(tot + 1);
			L(i, 1, tot) 
				V[i] = qpow(p[i], kd), pref[i] = pref[i - 1] + V[i];
			L(i, 1, tot) 
				for(int j = 1; j <= tp && w[j] >= p[i] * p[i]; ++j) 
					f[j] -= (f[getid(w[j] / p[i])] - pref[i - 1]) * V[i];
			L(i, 1, tp) {
				g[i] += f[i] * buff[kd];
			}
		}
		L(i, 1, tp) g[i] += calc_prm(w[i]);
		vector<mint>ss(sq + 1);
		L(i, 1, tot) ss[p[i]] = fun(i, 1);
		L(i, 1, sq) ss[i] += ss[i - 1];
		R(i, tot, 1) {
			vector<mint>hoho = {1};
			vi pw = {1};
			while((ll) pw.back() * p[i] <= n) {
				hoho.pb(fun(i, sz(pw))), pw.pb(pw.back() * p[i]);
			}
			for(int j = 1; j <= tp && w[j] >= p[i] * p[i]; ++j) {
				L(k, 1, sz(pw) - 1) {
					if(w[j] < pw[k])break;
					int val = w[j] / pw[k];
					g[j] += (g[getid(val)] - ss[min(val, p[i])] + (k > 1)) * hoho[k];
				}
			}
		}
		L(i, 1, tp) 
			g[i] += 1;
	}
};
template < int MX > struct Min_25_2 {
	int n, sq;
	bool Prime[N];
	int p[N], tot;
	ll w[N], id1[N], id2[N], tp;
	inline int getid(ll x) {
		return x <= sq ? id1[x] : id2[n / x];
	}
	void xxs(int x) {
		L(i, 2, x) {
			if(!Prime[i]) p[++tot] = i;
			for(int j = 1; p[j] * i <= x && j <= tot; ++j) {
				Prime[p[j] * i] = true;
				if(i % p[j] == 0) break;
			} 
		}
	}
	mint f[N], g[N];
	mint query(int v, int j) {
		// cout << v << " and " << j << endl;
		if(v < p[j]) return 0;
		if(v < (ll) p[j] * p[j]) return g[getid(v)] - j + 1;
		return query(v, j + 1) + query(v / p[j], j) + 1;
	}
	void solve(int NN) {
		n = NN;
		sq = sqrt(n);
		xxs(1e6);
		for(ll l = 1, r; l <= n; l = r + 1) {
			r = n / (n / l);
			w[++tp] = n / l;
			if(w[tp] <= sq) id1[w[tp]] = tp;
			else id2[n / w[tp]] = tp;
		}
		
		L(i, 1, tp) {
			f[i] = w[i] - 1;
		}
		vector<mint>pref(tot + 1), V(tot + 1);
		L(i, 1, tot) V[i] = 1, pref[i] = pref[i - 1] + V[i];
		L(i, 1, tot) 
			for(int j = 1; j <= tp && w[j] >=(ll) p[i] * p[i]; ++j) 
				f[j] -= (f[getid(w[j] / p[i])] - pref[i - 1]) * V[i];
		L(i, 1, tp) {
			g[i] = f[i];
			// cout << w[i] << " : " << g[i].x << endl;
		}
	}
};
Min_25 < (int)1e9 > f;
Min_25_2 < (int)1e9 > g;
int n, m;
int mxdep[N], outs[N];
vi e[N];
void dfs(int x, int fa) {
	mxdep[x] = 0;
	for(auto v : e[x]) if(v != fa) {
		dfs(v, x);
		mxdep[x] = max(mxdep[x], mxdep[v] + 1);
	}
}
int seq1[N], seq2[N];
int len[N];
void dfs2(int x, int fa) {
	vi qwq = vi{outs[x], 0};
	for(auto v : e[x]) if(v != fa) qwq.pb(mxdep[v] + 1);
	sort(qwq.begin(), qwq.end());
	reverse(qwq.begin(), qwq.end());
	len[x] = qwq[0] + qwq[1] + 1;
	L(o, 0, 1) {
		int mx = outs[x] + 1;
		for(auto v : e[x]) if(v != fa) outs[v] = max(outs[v], mx), mx = max(mx, mxdep[v] + 2);
		reverse(e[x].begin(), e[x].end());
	}
	for(auto v : e[x]) if(v != fa) {
		dfs2(v, x);
	}
}
ll sq, w[N], id1[N], id2[N], tp;
inline int getid(ll x) {
	return x <= sq ? id1[x] : id2[m / x];
}

int co[N];
int num_p;
mint cnt[N];
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	xxs(1e6);
	cin >> n >> m;
	L(i, 1, n - 1) {
		int u, v;
		cin >> u >> v;
		e[u].pb(v);
		e[v].pb(u);
	}
	dfs(1, 0);
	dfs2(1, 0);	
	// n = 1e2,m=1e9;
	// L(i, 1, n) len[i] = max(i, n / 2);
	sq = sqrt(m);
	lim = *max_element(len + 1, len + n + 1);
	f.buff = {mod - 1};
	f.fun = [&] (int pid, int k) -> mint {
		if(k != 1) return 0;
		if(p[pid] <= lim) return 0;
		return mod - 1;
	};
	f.solve(m);
	g.solve(m);
	// cout << "query = " << g.query(3, 1).x << endl;
	num_p = mx_prm(lim);
	for(ll l = 1, r; l <= m; l = r + 1) {
		r = m / (m / l);
		w[++tp] = m / l;
		if(w[tp] <= sq) id1[w[tp]] = tp;
		else id2[m / w[tp]] = tp;
	}
	L(i, 1, n) co[mx_prm(len[i])] += 1;
	// L(i, 1, num_p) {
	// 	cout << co[i] << ' ';
	// }
	// cout << endl;
	mint ret = 0;
	L(i, 1, tp) {
		mint qwq = f.g[i] - f.g[i + 1];
		if(!qwq.x) continue;
		int v = m / w[i];
		if(v <= lim / 2) {
			ret += qwq;
		} else {
			mint ans = 1;
			mint all = v;
			L(i, 1, num_p) {
				if(v >= p[i])all -= g.query(v / p[i], i) + 1; //, cout << v / p[i] << ' ' << i << "::" << g.query(v / p[i], i).x << endl;
				// cout << "all = " << all.x << endl;
				if(co[i])ans *= qpow(all, co[i]);
			}
			// L(j, 1, n) {
			// 	int cnt = 0;
			// 	L(x, 1, v) {
			// 		int win = 1;
			// 		L(y, 2, len[j])
			// 			win &= x % y != 0;
			// 		if(win)++cnt;
			// 	}
			// 	ans *= cnt;
			// }
			ret += ans * qwq;
		}
	}
	cout << ret.x << '\n';
	return 0;
}