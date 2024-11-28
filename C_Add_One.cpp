#include <bits/stdc++.h>
using namespace std;

#define int long long

const int max_n = 200005, mod = 1000000007;
int dp[max_n];

signed main(){

    for(int i=0; i<9; i++)dp[i] = 2;
    dp[9] = 3;
    for(int i=10; i<max_n; i++){
        dp[i] = (dp[i-9] + dp[i-10])%mod;
    }

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        int ans = 0;
        while(n > 0){
            int x = n%10;
            ans += ((m + x < 10) ? 1 : dp[m + x - 10]);
            ans %= mod;
            n/=10;
        }
        cout<<ans<<"\n";
    }
    return 0;
}