#include "bits/stdc++.h"
using namespace std;
#define all(x) x.begin(),x.end()
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << p.first << " " << p.second; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { string sep; for (const T &x : v) os << sep << x, sep = " "; return os; }
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#define ASSERT(...) 42
#endif
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
const int oo = 1e9;
struct LCA {
    vi par,d,jmp,in,out;
    vector<basic_string<int>> adj;
    vi ord;
    int root;
    LCA(int n,int root=0) : par(n,root),d(n),jmp(n,root),in(n),out(n),adj(n),root(root) {}
    void add(int i) {
        int p = par[i];
        d[i]=1+d[p];
        if(d[p] - d[jmp[p]] == d[jmp[p]] - d[jmp[jmp[p]]]) jmp[i] = jmp[jmp[p]];
        else jmp[i] = p;
    }
    int jump(int a, int k) {
        int D = max(0,d[a]-k);
        while(d[a]>D) {
            if(d[jmp[a]]>=D) a = jmp[a];
            else a = par[a];
        }
        return a;
    }
    template<typename F> pi find(int a, F f) {
        int steps=d[a];
        while(!f(a)) {
            if(!f(jmp[a])) a = jmp[a];
            else a = par[a];
        }
        steps-=d[a]-1;
        return {a,steps};
    }
    int lca(int a, int b) {
        if(d[a]<d[b]) swap(a,b);
        a = jump(a,d[a]-d[b]);
        while(a!=b) {
            if(jmp[a]!=jmp[b]) a=jmp[a],b=jmp[b];
            else a=par[a],b=par[b];
        }
        return a;
    }
    void addE(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int cnt=0;
    void dfs(int at) {
        ord.push_back(at);
        in[at]=cnt++;
        for(int to: adj[at]) if(to!=par[at])  {
            par[to]=at;
            add(to);
            dfs(to);
        }
        out[at]=cnt;
    }
    void init() {
        dfs(root);
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vi a(2*n);
    for(auto& i : a) cin >> i,--i;
    vector<basic_string<int>> who(n);
    for(int i=0;i<n*2;++i) {
        who[a[i]].push_back(i);
    }
    vector<pi> es(n*2-1);
    for(auto& [u,v] : es) cin >> u >> v ,--u,--v;
    auto t = who[0];


    auto solve = [&](int rt) {
        LCA lca(n*2,rt);
        for(auto [u,v] : es) {
            lca.addE(u,v);
        }
        lca.init();
        vector<bool> vis(n*2),vis2(n*2);
        auto put = [&](int i) {
            while(!vis[i]) {
                vis[i]=1;
                
                if(lca.par[i]==i) break; 
                i=lca.par[i];
            }
        };
        for(auto w : who) {
            put(lca.lca(w[0],w[1]));
        }
        for(int i=n*2-1;i>=0;--i) {
            if(!vis[i]) {
                auto dfs = [&](auto&& self, int at) {
                    if(vis2[at]) return;
                    vis2[at]=1;
                    auto& w = who[a[at]];
                    put(w[0]^w[1]^at);
                    for(int to : lca.adj[at]) if(to!=lca.par[at]) {
                        self(self,to);
                    }
                };
                dfs(dfs,i);
            }
        }
        return vis;

    };
    auto res = solve(t[0]);
    auto res2 = solve(t[1]);
    reverse(all(res));
    reverse(all(res2));
    res=min(res,res2);
    reverse(all(res));
    vi ans;
    for(int i=0;i<2*n;++i) if(res[i]) ans.push_back(i+1);
    cout<<ans.size() << '\n' << ans << '\n';


}