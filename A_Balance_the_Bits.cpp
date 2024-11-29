#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void test_case(int& tc) {
	int n;
	string s;
	cin >> n >> s;
	int cnt = 0;
	for (int i = 0; i < n; i++)
		cnt += (s[i] == '1');
	if (cnt % 2 == 1 || s[0] == '0' || s[n-1] == '0') {
		cout << "NO\n";
		return;
	}
	string a = "", b = "";
	int k = 0;
	bool flip = false;
	for (int i = 0; i < n; i++) {
		if (s[i] == '1') {
			a += (2 * k < cnt ? '(' : ')');
			b += a.back();
			k++;
		} else {
			a += (flip ? '(' : ')');
			b += (flip ? ')' : '(');
			flip = !flip;
		}
	}
	cout << "YES\n" << a << "\n" << b << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T = 1;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
		test_case(tc);
}