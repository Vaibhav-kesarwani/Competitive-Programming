#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
	string s;
	cin >> s;
	int n = s.size();
	string a, b;
	for (int i = 0; i < 2 * n; ++i) {
	  a += "()"[i & 1];
	  b += ")("[i < n];
	}
	if (a.find(s) == string::npos) {
	  cout << "YES\n" << a << '\n';
	} else if (b.find(s) == string::npos) {
	  cout << "YES\n" << b << '\n';
	} else {
	  cout << "NO\n";
	}
  }
}