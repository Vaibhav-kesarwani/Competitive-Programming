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
const int N = 1 << 20;
int n;
int l[N], r[N];
int hd[N], nxt[N];
vi ql[N], qr[N];
int ans[N];
int id[N], op[N];
int seq[N];
int inc[N];
int f[N], siz[N], mn[N];
inline int find(int x) {
	return f[x] == x ? x : f[x] = find(f[x]);
}
int lst[N];
int check(int d) {
	if(d > n) 
		return 0;
	if(ans[d] != -1) {
		return ans[d];
	}
	L(i, 0, n * 2) f[i] = i, inc[i] = 0;
	int lst = 0;
	int now = 0;
	int cnt = 0;
	L(i, 1, n * 2) {
		for(int p = hd[i]; p; p = nxt[p]) if(l[p] > lst) {
			int u = find(l[p] - 1);
			++inc[i];
			if(!u) {
				++now;
			} else {
				--inc[u];
				if(!inc[u]) {
					f[u] = u - 1;
				}
			}
		}
		if(now >= d) {
			++cnt;
			lst = i;
			now = 0;
			while(find(i)) {
				int u = find(i);
				inc[u] = 0;
				f[u] = u - 1;
			}
		}
		if(!inc[i]) {
			f[i] = i - 1;
		}
	}
	return ans[d] = cnt;
}
void Main() {
	cin >> n;
	L(i, 1, n) ans[i] = -1;
	L(i, 1, n) {
		cin >> l[i];
	}
	L(i, 1, n) {
		cin >> r[i];
		nxt[i] = hd[r[i]];
		hd[r[i]] = i;
	}
	int ans = 0;
	for(int l = 1, r; l <= n; l = r + 1) {
		r = l;
		int v = check(l);
		if(!v) break;
		r = max(l, ans / v);
		int i = 0;
		while(check(r + (1 << i)) == v) r += 1 << i, ++i;
		while(i) {
			--i;
			if(check(r + (1 << i)) == v) 
				r += 1 << i;			
		}
		ans = max(ans, v * r);
		// cout << l << ' ' << r << endl;
	}
	cout << ans << '\n';
	L(i, 1, n * 2) {
		hd[i] = 0;
		nxt[i] = 0;
	}
}
int main () { 
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie (0);
	int t; cin >> t; while(t--) Main();
	return 0;
}
