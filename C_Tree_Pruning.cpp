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
const int N = 1e6 + 7;
template < int N > struct stlca {
	int n;
	int ehd[N], ev[N * 2], enx[N * 2], eid;
	void Eadd(int u, int v) {
		enx[++eid] = ehd[u], ev[eid] = v, ehd[u] = eid;
	}
	void add(int u, int v) {
		Eadd(u, v);
		Eadd(v, u);
	}
	int q[N], s[N], fa[N], dep[N], top;
	int cs[20][N];
	void dfs1(int x) {
		++top, cs[0][q[x] = top] = fa[x];
		for(int i = ehd[x]; i; i = enx[i]) if(ev[i] != fa[x]) 
			dep[ev[i]] = dep[x] + 1, fa[ev[i]] = x, dfs1(ev[i]);
	}
	inline int cmin(int &x, int &y) {
		return dep[x] < dep[y] ? x : y;
	}
	int lca(int l, int r) {
		if(l == r) return l;
		l = q[l], r = q[r];
		if(l > r) swap(l, r);
		++l;
		int p = __lg(r - l + 1);
		return cmin(cs[p][l], cs[p][r - (1 << p) + 1]);
	}
	inline int dis(int x, int y) {
		return dep[x] + dep[y] - 2 * dep[lca(x, y)];
	}
	void mk(int xn) {
		n = xn, dfs1(1);
		L(i, 1, 19) L(j, 1, top - (1 << i) + 1) 
			cs[i][j] = cmin(cs[i - 1][j], cs[i - 1][j + (1 << (i - 1))]);
	}
	void clear() {
		L(i, 1, n) ehd[i] = 0, fa[i] = 0;
		top = 0, n = 0, eid = 0;
	}
} ;
stlca < N > st;

int n;
int a[N];
vi vc[N];
void Main() {
	st.clear();
	cin >> n;
	st.n = n;
	L(i, 1, n - 1) {
		int u, v;
		cin >> u >> v;
		st.add(u, v);
	}
	st.mk(n);
	L(i, 1, n) {
		vc[st.dep[i]].pb(i);
	}
	int ans = 0;
	L(i, 0, n) {
		sort(vc[i].begin(), vc[i].end(), [&] (int u, int v) {
			return st.q[u] < st.q[v];
		});
		int sum = 0;
		L(j, 0, sz(vc[i]) - 1) {
			sum += st.dep[vc[i][j]];
			if(j)sum -= st.dep[st.lca(vc[i][j - 1], vc[i][j])];
		}
		// cout << i << " : " << sz(vc[i]) << ' ' << sum << endl;
		ans = max(ans, sum);
	}
	cout << n - ans - 1 << '\n';
	L(i, 0, n + 1) {
		vc[i].clear();
	}
}
int main () { 
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie (0);
	int t; cin >> t; while(t--) Main();
	return 0;
}
