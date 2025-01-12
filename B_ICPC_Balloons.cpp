#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX = 200007;
const int MOD = 1000000007;
 
void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	bool vis[26] = {};
	int res = 0;
	for (char c : s) {
		if (!vis[c - 'A']) {res += 2; vis[c - 'A'] = true;}
		else {res++;}
	}
	cout << res << '\n';
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}