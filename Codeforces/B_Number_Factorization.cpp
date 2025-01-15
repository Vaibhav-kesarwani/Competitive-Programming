#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
pair<int, int> s[110];
int d[110];
void get() {
	int n, l = 0, i, c;
	cin >> n;
	for (i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			c = 0;
			while (n % i == 0) c++, n /= i;
			s[++l] = make_pair(c, i);
		}
	}
	if (n != 1) s[++l] = make_pair(1, n);
	sort(s + 1, s + l + 1), d[l + 1] = 1;
	for (i = l; i >= 1; i--) d[i] = d[i + 1] * s[i].second;
	int ans = 0;
	for (i = 1; i <= l; i++) if (s[i].first != s[i - 1].first) ans += d[i] * (s[i].first - s[i - 1].first);
	cout << ans << endl;
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) get();
	return 0;
}