#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {

		int n;
		cin >> n;
		vector<long long> d(n);
		for (int i = 0; i < n; ++i) {
			cin >> d[i];
		}
		sort(d.begin(), d.end());
		long long x = d[0] * d[n - 1];
		
		vector<long long> dd;
		for (int i = 2; i * 1ll * i <= x; ++i) {
			if (x % i == 0) {
				dd.push_back(i);
				if (i != x / i) {
					dd.push_back(x / i);
				}
			}
		}
		sort(dd.begin(), dd.end());
		
		if (dd == d) {
			cout << x << endl;
		} else {
			cout << -1 << endl;
		}
	}
	
	return 0;
}