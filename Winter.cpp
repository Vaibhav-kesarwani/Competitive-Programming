#include <bits/stdc++.h>
using namespace std;
#define int long long
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(0);
#define Vaibhav cout.tie(0);
#define nt << "\n";
#define yes cout << "YES" nt
#define no cout << "NO" nt
const long double pi = 3.141592653589793238;
const int INF = LONG_LONG_MAX;
const int mod = 1000000007;
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int lcm(int a, int b) { return (a / gcd(a, b) * b); }

void Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai()
{
}

signed main()
{
    Code By Vaibhav auto solve = [&]() -> void
    {
        int N, M, Q;
        cin >> N >> M >> Q;
        vector<int> g[N + 10];

        for (int i = 0; i < M; i++)
        {
            int a, b;
            cin >> a >> b;

            g[a].push_back(b);
            g[b].push_back(a);
        }
        vector<int> vis(N + 10, 0);
        queue<int> q;

        auto time_bfs = [&](int T) -> void
        {
            while (q.size() && T--)
            {
                int sz = q.size();
                while (sz--)
                {
                    auto beg = q.front();
                    q.pop();

                    for (auto v : g[beg])
                    {
                        if (vis[v] == 0)
                        {
                            vis[v] = 1;
                            q.push(v);
                        }
                    }
                }
            }
        };

        for (int i = 0; i < Q; i++)
        {
            int a, b;
            cin >> a >> b;

            if (a == 1)
            {
                if (vis[b] == 0)
                {
                    vis[b] = 1;
                    q.push(b);
                }
            }
            else if (a == 2)
            {
                time_bfs(b);
            }
            else
            {
                if (vis[b])
                {
                    cout << "YES" << endl;
                }
                else
                {
                    cout << "NO" << endl;
                }
            }
        }
    };

    int test = 1;
    // cin>>test;
    while (test--)
        solve();

    return 0;
}