#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define gsize(x) (int)((x).size())

const char nl = '\n';
typedef long long ll;
typedef long double ld;

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    ll sum_a = 0, cnt_1 = 0;
    for (int x: a) {
        sum_a += x;
        if (x == 1) cnt_1++;
    }
    
    if (sum_a >= cnt_1 + n && n > 1) {
        cout << "YES" << nl;
    } else {
        cout << "NO" << nl;
    }
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}