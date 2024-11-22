#include <iostream>
#include <numeric>
#include <bits/stdc++.h>

using namespace std;

#define ll                   long long
#define pp                   pop_back
#define pb                   push_back
#define cy                   cout<< "YES\n";
#define cn                   cout<< "NO\n";
#define fast                 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define FOR(i,n)             for(ll i=1;i<=n;i++)
#define LOOP(i,n)            for(ll i=0;i<n;i++)
#define FOOR(i,a,b)          for(ll i=a;i<=b;i++)
#define LOP(i,a,b)           for(ll i=a;i<b;i++)
#define inf                  100000
#define MAXN                 100004
const ll INF = LONG_LONG_MAX;
const int IINF = 1e9 + 5;
const ll mod = 1e9 + 7;
// (a / b) % mod ->  (a % mod)* binpow(b, mod - 2) % mod
//((p % mod) + mod) % mod // negative mod
//ll vis[MAXN], vis1[MAXN], lvl[MAXN] = {-1};
//bool bfs(ll src, ll n, vector<ll> graph[])
//{
//    queue<ll> q;
//    int color[n + 1];
//    for(ll i = 0; i <= n; i++)
//        color[i] = -1;
//    color[src] = 1;
//    q.push(src);
//    while(!q.empty())
//    {
//        ll temp = q.front();
//        q.pop();
//        for(ll i = 0; i < graph[temp].size(); i++)
//        {
//            if(graph[temp][i] == temp)
//                return false;
//            else if(color[graph[temp][i]] == -1)
//            {
//                color[graph[temp][i]] = 1 - color[temp];
//                q.push(graph[temp][i]);
//            }
//            else if(color[graph[temp][i]] == color[temp])
//            {
//                return false;
//            }
//        }
//    }
//    return true;
//}

//bool cmp(pair<pair<int, int>, char> a, pair<pair<int, int>, char> b)
//{
//    if(a.first.first == b.first.first)
//    {
//        return a.first.second > b.first.second;
//    }
//    else
//        return a.first < b.first;
//}

void solve()
{
    int n;
    cin >> n;
    vector<int> ar(n);
    for(int i = 1; i < n; ++i)
    {
        cout << "? " << 1 << " " << i + 1 << "\n";
        // cout.flush();
        int res;
        cin >> res;
        ar[i] = res;
    }
    if(ar[n - 1] == 0)
    {
        cout << "! IMPOSSIBLE\n";
        return;
    }
    int temp = 1, k;
    while(ar[temp] == 0)
    {
        ++temp;
    }
    k = ar[temp];
    string str(n, '0');
    for(int i = 0; i < temp - k; ++i)
    {
        str[i] = '1';
    }
    for(int i = temp; i < n; ++i)
    {
        str[i] = (((ar[i] > ar[i - 1]) ? '1' : '0'));
    }
    cout << "! " << str << "\n";
}

int main()
{
    // fast;
//    sieve1();
    int t, n;
//    int c = 1;
    cin >> t;
//    t = 1;
    while(t--)
    {
//        cout << "Case " << c << ": ";
//        c++;
        //memset(dp, -1, sizeof(dp));
        solve();
    }


    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << " ms\n";
    return 0;
}
