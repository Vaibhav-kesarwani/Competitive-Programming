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


/*
  (x2-x1) A[x0] + (x1-x0) A[x2] <= (x2-x0) A[x1]
  ==> x1 is useless
  
     y0 y1
  x0 o--o (y1-y0) A[x0]                 + (x2-x0) B[y1]
  x1    o 
  x2    o 
  
     y0 y1
  x0 o    
  x1 o--o (y1-y0) A[x1] + (x1-x0) B[y0] + (x2-x1) B[y1]
  x2    o 
  
     y0 y1
  x0 o    
  x1 o    
  x2 o--o (y1-y0) A[x2] + (x2-x0) B[y1]                
  
  remaining: convex
  
     y0 y1
  x0 o    
     |    (y1-y0) A[x1] + (x1-x0) B[y0]
  x1 o--o 
  
     y0 y1
  x0 o--o 
        | (y1-y0) A[x0] + (x1-x0) B[y1]
  x1    o 
  
  (A[x1]-A[x0])/(x1-x0) vs (B[y1]-B[y0])/(y1-y0)
*/

vector<int> hull(const vector<Int> &as) {
  auto elim = [&](int x0, int x1, int x2) -> bool {
    return ((x2-x1) * as[x0] + (x1-x0) * as[x2] <= (x2-x0) * as[x1]);
  };
  const int asLen = as.size();
  vector<int> xs;
  for (int x = 0; x < asLen; ++x) {
    for (; xs.size() >= 2 && elim(xs[xs.size() - 2], xs[xs.size() - 1], x); xs.pop_back()) {}
    xs.push_back(x);
  }
  return xs;
}

int M, N;
vector<Int> A, B;

void solve() {
  {
    const auto xs = hull(A);
    const auto ys = hull(B);
// cerr<<xs<<" "<<ys<<endl;
    const int xsLen = xs.size();
    const int ysLen = ys.size();
    Int ans = 0;
    for (int i = 0, j = 0; i < xsLen - 1 || j < ysLen - 1; ) {
      if (i < xsLen - 1 && (j == ysLen - 1 ||
          (ys[j+1]-ys[j]) * (A[xs[i+1]]-A[xs[i]]) <= (xs[i+1]-xs[i]) * (B[ys[j+1]]-B[ys[j]])
      )) {
        ans += (xs[i+1]-xs[i]) * B[ys[j]];
        ++i;
      } else {
        ans += (ys[j+1]-ys[j]) * A[xs[i]];
        ++j;
      }
    }
    
    // !
    for (int x = 0; x < M; ++x) ans += A[x];
    for (int y = 0; y < N; ++y) ans += B[y];
    
    printf("%lld\n", ans);
  }
}

int main() {
  int N, P, Q;
  for (; ~scanf("%d%d%d", &N, &P, &Q); ) {
    ::M = ::N = N;
    A.resize(N); for (int i = 0; i < N; ++i) A[i] = __gcd(i + 1, P);
    B.resize(N); for (int i = 0; i < N; ++i) B[i] = __gcd(i + 1, Q);
    solve();
  }
  return 0;
}
