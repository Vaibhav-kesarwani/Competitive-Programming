#include <bits/stdc++.h>
#define ll long long
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1 | 1)
#define ru(i, l, r) for (int i = (l); i <= (r); i++)
#define rd(i, r, l) for (int i = (r); i >= (l); i--)
#define mid ((l + r) >> 1)
#define pii pair<int, int>
#define mp make_pair
#define fi first
#define se second
#define sz(s) (int)s.size()
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
using namespace std;
mt19937 Rand(chrono::steady_clock::now().time_since_epoch().count());
int read() {
    int x = 0, w = 0;
    char ch = getchar();

    while (!isdigit(ch))
        w |= ch == '-', ch = getchar();

    while (isdigit(ch))
        x = x * 10 + ch - '0', ch = getchar();

    return w ? -x : x;
}
int main() {
    int T = read();

    while (T--) {
        int n = read();
        vector<int> a, b;
        ru(i, 1, n) a.push_back(read());
        ru(i, 1, n) b.push_back(read());

        if (a == b) {
            printf("Bob\n");
            continue;
        }

        reverse(a.begin(), a.end());

        if (a == b) {
            printf("Bob\n");
            continue;
        }

        printf("Alice\n");
    }

    return 0;
}