#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int ll;
typedef pair<int, int> pii;
 
#define SZ(x)                       (int) x.size()
#define F                           first
#define S                           second
 
const int N = 2e5 + 10;
ll dp[2][N]; int A[2][N], n; vector<int> adj[N];
 
void DFS(int v, int p = -1) {
    dp[0][v] = dp[1][v] = 0;
    for (int u : adj[v]) {
        if (u == p) continue;
        DFS(u, v);
        dp[0][v] += max(abs(A[0][v] - A[1][u]) + dp[1][u], dp[0][u] + abs(A[0][v] - A[0][u]));
        dp[1][v] += max(abs(A[1][v] - A[1][u]) + dp[1][u], dp[0][u] + abs(A[1][v] - A[0][u]));
    }
}
 
void Solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d%d", &A[0][i], &A[1][i]);
    fill(adj + 1, adj + n + 1, vector<int>());
    for (int i = 1; i < n; i++) {
        int u, v; scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1);
    printf("%lld\n", max(dp[0][1], dp[1][1]));
}
 
int main() {
    int t; scanf("%d", &t);
    while (t--) Solve();
    return 0;
}