#include <bits/stdc++.h>
#define rep(x, y, z) for(int x = (y); x <= (z); ++x)
#define per(x, y, z) for(int x = (y); x >= (z); --x)
#define endl '\n'
using namespace std;
typedef long long ll;
 
int T, n;
string s;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    for(cin >> T; T; --T) {
        cin >> n >> s;
        int cntU = 0;
        for(char c : s) if(c == 'U') ++cntU;
        if(cntU & 1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}