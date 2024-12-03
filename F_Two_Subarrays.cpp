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
const ll oo = 1e18;
int sgn(int i) {
    if(i%2==1) return -1;
    return 0;
}
struct node {
    ll suma=0;
    ll mat[5][5];
    // i-->j in the automaton!
    node() {
        // *this = node(0);
        for(int i=0;i<5;++i) {
            fill(mat[i],mat[i]+5,-oo);
            mat[i][i]=0; // do nothing is free!
        }
    }
    node(ll a, ll b) {
        *this = node();
        suma=a;
        for(int i=0;i<4;i+=2) {
            mat[i][i+2]=2*b+a;
            mat[i][i+1]=0+b;
            mat[i+1][i+2]=a+b;
        }
    }

    void merge(node o) {
        for(int i=0;i<5;++i) {
            for(int j=i;j<5;++j) {
                o.mat[i][j]+=(sgn(j)-sgn(i))*suma;
            }
        }
        

        node res;
        for(int i=0;i<5;++i) {
            for(int j=i;j<5;++j) for(int k=j;k<5;++k) {
                res.mat[i][k]=max(res.mat[i][k],mat[i][j]+o.mat[j][k]);
            }
        }
        res.suma=suma+o.suma;
        *this=res;
    }
    friend node merge(node a, const node& b) {
        a.merge(b);
        return a;
    }
};
struct segtree {
    int ptwo;
    vector<node> seg;
    segtree(){}
    node& operator[](int i) {
        return seg[i+ptwo];
    }
    segtree(int nn) {
        ptwo=nn;
        seg.assign(ptwo*2,{});
    }
    auto query(int l, int r) {
        assert(l>=0 and l<ptwo and r >=0 and r<ptwo);
        l+=ptwo; r+=ptwo;
        node resl, resr;
        while(l and l<=r) {
            if(l%2==1) resl = merge(resl,seg[l++]);
            if(r%2==0) resr = merge(seg[r--],resr);
            l/=2; r/=2;
        }
        return merge(resl,resr);
    }
    void update(int i, int aa, int bb) {
        assert(i>=0 and i<ptwo);
        i+=ptwo;
        seg[i] = node(aa,bb);
        for(i/=2;i>=1;i/=2) {
            seg[i] = merge(seg[2*i],seg[2*i+1]);
        }
    }
    void build() {
        for(int i=ptwo-1;i>=1;--i) {
            seg[i] = merge(seg[2*i],seg[2*i+1]);
        }
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vi a(n);
    vi b(n);
    for(auto& i : a) cin >> i;
    for(auto& i : b) cin >> i;
    segtree seg(n);
    for(int i=0;i<n;++i) seg[i] = node(a[i],b[i]);
    seg.build();
    int q; cin >> q;
    while(q--) {
        int t; cin >> t;
        if(t<=2) {
            int p,x; cin >> p >> x;
            --p;
            if(t==1) a[p]=x;
            else b[p]=x;
            seg.update(p,a[p],b[p]);
        } else {
            int l,r; cin >> l >> r;
            --l,--r;
            cout << seg.query(l,r).mat[0][4] << '\n';
        }
    }
}