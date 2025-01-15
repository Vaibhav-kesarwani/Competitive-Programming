#include <bits/stdc++.h>
using namespace std;
 
char s[200005];
 
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int tc, n; cin >> tc;
	while (tc--) {
		cin >> n; s[n + 1] = 'C';
		for (int i = 1; i <= n; ++i) cin >> s[i];
		int pt1 = 1, pt2 = 1, ans = 0;
		while (s[pt1] == 'B') ++pt1, ++pt2;
		while (pt1 <= n) {
			int cntA = 0, cntB = 0;
			while (s[pt2] == 'A') ++pt2, ++cntA;
			while (s[pt2] == 'B') ++pt2, ++cntB;
			if (s[pt2 - 1] == 'B') ans += pt2 - pt1 - 1;
			if (cntB) pt1 = pt2 - 1;
			else break;
		}
		cout << ans << '\n';
	}
}