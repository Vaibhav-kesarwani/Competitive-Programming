#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
// using namespace __gnu_pbds;
 
#define int long long
#define mod 1000000007
#define base 7001
#define base2 757
#define F first
#define S second
// #define pi acos(-1)
#define double long double
// #define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
// #define ordered_multiset tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
 
#pragma GCC optimize("O3,Ofast,unroll-loops")
#pragma GCC target("avx2,sse3,sse4,avx")

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
constexpr int maxn = 1000001;
const int N = 1 << (int)(ceil(log2(maxn)));

int n, a[15];

signed main()
{
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n;
    int mn = INT_MAX, mni = 0;
    for (int i = 1; i < 10; i++) {
        cin >> a[i];
        if (a[i] < mn) {mn = a[i]; mni = i;}
    }
    if (!(n / mn)) {cout << -1; return 0;}
    vector<int> v;
    for (int i = 1; i <= n / mn; i++) v.push_back(mni);
    int rem = n / mn * mn;
    for (int i = 0; i < v.size(); i++) {
        for (int j = 9; j > 0; j--) {
            if (rem - mn + a[j] <= n) {
                v[i] = j;
                rem -= mn; rem += a[j];
                break;
            }
        }
    }
    for (int i : v) cout << i;
}