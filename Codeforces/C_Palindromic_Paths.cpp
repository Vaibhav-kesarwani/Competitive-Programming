#include <bits/stdc++.h>

using namespace std;

void solve()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int> > a(n, vector<int>(m));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> a[i][j];
	vector<vector<int> > cnt(n + m - 1, vector<int>(2));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cnt[i + j][a[i][j]]++;
	int ans = 0;
	for(int i = 0; i <= n + m - 2; i++)
	{
		int j = n + m - 2 - i;
		if(i <= j) continue;
		ans += min(cnt[i][0] + cnt[j][0], cnt[i][1] + cnt[j][1]);
	}
	cout << ans << endl;
}

int main() {
	int t;
	cin >> t;
	for(int i = 0; i < t; i++)
		solve();
}