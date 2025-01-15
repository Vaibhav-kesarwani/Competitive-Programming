#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
const int mod = 1e9 + 7;
 
void solve(){
    int n;
    cin >> n;
    ll ans = 0;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
        ans += a[i];
    }
    cout << ans - 2 * a[n - 2] << '\n';
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}