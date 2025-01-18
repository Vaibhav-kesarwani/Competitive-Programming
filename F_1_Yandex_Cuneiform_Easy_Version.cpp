#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

using namespace __gnu_pbds;
using namespace std;

using ll = long long;
using ld = double;

//#include "testlib.h"


typedef tree<
        pair<int, int>,
        null_type,
        less<pair<int, int>>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;

#define mp make_pair

//const int MOD = 1'000'000'007;
int MOD = 998'244'353;

int mul(int a, int b) {
    return (1LL * a * b) % MOD;
}

int add(int a, int b) {
    int s = (a+b);
    if (s>=MOD) s-=MOD;
    return s;
}

int sub(int a, int b) {
    int s = (a+MOD-b);
    if (s>=MOD) s-=MOD;
    return s;
}

int po(int a, ll deg)
{
    if (deg==0) return 1;
    if (deg%2==1) return mul(a, po(a, deg-1));
    int t = po(a, deg/2);
    return mul(t, t);
}

int inv(int n)
{
    return po(n, MOD-2);
}


mt19937 rnd(time(0));


const int LIM = 400'005;

vector<int> facs(LIM), invfacs(LIM), invs(LIM);

void init()
{
    facs[0] = 1;
    for (int i = 1; i<LIM; i++) facs[i] = mul(facs[i-1], i);
    invfacs[LIM-1] = inv(facs[LIM-1]);
    for (int i = LIM-2; i>=0; i--) invfacs[i] = mul(invfacs[i+1], i+1);

    for (int i = 1; i<LIM; i++) invs[i] = mul(invfacs[i], facs[i-1]);
}

int C(int n, int k)
{
    if (n<k) return 0;
    if (n<0 || k<0) return 0;
    return mul(facs[n], mul(invfacs[k], invfacs[n-k]));
}

struct DSU
{
    vector<int> sz;
    vector<int> parent;
    void make_set(int v) {
        parent[v] = v;
        sz[v] = 1;
    }

    int find_set(int v) {
        if (v == parent[v])
            return v;
        return find_set(parent[v]);
    }

    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);

        if (a != b) {
            if (sz[a] < sz[b])
                swap(a, b);
            parent[b] = a;
            sz[a] += sz[b];
        }
    }

    DSU (int n)
    {
        parent.resize(n);
        sz.resize(n);
        for (int i = 0; i<n; i++) make_set(i);
    }
};

void print(vector<int> a)
{
    for (auto it: a) cout<<it<<' ';
    cout<<endl;
}

void print(vector<vector<int>> a)
{
    for (auto vec: a) print(vec);
    cout<<endl;
}

void print(set<int> a)
{
    for (auto it: a) cout<<it<<' ';
    cout<<endl;
}

void print(vector<bool> a)
{
    for (auto it: a) cout<<it<<' ';
    cout<<endl;
}

void print(vector<ll> a)
{
    for (auto it: a) cout<<it<<' ';
    cout<<endl;
}

void print(vector<ld> a)
{
    for (auto it: a) cout<<it<<' ';
    cout<<endl;
}

void print(vector<pair<ll, ll>> a)
{
    for (auto it: a) cout<<it.first<<' '<<it.second<<"| ";
    cout<<endl;
}

void print(set<pair<int, int>> a)
{
    for (auto it: a) cout<<it.first<<' '<<it.second<<"| ";
    cout<<endl;
}

void print(vector<pair<int, int>> a)
{
    for (auto it: a) cout<<it.first<<' '<<it.second<<"| ";
    cout<<endl;
}

void print(vector<pair<ll, int>> a)
{
    for (auto it: a) cout<<it.first<<' '<<it.second<<"| ";
    cout<<endl;
}

void print(map<ll, int> a)
{
    for (auto it: a) cout<<it.first<<' '<<it.second<<"| ";
    cout<<endl;
}

struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> const &a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

int n; string s;
vector<int> nxt, prv;
map<string, set<int>> positions;

void remove_cand(int x)
{
    if (nxt[x] < n && nxt[nxt[x]] < n)
    {
        string tmp;
        for (auto pos: {x, nxt[x], nxt[nxt[x]]}) tmp+=s[pos];
        if (tmp[0] == tmp[2])
        {
            positions[tmp].erase(x);
        }
    }
}

void insert_cand(int x)
{
    if (nxt[x] < n && nxt[nxt[x]] < n)
    {
        string tmp;
        for (auto pos: {x, nxt[x], nxt[nxt[x]]}) tmp+=s[pos];
        if (tmp[0] == tmp[2])
        {
            positions[tmp].insert(x);
        }
    }
}

void remove(int pos)
{
    remove_cand(pos);
    if (prv[pos] >= 0)
    {
        remove_cand(prv[pos]);
        if (prv[prv[pos]] >= 0)
        {
            remove_cand(prv[prv[pos]]);
        }
    }

    if (nxt[pos]<n) prv[nxt[pos]] = prv[pos];
    if (prv[pos]>=0) nxt[prv[pos]] = nxt[pos];

    if (prv[pos] >= 0)
    {
        insert_cand(prv[pos]);
        if (prv[prv[pos]] >= 0)
        {
            insert_cand(prv[prv[pos]]);
        }
    }
}

void solve()
{
    cin>>s;
    n = s.size();
    for (int i = 0; i<n-1; i++)
    {
        if (s[i] == s[i+1])
        {
            cout<<"NO"<<endl; return;
        }
    }

    map<char, int> cntmap;
    for (auto c: s) cntmap[c]++;
    for (auto pr: cntmap)
    {
        if (pr.second != n/3) {cout<<"NO"<<endl; return;}
    }

    cout<<"YES"<<endl;
    cout<<s<<endl;
    vector<vector<pair<char, int>>> ops;

    vector<bool> present(n, true);
    FenwickTree tree(n);
    for (int i = 0; i<n; i++) tree.add(i, 1);

    nxt.clear(); nxt.resize(n);
    prv.clear(); prv.resize(n);
    for (int i = 0; i<n; i++) nxt[i] = i+1;
    for (int i = 0; i<n; i++) prv[i] = i-1;


    positions.clear();
    //for (auto cand: {"YDY", "DYD", "XDX", "DXD", "YXY", "XYX"}) positions[cand].

    for (int i = 0; i<n-2; i++)
    {
         string tmp;
         for (int j = i; j<i+3; j++) tmp+=s[j];
         if (tmp[0] == tmp[2]) positions[tmp].insert(i);
    }

    map<char, vector<string>> mapka;
    mapka['X'] = {"YDY", "DYD"};
    mapka['Y'] = {"XDX", "DXD"};
    mapka['D'] = {"YXY", "XYX"};


    for (int i = 0; i<n; i++) if (present[i])
    {
        int pos = -1;
        for (auto cand: mapka[s[i]]) if (!positions[cand].empty())
        {
            pos = *(positions[cand].begin());
        }

        vector<int> deleting;

        if (pos == -1)
        {
            deleting = {i, nxt[i], nxt[nxt[i]]};
        }
        else deleting = {i, pos, nxt[pos]};

        vector<pair<char, int>> op;

        for (auto position: deleting)
        {
            op.push_back({s[position], tree.sum(position)-1});
            remove(position);
            present[position] = false;
            tree.add(position, -1);
        }
        reverse(op.begin(), op.end());
        ops.push_back(op);
    }


    reverse(ops.begin(), ops.end());

    //string checker;

    for (auto op: ops)
    {
        for (auto pr: op)
        {
            //checker.insert(pr.second, 1, pr.first);
            cout<<pr.first<<' '<<pr.second<<' ';
        }
        //cerr<<checker<<endl;
        cout<<endl;
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t; cin>>t;
    while (t--) solve();


}

