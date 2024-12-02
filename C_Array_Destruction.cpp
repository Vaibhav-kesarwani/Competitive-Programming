#include<bits/stdc++.h>
using namespace std;
 
#define ull         unsigned long long int 
#define ll          long long int
#define lld         long double
#define ff          first
#define ss          second
#define all(a)      a.begin(),a.end()
#define rall(a)     a.rbegin(),a.rend()
#define pb          push_back
#define vi          vector<ll>
#define vpi         vector<pair<ll,ll>>
#define setbit(x)   __builtin_popcount(x)
 
const ll mod = 998244353;
const ll N = 2e5+5;
const ll inf = 1e18;
 
void solve() {
    ll n;
    cin>>n;
    n*=2;
    vi a(n);
    map<ll,ll> mp;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mp[a[i]]++;
    }
    vpi ans;
    sort(all(a), greater<int>());
    for(int i=1;i<n;i++){
        map<ll,ll> curr = mp;
        ans.pb({a[0], a[i]});
        curr[a[0]]--;
        curr[a[i]]--;
        for(int j=1;j<n;j++){
            if(i==j||curr[a[j]]<=0)continue;
            curr[a[j]]--;
            pair<ll,ll> curr1 = ans.back();
            ll temp = curr1.ff;
            ll diff = temp-a[j];
            if(curr[diff]==0)break;
            ll p1 = a[j];
            ll p2 = diff;
            if(p1<p2)swap(p1, p2);
            ans.pb({p1, p2});
            curr[diff]--;
        }
        // for(auto i: ans){
        //     cout<<i.ff<<" "<<i.ss<<endl;
        // }
        // cout<<endl;
        if(ans.size()==n/2)break;
        ans.clear();
    }
    if(ans.size()!=n/2){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
        cout<<ans[0].ff+ans[0].ss<<endl;
        for(auto i: ans){
            cout<<i.ff<<" "<<i.ss<<endl;
        }
    }
 
}
int main() {   
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
}