#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <ranges>
#include <set>
#include <vector>
using namespace std;

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }


template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename... Args> ostream& operator<<(ostream& os, const tuple<Args...>& t) { os << '('; apply([&os](const Args&... args) { size_t n = 0; ((os << args << (++n != sizeof...(Args) ? ", " : "")), ...); }, t); return os << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef NEAL_DEBUG
#define dbg(...) cerr << '[' << __FILE__ << ':' << __LINE__ << "] (" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif


const int INF = int(1e9) + 5;

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N, Q;
    cin >> N >> Q;
    vector<pair<int, char>> queries(Q);

    for (auto &qry : queries) {
        cin >> qry.first >> qry.second;
        qry.first--;
    }

    vector<int> extends(N, 0), shrinks(N, 0);
    vector<vector<int>> max_diff(N, vector<int>(N, 0));

    for (auto &[s, op] : queries)
        if (op == '+') {
            extends[s]++;

            for (int x = 0; x < N; x++)
                max_diff[s][x] = max(max_diff[s][x], extends[s] - shrinks[x]);
        } else {
            shrinks[s]++;

            for (int x = 0; x < N; x++)
                max_diff[x][s] = max(max_diff[x][s], extends[x] - shrinks[s]);
        }

    vector<vector<int>> dp(1 << N, vector<int>(N, INF));

    for (int i = 0; i < N; i++)
        dp[1 << i][i] = extends[i] + 1;

    for (int mask = 1; mask < 1 << N; mask++)
        for (int prefix = mask; prefix != 0; prefix &= prefix - 1) {
            int i = __builtin_ctz(prefix);
            int without = (1 << N) - 1 - mask;

            for (int without_prefix = without; without_prefix != 0; without_prefix &= without_prefix - 1) {
                int j = __builtin_ctz(without_prefix);
                dp[mask | 1 << j][j] = min(dp[mask | 1 << j][j], (dp[mask][i] - extends[i]) + max_diff[i][j] + 1 + extends[j]);
            }
        }

    cout << *min_element(dp.back().begin(), dp.back().end()) << '\n';
}
