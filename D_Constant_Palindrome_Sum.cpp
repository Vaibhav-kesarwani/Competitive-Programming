#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		for (auto &it : a) cin >> it;
		vector<int> cnt(2 * k + 1);
		for (int i = 0; i < n / 2; ++i) {
			++cnt[a[i] + a[n - i - 1]];
		}
		vector<int> pref(2 * k + 2);
		for (int i = 0; i < n / 2; ++i) {
			int l1 = 1 + a[i], r1 = k + a[i];
			int l2 = 1 + a[n - i - 1], r2 = k + a[n - i - 1];
			assert(max(l1, l2) <= min(r1, r2));
			++pref[min(l1, l2)];
			--pref[max(r1, r2) + 1];
		}
		for (int i = 1; i <= 2 * k + 1; ++i) {
			pref[i] += pref[i - 1];
		}
		int ans = 1e9;
		for (int sum = 2; sum <= 2 * k; ++sum) {
			ans = min(ans, (pref[sum] - cnt[sum]) + (n / 2 - pref[sum]) * 2);
		}
		cout << ans << endl;
	}
	
	return 0;
}