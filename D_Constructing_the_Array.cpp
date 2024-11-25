#include <bits/stdc++.h>

using namespace std;

struct cmp {
	bool operator() (const pair<int, int> &a, const pair<int, int> &b) const {
		int lena = a.second - a.first + 1;
		int lenb = b.second - b.first + 1;
		if (lena == lenb) return a.first < b.first;
		return lena > lenb;
	}
};

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		set<pair<int, int>, cmp> segs;
		segs.insert({0, n - 1});
		vector<int> a(n);
		for (int i = 1; i <= n; ++i) {
			pair<int, int> cur = *segs.begin();
			segs.erase(segs.begin());
			int id = (cur.first + cur.second) / 2;
			a[id] = i;
			if (cur.first < id) segs.insert({cur.first, id - 1});
			if (id < cur.second) segs.insert({id + 1, cur.second});
		}
		for (auto it : a) cout << it << " ";
		cout << endl;
	}
	
	return 0;
}