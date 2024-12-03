#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;
int f[1000005][2];
int s[1000005][2];
int n , k;
int t[1000005] , rt[1000005];
int fpow(int a,int b) {
    int ans = 1;
    while(b) {
        if(b & 1) ans =1LL*ans*a%mod;
        a = 1LL * a * a % mod; b >>= 1;
    }
    return ans;
}
int C(int a,int b) {
    return 1LL * t[a] * rt[b] % mod * rt[a-b] % mod;
}
int main() {
    ios::sync_with_stdio(false) ; cin.tie(0) ;
    cin >> n >> k ; n-- ; k--;
    if(k == 0) {
        cout << 1 << '\n' ; return 0;
    }
    t[0] = rt[0] = 1;
    for(int i = 1;i <= n + 1;i++) t[i] = 1LL * t[i - 1] * i % mod , rt[i] = fpow(t[i] , mod - 2);
    for(int i = 1;i <= n;i++) {
        /// 0 , 2
        int l = max(0 , i - k - 1) ; /// f[i-k] ... f[i - 1]
        f[i][0] = (1LL * (s[i-1][1] - s[l][1] + mod)) % mod;
        f[i][1] = (1LL * (s[i-1][0] - s[l][0] + mod)) % mod;
        if(i <= k) {
            f[i][0]++ ; f[i][1]++ ;
        }
        for(int j = 0;j < 2;j++) {
            s[i][j] = (s[i - 1][j] + f[i][j]) % mod ;
        }
    }
    int ans = 1;
    for(int i =1;i <= n;i++) {
        ans = (ans + 1LL * (f[i][0] + f[i][1]) * C(n , i)) % mod;
    }

    cout << ans << '\n';
}