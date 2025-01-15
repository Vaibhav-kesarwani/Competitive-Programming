#include <bits/stdc++.h>
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using namespace std;
using namespace __gnu_pbds;
using cd = complex<double>;
const double PI = acos(-1);
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ld, ld> pld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef tree<
    int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_set;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
 
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
 
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
 
uniform_int_distribution<int> RAND(0, 1), COIN(0, 1), RAND2(2, 10);
uniform_real_distribution<double> R(0, 1);
 
using namespace std;
const int N = 1e6 + 10, M = 20, dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
int n, k;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
 
  int t = 1;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    cin >> n >> k;
    vi cnt(26, 0);
    string s;
    cin >> s;
    for (int i = 0; i < n; ++i) {
      cnt[s[i] - 'a']++;
    }
    int odd = 0;
    for (int x : cnt) {
      odd += (x & 1);
    }
    cout << ((odd <= k + 1) ? "YES" : "NO") << '\n';
  }
}