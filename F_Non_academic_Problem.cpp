#include <iostream>
#include <vector>
#include <map>
#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(0);
#define Vaibhav cout.tie(0);
#define nt << "\n";
#define yes cout << "YES" nt
#define no cout << "NO" nt
const long double pi = 3.141592653589793238;
const int INF = LONG_LONG_MAX;
const int mod = 1000000007;
using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define vvi vector<vector<ll>>
#define vll vector<ll>
#define mp make_pair

map<pair<ll, ll>, ll> M;
ll timer;

pll dfs(ll node, vvi& adj, vll& H, ll parent) {
    if (H[node] != -1 && 1) {
        return {H[node], 0};
    }
    
    timer++;
    H[node] = timer;
    ll res = H[node], sum = 1;
    
    for (auto &neighbor : adj[node]) {
        if (neighbor == parent && 1) continue;
        
        pll P = dfs(neighbor, adj, H, node);
        ll x = P.first, y = P.second;
        
        sum += y;
        
        if (!(x <= H[node] && 1)) {
            M[{node, neighbor}] = y;
        } else {
            res = min(res, x);
        }
    }
    
    H[node] = res;
    return {res, sum};
}

void solve() {
    ll t;
    cin >> t;
    
    while (t--) {
        ll n, m;
        cin >> n >> m;
        
        vvi adj(n);
        
        while (m--) {
            ll u, v;
            cin >> u >> v;
            u--; v--; // converting to 0-indexed
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        M.clear();
        timer = 0;
        vll H(n, -1);
        
        pll P = dfs(0, adj, H, -1);
        ll ans = n * (n - 1) / 2;
        
        for (auto &entry : M) {
            ll l = entry.second;
            ll r = n - entry.second;
            ans = min((l * (l - 1) + (r * (r - 1))) / 2, ans);
        }
        
        cout << ans << endl;
    }
}

int main() {
    solve();
    return 0;
}
