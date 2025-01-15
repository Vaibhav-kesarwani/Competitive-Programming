#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX = 200'007;
const int MOD = 1'000'000'007;
 
void solve() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	string s;
	for (int i = 1; i <= 12; i++) {
		if (i == a || i == b) {s += "a";}
		if (i == c || i == d) {s += "b";}
	}
	cout << (s == "abab" || s == "baba" ? "YES\n" : "NO\n");
}
 
int main() {
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}
