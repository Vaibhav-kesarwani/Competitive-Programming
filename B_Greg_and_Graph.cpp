#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<long long>> dist(n, vector<long long>(n, LONG_LONG_MAX));
    vector<int> RemovedThisTurn(n); // 0-indexed which tells which vertex was removed this turn (0 to n-1 turns, giving nodes 0 to n-1)
    vector<long long> sums(n, 0);
    vector<bool> added(n, false); // Start with no nodes, add them on (reverse Floyd-Warshal --> allows use of previous dist[u][v] in new iterations)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        cin >> RemovedThisTurn[i];
        RemovedThisTurn[i]--;
    }

    for (int i = n-1; i >= 0; i--) { // STARTING FROM THE LAST VERTEX REMOVED: Add this vertex, and recalculate min-distances which could use this vertex
        int newV = RemovedThisTurn[i];
        added[newV] = true;

        for (int u = 0; u < n; u++) {
            if (!added[u]) continue;
            for (int v = 0; v < n; v++) {
                if (!added[v] || u == v || u == newV || v == newV) continue;
                dist[u][newV] = min(dist[u][newV], dist[u][v] + dist[v][newV]);
                dist[newV][u] = min(dist[newV][u], dist[newV][v] + dist[v][u]);

                dist[newV][v] = min(dist[newV][v], dist[newV][u] + dist[u][v]);
                dist[v][newV] = min(dist[v][newV], dist[v][u] + dist[u][newV]);
            }
        }

        for (int u = 0; u < n; u++) {
            if (!added[u]) continue;
            for (int v = 0; v < n; v++) {
                if (!added[v] || u == v || u == newV || v == newV) continue;
                dist[u][v] = min(dist[u][v], dist[u][newV] + dist[newV][v]);
            }
        }

        for (int u = 0; u < n; u++) {
            if (!added[u]) continue;
            for (int v = 0; v < n; v++) {
                if (!added[v] || u == v) continue;
                sums[i] += dist[u][v];
            }
        }
    }

    for (int i = 0; i < n; i++) cout << sums[i] << " ";
    cout << "\n";
    return 0;
}