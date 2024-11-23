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


int N;
vector<Int> A;

int main() {
  for (int numCases; ~scanf("%d", &numCases); ) { for (int caseId = 1; caseId <= numCases; ++caseId) {
    scanf("%d", &N);
    A.resize(N);
    for (int i = 0; i < N; ++i) {
      scanf("%lld", &A[i]);
    }
    sort(A.begin(), A.end());
    
    vector<int> bs;
    for (int i = 0; i < N; ) {
      if (i + 1 < N && A[i] == A[i + 1]) {
        bs.push_back(A[i]);
        i += 2;
      } else {
        i += 1;
      }
    }
    const int bsLen = bs.size();
    if (bsLen >= 4) {
      Int xs[4], ys[4];
      xs[0] = xs[1] = bs[0];
      xs[2] = xs[3] = bs[bsLen - 2];
      ys[0] = ys[2] = bs[1];
      ys[1] = ys[3] = bs[bsLen - 1];
      puts("YES");
      for (int u = 0; u < 4; ++u) {
        if (u) printf(" ");
        printf("%lld %lld", xs[u], ys[u]);
      }
      puts("");
    } else {
      puts("NO");
    }
  }
#ifndef LOCAL
  break;
#endif
  }
  return 0;
}
