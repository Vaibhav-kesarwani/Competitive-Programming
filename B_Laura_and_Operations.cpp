#include "bits/stdc++.h"

using namespace std;
using ll = long long;
const int mod = 1e9+7;
#define int long long
#define all(x) x.begin(),x.end()
void solve(){
    int a,b,c;cin>>a>>b>>c;
    if(abs(b-c)%2==0){
        cout<<1<<" ";
    }
    else{
        cout<<0<<" ";
    }
    if(abs(a-c)%2==0){
        cout<<1<<" ";
    }
    else{
        cout<<0<<" ";
    }
    if(abs(b-a)%2==0){
        cout<<1<<" ";
    }
    else{
        cout<<0<<" ";
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
#ifdef prince
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int q = 1;
    cin >> q;
    while (q--) {
        solve();
        cout << '\n';
    }
}
