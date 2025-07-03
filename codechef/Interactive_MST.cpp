// #include "bits/stdc++.h"
#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif
using namespace std;

#define all(v) v.begin(), v.end()

const int INF = 1e9;

struct DSU {
    vector<int> p;
    DSU(int n) : p(n) {
        iota(all(p), 0);
    }

    int find(int x) {
        return (x == p[x]) ? x : p[x] = find(p[x]);
    }

    bool unite(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx == ry) return false;
        p[rx] = ry;
        return true;
    }
};

// Return MST weight for current binary weights
int mst(int n, vector<array<int, 3>> &edges, vector<int> &mask) {
    vector<pair<int, int>> ew;
    for (int i = 0; i < edges.size(); ++i)
        if (mask[i])
            ew.emplace_back(edges[i][2], i);  // (weight, index)

    sort(all(ew));
    DSU dsu(n);
    int res = 0;
    for (auto &[w, idx] : ew) {
        auto &[u, v, _] = edges[idx];
        if (dsu.unite(u, v)) res += w;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        int n, m; cin >> n >> m;
        vector<array<int, 3>> edges(m);
        for (auto &[u, v, w] : edges) {
            cin >> u >> v >> w;
            --u, --v;
        }

        int min_flips = m;

        // Try all 2^m possible weight flip combinations (since m ≤ 78)
        for (int flip = 0; flip < (1 << m); ++flip) {
            vector<array<int, 3>> changed = edges;
            int flips = 0;

            for (int i = 0; i < m; ++i) {
                if ((flip >> i) & 1) {
                    changed[i][2] ^= 1;
                    flips++;
                }
            }

            set<int> mst_results;
            for (int mask = 0; mask < (1 << m); ++mask) {
                vector<int> apply_mask(m);
                for (int i = 0; i < m; ++i)
                    apply_mask[i] = ((mask >> i) & 1);
                vector<array<int, 3>> temp = changed;
                for (int i = 0; i < m; ++i)
                    temp[i][2] *= apply_mask[i];
                int weight = mst(n, temp, apply_mask);
                mst_results.insert(weight);
                if (mst_results.size() > m)
                    break;
            }

            if (mst_results.size() > m)
                min_flips = min(min_flips, flips);
        }

        cout << min_flips << '\n';
    }
}
