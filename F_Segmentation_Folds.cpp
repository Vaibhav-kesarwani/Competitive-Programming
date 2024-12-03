#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll l ,r;
const int mod = 998244353;
const int N = 1.5e6;
bool p[N + 5] ;
vector<int> pr ;
bool tp[200005] ;
ll pre[200005] , suf[200005];
typedef pair<ll,ll> pll;
ll L , R;
void chk_ans(pll &A,pll B) {
    if(B.first < A.first) {
        A = B;
    }
    else if(B.first == A.first ) {
        A.second = (A.second + B.second) % mod;
    }
}
pll lop(pll x) {
    ll p = pre[(x.second + x.first) / 2 - L] ;
    if(p == -1 || p <= x.first) return {-1,-1} ;
    return {p , x.second} ;
}
pll rop(pll x) {
    ll p = suf[(x.second + x.first + 1) / 2 - L] ;
    if(p == -1 || p >= x.second) return {-1,-1} ;
    return {x.first , p} ;
}

ll inf = 1e18;
unordered_map<ll , pll> mp;
const int D = 2e5 + 10 ;
ll gid(pll x) {
    return (x.first - L) * D + (x.second - L) ;
}
pll dfs(pll r) {
    if(r.first == -1) return {inf , 0} ;
    ll id = gid(r) ;
    if(mp.count(id)) {
        return mp[id] ;
    }
    pll &ans = mp[id] ;
    ans = {r.second - r.first , 1} ;
    chk_ans(ans , dfs(lop(r))) ;
    chk_ans(ans , dfs(rop(r))) ;
    return ans;
}
void solv() {
    mp.clear() ;
    cin >> l >> r;
    L = 2*l ; R = 2*r;
    /// 2l , 2r
    memset(tp,0,sizeof(tp)) ;
    memset(pre , 0 ,sizeof(pre)) ;
    memset(suf , 0 , sizeof(suf)) ;
    for(auto x : pr) {
        for(ll i = x * max(2LL , (L + x - 1) / x); i <= R ; i += x) {
            tp[i - (l * 2)] = 1;
        }
    }
    ll lst = -1;
    for(ll i = 2*l ; i <= 2*r ; i++) {
        if(tp[i - l*2] == 0) lst = i;
        pre[i - l * 2] = lst ;
    }
    lst = -1;
    for(ll i = r * 2 ; i >= 2*l ; i--) {
        if(tp[i - l*2] == 0) lst = i;
        suf[i - l*2] = lst;
    }
    pll ans = dfs({l*2 , r*2}) ;
    cout << ans.second << '\n' ;
}   
int main() {
    ios::sync_with_stdio(false) ; cin.tie(0) ;
    int t;cin >> t;
    for(int i =2;i <= N;i++) {
        if(!p[i]) {
            pr.push_back(i) ;
            for(int j = i * 2; j <= N; j += i) p[j] = 1;
        }
    }
    while(t--) solv() ;
}