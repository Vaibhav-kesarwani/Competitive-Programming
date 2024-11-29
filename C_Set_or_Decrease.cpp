#include<bits/stdc++.h>

using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define sz(a) int((a).size())

typedef long long li;

const int INF = int(1e9);
const li INF64 = li(1e18);

int n;
li k;
vector<int> a;

inline bool read() {
	if(!(cin >> n >> k))
		return false;
	a.resize(n);
	fore (i, 0, n)
		cin >> a[i];
	return true;
}

li accurateFloor(li a, li b) {
	li val = a / b;
	while (val * b > a)
		val--;
	return val;
}

inline void solve() {
	sort(a.begin(), a.end());
	vector<li> pSum(n + 1, 0);
	fore (i, 0, n)
		pSum[i + 1] = pSum[i] + a[i];
	
	li ans = 1e18;
	fore (y, 0, n) {
		//(a[0] - x)(y + 1) + (pSum[n - y] - a[0]) <= k
		//a[0] - x <= (k - pSum[n - y] + a[0]) / (y + 1)
		//x == a[0] - (k - pSum[n - y] + a[0]) / (y + 1)
		
		li x = a[0] - accurateFloor(k - pSum[n - y] + a[0], y + 1);
		ans = min(ans, y + max(0LL, x));
	}
	cout << ans << endl;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	int t; cin >> t;
	while (t--) {
		read();
		solve();
	}
	return 0;
}