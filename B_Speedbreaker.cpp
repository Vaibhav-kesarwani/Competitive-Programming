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
int n;
int a[N];
vi vc[N];
int vis[N];
void add(int l, int r) {
	if(l <= r)
		vis[l] += 1, 
		vis[r + 1] -= 1;
}
void Main() {
	cin >> n;
	L(i, 1, n) {
		cin >> a[i];
		vc[a[i]].pb(i);
	}
	int l = n + 1, r = 0;
	L(t, 1, n) {
		for(auto u : vc[t]) {
			l = min(l, u);
			r = max(r, u);
		}
		if(!r)continue;
		if(r - l + 1 > t) {
			add(1, n);
		}
		add(1, r - t);
		add(l + t, n);
	}
	L(i, 1, n) {
		vis[i] += vis[i - 1];
	}
	int ans = 0;
	L(i, 1, n) {
		if(!vis[i]) {
			++ans;
		}
	}
	cout << ans << '\n';
	L(i, 0, n + 1) {
		vis[i] = 0;
		vc[i].clear();
	}
}
int main () { 
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie (0);
	int t; cin >> t; while(t--) Main();
	return 0;
}
