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
const int S = 4;
const ll inf = 1e18;
struct mat {
	ll f[4][4];
	mat(ll w = 0) {
		L(i, 0, 3) {
			L(j, 0, 3) {
				f[i][j] = -inf;
			}
		}
		L(i, 0, 3) f[i][i] = w;
	}
};
mat operator * (mat a, mat b) {
	mat c(-inf);
	L(i, 0, 3) L(j, 0, 3) L(k, 0, 3) c.f[i][j] = max(c.f[i][j], a.f[i][k] + b.f[k][j]);
	return c;
}
mat seg[N];
int a[N];
void build(int x, int L, int R) {
	if(L == R) {
		seg[x] = mat(-inf);
		L(a, 0, 1) L(b, 0, 1) seg[x].f[a * 2 + b][0 * 2 + b] = 0;
		return;
	}
	int mid = (L + R) >> 1;
	build(x * 2, L, mid);
	build(x * 2 + 1, mid + 1, R);
	seg[x] = seg[x * 2] * seg[x * 2 + 1];
}
void upd(int x, int L, int R, int p) {
	if(L == R) {
		L(a, 0, 1) L(b, 0, 1) L(c, 0, 1 - a) L(d, 0, min(c, 1 - b)) 
			seg[x].f[a * 2 + b][c * 2 + b + d] = c + d * ::a[p];
		return;
	}
	int mid = (L + R) >> 1;
	p <= mid ? upd(x * 2, L, mid, p) : upd(x * 2 + 1, mid + 1, R, p); 
	seg[x] = seg[x * 2] * seg[x * 2 + 1];
}
int n;
int ord[N];
void Main() {
	cin >> n;
	L(i, 1, n) {
		cin >> a[i];
	}
	L(i, 1, n) {
		ord[i] = i;
	}
	sort(ord + 1, ord + n + 1, [&] (int x, int y) {
		return a[x] < a[y];
	});
	build(1, 1, n);
	ll ans = 0;
	R(i, n, 1) {
		int p = ord[i];
		upd(1, 1, n, p);
		ans = max(ans, seg[1].f[0][1] + a[p]);
		ans = max(ans, seg[1].f[0][3] + a[p]);
	}
	cout << ans << '\n';
}
int main () { 
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie (0);
	int t; cin >> t; while(t--) Main();
	return 0;
}
