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


void run_case() {
    int N, M, Q;
    cin >> N >> M >> Q;
    M--;
    vector<array<int, 2>> ranges = {{M, M + 1}};

    auto clean = [&]() -> void {
        sort(ranges.begin(), ranges.end());
        vector<array<int, 2>> nranges;

        for (auto &range : ranges)
            if (nranges.empty() || nranges.back()[1] < range[0])
                nranges.push_back(range);
            else
                nranges.back()[1] = range[1];

        ranges.swap(nranges);
    };

    auto add = [&](int a) -> void {
        vector<array<int, 2>> nranges;

        for (auto &range : ranges)
            if (a < range[0]) {
                nranges.push_back({range[0] - 1, range[1]});
            } else if (a >= range[1]) {
                nranges.push_back({range[0], range[1] + 1});
            } else {
                if (range[1] - range[0] > 1)
                    nranges.push_back(range);

                nranges.push_back({0, 1});
                nranges.push_back({N - 1, N});
            }

        ranges.swap(nranges);
        clean();
    };

    auto query = [&]() -> int {
        int sum = 0;

        for (auto &range : ranges)
            sum += range[1] - range[0];

        return sum;
    };

    for (int q = 0; q < Q; q++) {
        int a;
        cin >> a;
        a--;
        add(a);
        cout << query() << (q < Q - 1 ? ' ' : '\n');
    }
}

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}
