#include <cassert>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

using Int = long long;

template <class T1, class T2> ostream &operator<<(ostream &os, const pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; ++i) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << endl; }
template <class T> bool chmin(T &t, const T &f) { if (t > f) { t = f; return true; } return false; }
template <class T> bool chmax(T &t, const T &f) { if (t < f) { t = f; return true; } return false; }
#define COLOR(s) ("\x1b[" s "m")


constexpr double INF = 1e+10;

// n, deck gomi, hand gomi, hand good
map<int, double> cache[4 + 1][52 + 1][52 + 1];
double calc(int n, int a, int b, int p) {
  auto it = cache[n][a][b].find(p);
  if (it != cache[n][a][b].end()) return it->second;
  double ret = INF;
  
  const int pop = __builtin_popcount(p);
  if (b + pop < 5) {
    // draw
    const int deck = a + (n*5 - pop);
    if (deck) {
      ret = 0.0;
      if (a) {
        ret += ((double)a / deck) * calc(n, a - 1, b + 1, p);
      }
      for (int x = 0; x < n*5; ++x) if (!(p & 1 << x)) {
        ret += (1.0 / deck) * calc(n, a, b, p | 1 << x);
      }
    }
  } else {
    assert(b + pop == 5);
    bool win = false;
    for (int i = 0; i < n; ++i) {
      bool ok = true;
      for (int x = i*5; x < (i+1)*5; ++x) ok = ok && (p & 1 << x);
      win = win || ok;
    }
    if (win) {
      ret = 0.0;
    } else {
      // discard
      for (int db = 0; db <= b; ++db) {
        for (int dp = p; ; --dp &= p) {
          if (db || dp) {
            int tr[4];
            fill(tr, tr + n, -2);
            for (int x = 0; x < n*5; ++x) if (dp & 1 << x) tr[x/5] = -1;
            int nn = 0;
            for (int i = 0; i < n; ++i) if (~tr[i]) tr[i] = nn++;
            int aa = a;
            int bb = b - db;
            int pp = 0;
            // deck gomika
            for (int x = 0; x < n*5; ++x) if (!(p & 1 << x)) {
              if (!~tr[x/5]) {
                ++aa;
              }
            }
            // new hand
            for (int x = 0; x < n*5; ++x) if ((p - dp) & 1 << x) {
              if (~tr[x/5]) {
                pp |= 1 << (tr[x/5]*5+(x%5));
              } else {
                ++bb;
              }
            }
            chmin(ret, calc(nn, aa, bb, pp));
          }
          if (!dp) break;
        }
      }
      ret += 1.0;
    }
  }
  
// cerr<<n<<" "<<a<<" "<<b<<" "<<p<<": "<<ret<<endl;
  return cache[n][a][b][p] = ret;
}

const double ANS[4 + 1] = {0,
3.598290598290597,
8.067171308522770,
12.423075934638065,
16.636642360808395,
};

int main() {
  int N;
  for (; ~scanf("%d", &N); ) {
    // const double ans = calc(N, N*8, 0, 0);
    const double ans = ANS[N];
    printf("%.15f\n", ans);
  }
  return 0;
}
    