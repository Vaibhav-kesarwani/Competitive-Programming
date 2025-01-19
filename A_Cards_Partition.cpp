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
ll k, a[N];
void Main() {
	cin >> n >> k;
	L(i, 1, n) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	ll L = accumulate(a + 1, a + n + 1, 0LL);
	ll R = k + L;
	R(t, n, 1) {
		ll uset = R / t;
		if(uset * t < L) {
			continue;
		}
		if(a[n] > uset) {
			continue;
		}
		cout << t << '\n';
		return;
	}
}
int main () { 
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie (0);
	int t; cin >> t; while(t--) Main();
	return 0;
}
