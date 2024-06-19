#include <bits/stdc++.h>
#define rep(x, y, z) for(int x = (y); x <= (z); ++x)
#define per(x, y, z) for(int x = (y); x >= (z); --x)
#define endl '\n'
using namespace std;
typedef long long ll;
 
const int N = 105;
 
int T, n, a[N], b[N];
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    for(cin >> T; T; --T) {
        cin >> n;
        rep(i, 1, n) cin >> a[i];
        rep(i, 1, n) cin >> b[i];
        int diff = 0, ans = 0;
        rep(i, 1, n) {
            if(a[i - diff] > b[i]) {
                ++ans;
                ++diff;
            }
        }
        cout << ans << endl;
    }
    return 0;
}