#include <bits/stdc++.h>
#define L(i, j, k) for (int i = (j); i <= (k); ++i)
#define R(i, j, k) for (int i = (j); i >= (k); --i)
#define ll long long
#define sz(a) ((int)(a).size())
#define pb emplace_back
#define me(a, x) memset(a, x, sizeof(a))
#define vi vector<int>
#define ull unsigned long long
using namespace std;
#define pii pair<int, int>
const int N = 4007;
template <int N, int Ne>
struct flows
{
    using F = int; // flow type
    F inf = 1e9;
    int n, s, t; // Remember to assign n, s and t !
    int ehd[N], cur[N], ev[Ne << 1], enx[Ne << 1], eid = 1;
    void clear()
    {
        eid = 1, memset(ehd, 0, sizeof(ehd));
    }
    F ew[Ne << 1], dis[N];
    void Eadd(int u, int v, F w)
    {
        ++eid, enx[eid] = ehd[u], ew[eid] = w, ev[eid] = v, ehd[u] = eid;
    }
    void add(int u, int v, F w)
    {
        Eadd(u, v, w), Eadd(v, u, 0);
    }
    bool bfs()
    {
        queue<int> q;
        L(i, 1, n)
        dis[i] = inf,
        cur[i] = ehd[i];
        q.push(s), dis[s] = 0;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int i = ehd[u]; i; i = enx[i])
                if (ew[i] && dis[ev[i]] == inf)
                {
                    dis[ev[i]] = dis[u] + 1, q.push(ev[i]);
                }
        }
        return dis[t] < inf;
    }
    F dfs(int x, F now)
    {
        if (!now || x == t)
            return now;
        F res = 0, f;
        for (int i = cur[x]; i; i = enx[i])
        {
            cur[x] = i;
            if (ew[i] && dis[ev[i]] == dis[x] + 1)
            {
                f = dfs(ev[i], min(now, ew[i])), ew[i] -= f, now -= f, ew[i ^ 1] += f, res += f;
                if (!now)
                    break;
            }
        }
        return res;
    }
    F max_flow()
    {
        F res = 0;
        while (bfs())
            res += dfs(s, inf);
        return res;
    }
};
int n, k;
struct info
{
    int l, r, k;
};
int p[2][N], ip[2][N];
int arr[2][N];
int tak[2][N];
flows<N * 2, N * 4> G, nG;
int top[2];
int U[N], V[N];
info D[2][N];
int musnt[N], must[N];
int EI[N];
void Main()
{
    me(p, 0);
    me(ip, 0);
    G.clear();
    cin >> n;
    L(o, 0, 1)
        L(i, 1, n) cin >> p[o][i],
        ip[o][p[o][i]] = i;
    cin >> k;
    L(o, 0, 1)
        L(i, 1, k) cin >> arr[o][i];
    L(o, 0, 1)
    {
        top[o] = 0;
        vi pos, num;
        L(i, 1, k)
        if (arr[o][i] != -1) pos.pb(ip[o][arr[o][i]]),
            tak[o][sz(pos)] = i;
        tak[o][0] = 0;
        tak[o][sz(pos) + 1] = k + 1;
        L(j, 0, sz(pos) - 2)
        {
            if (pos[j] > pos[j + 1])
            {
                cout << "Inconsistent" << '\n';
                return;
            }
        }
        L(i, 0, sz(pos))
        {
            int l = 1, r = n;
            if (i)
                l = pos[i - 1] + 1;
            if (i < sz(pos))
                r = pos[i] - 1;
            if (l <= r)
            {
                info qwq;
                qwq.l = l;
                qwq.r = r;
                qwq.k = tak[o][i + 1] - tak[o][i] - 1;
                D[o][++top[o]] = qwq;
            }
            if (i < sz(pos))
            {
                info qwq;
                qwq.l = pos[i];
                qwq.r = pos[i];
                qwq.k = 1;
                D[o][++top[o]] = qwq;
            }
        }
        // L(j, 1, top[o]) {
        // 	cout << D[o][j].l << ' ' << D[o][j].r << ' ';
        // }
        // cout << endl;
    }
    L(i, 1, top[0])
    L(j, D[0][i].l, D[0][i].r)
    U[p[0][j]] = i;
    L(i, 1, top[1])
    L(j, D[1][i].l, D[1][i].r)
    V[p[1][j]] = i;
    // L(i, 1, n)
    // 	cout << U[i] << ' ' << V[i] << endl;
    G.n = top[0] + top[1];
    G.s = ++G.n;
    G.t = ++G.n;
    L(i, 1, top[0])
    {
        G.add(G.s, i, D[0][i].k);
        // cout<<D[0][i].k<<endl;
    }
    L(i, 1, top[1])
    {
        G.add(i + top[0], G.t, D[1][i].k);
        // cout<<D[1][i].k<<endl;
    }
    L(i, 1, n)
    G.add(U[i], V[i] + top[0], 1), EI[i] = G.eid;
    auto f = G.max_flow();
    if (f != k)
    {
        cout << "Inconsistent\n";
        return;
    }
    auto nG = G;
    me(musnt, 0);
    me(must, 0);
    L(i, 1, n)
    {
        if (G.ew[EI[i]])
        {
            G.ew[EI[i]] = 0;
            G.add(G.s, U[i], 1);
            G.add(V[i] + top[0], G.t, 1);
            if (!G.max_flow())
            {
                must[i] = 1;
            }
            G = nG;
        }
    }
    L(i, 1, n)
    {
        if (!G.ew[EI[i]])
        {
            G.ew[EI[i] ^ 1] = 0;
            G.add(G.s, V[i] + top[0], 1);
            G.add(U[i], G.t, 1);
            if (!G.max_flow())
            {
                musnt[i] = 1;
            }
            G = nG;
        }
    }
    L(i, 1, n)
    if (must[i])
    {
        cout << "Y";
    }
    else if (musnt[i])
    {
        cout << "N";
    }
    else
    {
        cout << "?";
    }
    cout << '\n';
}
int main()
{
    ios ::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        Main();
    return 0;
}
/*
 2
 4
 1 2 3 4
 3 2 4 1
 3
 1 -1 -1
 3 -1 1
 4
 1 2 3 4
 3 2 4 1
 3
 1 -1 2
 3 -1 1


  2
 3
 1 2 3
 2 1 3
 2
 -1 2
 -1 -1
 3
 1 2 3
 3 2 1
 2
 1 3
 2 -1
*/