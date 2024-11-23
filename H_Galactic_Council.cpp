#line 1 "library/my_template.hpp"
#if defined(LOCAL)
#include <my_template_compiled.hpp>
#else


#pragma GCC optimize("Ofast,unroll-loops")



#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using u8 = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;
using i128 = __int128;
using u128 = unsigned __int128;
using f128 = __float128;

template <class T>
constexpr T infty = 0;
template <>
constexpr int infty<int> = 1'010'000'000;
template <>
constexpr ll infty<ll> = 2'020'000'000'000'000'000;
template <>
constexpr u32 infty<u32> = infty<int>;
template <>
constexpr u64 infty<u64> = infty<ll>;
template <>
constexpr i128 infty<i128> = i128(infty<ll>) * 2'000'000'000'000'000'000;
template <>
constexpr double infty<double> = infty<ll>;
template <>
constexpr long double infty<long double> = infty<ll>;

using pi = pair<ll, ll>;
using vi = vector<ll>;
template <class T>
using vc = vector<T>;
template <class T>
using vvc = vector<vc<T>>;
template <class T>
using vvvc = vector<vvc<T>>;
template <class T>
using vvvvc = vector<vvvc<T>>;
template <class T>
using vvvvvc = vector<vvvvc<T>>;
template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;

#define vv(type, name, h, ...) vector<vector<type>> name(h, vector<type>(__VA_ARGS__))
#define vvv(type, name, h, w, ...) vector<vector<vector<type>>> name(h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))
#define vvvv(type, name, a, b, c, ...) \
  vector<vector<vector<vector<type>>>> name(a, vector<vector<vector<type>>>(b, vector<vector<type>>(c, vector<type>(__VA_ARGS__))))


#define FOR1(a) for (ll _ = 0; _ < ll(a); ++_)
#define FOR2(i, a) for (ll i = 0; i < ll(a); ++i)
#define FOR3(i, a, b) for (ll i = a; i < ll(b); ++i)
#define FOR4(i, a, b, c) for (ll i = a; i < ll(b); i += (c))
#define FOR1_R(a) for (ll i = (a)-1; i >= ll(0); --i)
#define FOR2_R(i, a) for (ll i = (a)-1; i >= ll(0); --i)
#define FOR3_R(i, a, b) for (ll i = (b)-1; i >= ll(a); --i)
#define overload4(a, b, c, d, e, ...) e
#define overload3(a, b, c, d, ...) d
#define FOR(...) overload4(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)
#define FOR_R(...) overload3(__VA_ARGS__, FOR3_R, FOR2_R, FOR1_R)(__VA_ARGS__)

#define FOR_subset(t, s) for (ll t = (s); t >= 0; t = (t == 0 ? -1 : (t - 1) & (s)))
#define all(x) x.begin(), x.end()
#define len(x) ll(x.size())
#define elif else if

#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second

#define stoi stoll

int popcnt(int x) { return __builtin_popcount(x); }
int popcnt(u32 x) { return __builtin_popcount(x); }
int popcnt(ll x) { return __builtin_popcountll(x); }
int popcnt(u64 x) { return __builtin_popcountll(x); }
int popcnt_sgn(int x) { return (__builtin_parity(x) & 1 ? -1 : 1); }
int popcnt_sgn(u32 x) { return (__builtin_parity(x) & 1 ? -1 : 1); }
int popcnt_sgn(ll x) { return (__builtin_parity(x) & 1 ? -1 : 1); }
int popcnt_sgn(u64 x) { return (__builtin_parity(x) & 1 ? -1 : 1); }

int topbit(int x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }
int topbit(u32 x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }
int topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }
int topbit(u64 x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }

int lowbit(int x) { return (x == 0 ? -1 : __builtin_ctz(x)); }
int lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x)); }
int lowbit(ll x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }
int lowbit(u64 x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }

template <typename T>
T kth_bit(int k) {
  return T(1) << k;
}
template <typename T>
bool has_kth_bit(T x, int k) {
  return x >> k & 1;
}

template <typename T>
T floor(T a, T b) {
  return a / b - (a % b && (a ^ b) < 0);
}
template <typename T>
T ceil(T x, T y) {
  return floor(x + y - 1, y);
}
template <typename T>
T bmod(T x, T y) {
  return x - y * floor(x, y);
}
template <typename T>
pair<T, T> divmod(T x, T y) {
  T q = floor(x, y);
  return {q, x - q * y};
}

template <typename T, typename U>
T SUM(const vector<U> &A) {
  T sm = 0;
  for (auto &&a: A) sm += a;
  return sm;
}

#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))
#define LB(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define UB(c, x) distance((c).begin(), upper_bound(all(c), (x)))
#define UNIQUE(x) sort(all(x)), x.erase(unique(all(x)), x.end()), x.shrink_to_fit()

template <typename T>
T POP(deque<T> &que) {
  T a = que.front();
  que.pop_front();
  return a;
}
template <typename T>
T POP(pq<T> &que) {
  T a = que.top();
  que.pop();
  return a;
}
template <typename T>
T POP(pqg<T> &que) {
  T a = que.top();
  que.pop();
  return a;
}
template <typename T>
T POP(vc<T> &que) {
  T a = que.back();
  que.pop_back();
  return a;
}

template <typename F>
ll binary_search(F check, ll ok, ll ng, bool check_ok = true) {
  if (check_ok) assert(check(ok));
  while (abs(ok - ng) > 1) {
    auto x = (ng + ok) / 2;
    (check(x) ? ok : ng) = x;
  }
  return ok;
}
template <typename F>
double binary_search_real(F check, double ok, double ng, int iter = 100) {
  FOR(iter) {
    double x = (ok + ng) / 2;
    (check(x) ? ok : ng) = x;
  }
  return (ok + ng) / 2;
}

template <class T, class S>
inline bool chmax(T &a, const S &b) {
  return (a < b ? a = b, 1 : 0);
}
template <class T, class S>
inline bool chmin(T &a, const S &b) {
  return (a > b ? a = b, 1 : 0);
}


vc<int> s_to_vi(const string &S, char first_char) {
  vc<int> A(S.size());
  FOR(i, S.size()) { A[i] = (S[i] != '?' ? S[i] - first_char : -1); }
  return A;
}

template <typename T, typename U>
vector<T> cumsum(vector<U> &A, int off = 1) {
  int N = A.size();
  vector<T> B(N + 1);
  FOR(i, N) { B[i + 1] = B[i] + A[i]; }
  if (off == 0) B.erase(B.begin());
  return B;
}


template <typename T>
vector<int> argsort(const vector<T> &A) {
  vector<int> ids(len(A));
  iota(all(ids), 0);
  sort(all(ids), [&](int i, int j) { return (A[i] == A[j] ? i < j : A[i] < A[j]); });
  return ids;
}


template <typename T>
vc<T> rearrange(const vc<T> &A, const vc<int> &I) {
  vc<T> B(len(I));
  FOR(i, len(I)) B[i] = A[I[i]];
  return B;
}

template <typename T, typename... Vectors>
void concat(vc<T> &first, const Vectors &... others) {
  vc<T> &res = first;
  (res.insert(res.end(), others.begin(), others.end()), ...);
}
#endif
#line 1 "library/other/io.hpp"
#define FASTIO
#include <unistd.h>


namespace fastio {
static constexpr uint32_t SZ = 1 << 17;
char ibuf[SZ];
char obuf[SZ];
char out[100];

uint32_t pil = 0, pir = 0, por = 0;

struct Pre {
  char num[10000][4];
  constexpr Pre() : num() {
    for (int i = 0; i < 10000; i++) {
      int n = i;
      for (int j = 3; j >= 0; j--) {
        num[i][j] = n % 10 | '0';
        n /= 10;
      }
    }
  }
} constexpr pre;

inline void load() {
  memcpy(ibuf, ibuf + pil, pir - pil);
  pir = pir - pil + fread(ibuf + pir - pil, 1, SZ - pir + pil, stdin);
  pil = 0;
  if (pir < SZ) ibuf[pir++] = '\n';
}

inline void flush() {
  fwrite(obuf, 1, por, stdout);
  por = 0;
}

void rd(char &c) {
  do {
    if (pil + 1 > pir) load();
    c = ibuf[pil++];
  } while (isspace(c));
}

void rd(string &x) {
  x.clear();
  char c;
  do {
    if (pil + 1 > pir) load();
    c = ibuf[pil++];
  } while (isspace(c));
  do {
    x += c;
    if (pil == pir) load();
    c = ibuf[pil++];
  } while (!isspace(c));
}

template <typename T>
void rd_real(T &x) {
  string s;
  rd(s);
  x = stod(s);
}

template <typename T>
void rd_integer(T &x) {
  if (pil + 100 > pir) load();
  char c;
  do
    c = ibuf[pil++];
  while (c < '-');
  bool minus = 0;
  if constexpr (is_signed<T>::value || is_same_v<T, i128>) {
    if (c == '-') { minus = 1, c = ibuf[pil++]; }
  }
  x = 0;
  while ('0' <= c) { x = x * 10 + (c & 15), c = ibuf[pil++]; }
  if constexpr (is_signed<T>::value || is_same_v<T, i128>) {
    if (minus) x = -x;
  }
}

void rd(int &x) { rd_integer(x); }
void rd(ll &x) { rd_integer(x); }
void rd(i128 &x) { rd_integer(x); }
void rd(u32 &x) { rd_integer(x); }
void rd(u64 &x) { rd_integer(x); }
void rd(u128 &x) { rd_integer(x); }
void rd(double &x) { rd_real(x); }
void rd(long double &x) { rd_real(x); }
void rd(f128 &x) { rd_real(x); }

template <class T, class U>
void rd(pair<T, U> &p) {
  return rd(p.first), rd(p.second);
}
template <size_t N = 0, typename T>
void rd_tuple(T &t) {
  if constexpr (N < std::tuple_size<T>::value) {
    auto &x = std::get<N>(t);
    rd(x);
    rd_tuple<N + 1>(t);
  }
}
template <class... T>
void rd(tuple<T...> &tpl) {
  rd_tuple(tpl);
}

template <size_t N = 0, typename T>
void rd(array<T, N> &x) {
  for (auto &d: x) rd(d);
}
template <class T>
void rd(vc<T> &x) {
  for (auto &d: x) rd(d);
}

void read() {}
template <class H, class... T>
void read(H &h, T &... t) {
  rd(h), read(t...);
}

void wt(const char c) {
  if (por == SZ) flush();
  obuf[por++] = c;
}
void wt(const string s) {
  for (char c: s) wt(c);
}
void wt(const char *s) {
  size_t len = strlen(s);
  for (size_t i = 0; i < len; i++) wt(s[i]);
}

template <typename T>
void wt_integer(T x) {
  if (por > SZ - 100) flush();
  if (x < 0) { obuf[por++] = '-', x = -x; }
  int outi;
  for (outi = 96; x >= 10000; outi -= 4) {
    memcpy(out + outi, pre.num[x % 10000], 4);
    x /= 10000;
  }
  if (x >= 1000) {
    memcpy(obuf + por, pre.num[x], 4);
    por += 4;
  } else if (x >= 100) {
    memcpy(obuf + por, pre.num[x] + 1, 3);
    por += 3;
  } else if (x >= 10) {
    int q = (x * 103) >> 10;
    obuf[por] = q | '0';
    obuf[por + 1] = (x - q * 10) | '0';
    por += 2;
  } else
    obuf[por++] = x | '0';
  memcpy(obuf + por, out + outi + 4, 96 - outi);
  por += 96 - outi;
}

template <typename T>
void wt_real(T x) {
  ostringstream oss;
  oss << fixed << setprecision(15) << double(x);
  string s = oss.str();
  wt(s);
}

void wt(int x) { wt_integer(x); }
void wt(ll x) { wt_integer(x); }
void wt(i128 x) { wt_integer(x); }
void wt(u32 x) { wt_integer(x); }
void wt(u64 x) { wt_integer(x); }
void wt(u128 x) { wt_integer(x); }
void wt(double x) { wt_real(x); }
void wt(long double x) { wt_real(x); }
void wt(f128 x) { wt_real(x); }

template <class T, class U>
void wt(const pair<T, U> val) {
  wt(val.first);
  wt(' ');
  wt(val.second);
}
template <size_t N = 0, typename T>
void wt_tuple(const T t) {
  if constexpr (N < std::tuple_size<T>::value) {
    if constexpr (N > 0) { wt(' '); }
    const auto x = std::get<N>(t);
    wt(x);
    wt_tuple<N + 1>(t);
  }
}
template <class... T>
void wt(tuple<T...> tpl) {
  wt_tuple(tpl);
}
template <class T, size_t S>
void wt(const array<T, S> val) {
  auto n = val.size();
  for (size_t i = 0; i < n; i++) {
    if (i) wt(' ');
    wt(val[i]);
  }
}
template <class T>
void wt(const vector<T> val) {
  auto n = val.size();
  for (size_t i = 0; i < n; i++) {
    if (i) wt(' ');
    wt(val[i]);
  }
}

void print() { wt('\n'); }
template <class Head, class... Tail>
void print(Head &&head, Tail &&... tail) {
  wt(head);
  if (sizeof...(Tail)) wt(' ');
  print(forward<Tail>(tail)...);
}


void __attribute__((destructor)) _d() { flush(); }
} 
using fastio::read;
using fastio::print;
using fastio::flush;

#if defined(LOCAL)
#define SHOW(...) SHOW_IMPL(__VA_ARGS__, SHOW6, SHOW5, SHOW4, SHOW3, SHOW2, SHOW1)(__VA_ARGS__)
#define SHOW_IMPL(_1, _2, _3, _4, _5, _6, NAME, ...) NAME
#define SHOW1(x) print(#x, "=", (x)), flush()
#define SHOW2(x, y) print(#x, "=", (x), #y, "=", (y)), flush()
#define SHOW3(x, y, z) print(#x, "=", (x), #y, "=", (y), #z, "=", (z)), flush()
#define SHOW4(x, y, z, w) print(#x, "=", (x), #y, "=", (y), #z, "=", (z), #w, "=", (w)), flush()
#define SHOW5(x, y, z, w, v) print(#x, "=", (x), #y, "=", (y), #z, "=", (z), #w, "=", (w), #v, "=", (v)), flush()
#define SHOW6(x, y, z, w, v, u) print(#x, "=", (x), #y, "=", (y), #z, "=", (z), #w, "=", (w), #v, "=", (v), #u, "=", (u)), flush()
#else
#define SHOW(...)
#endif

#define INT(...)   \
  int __VA_ARGS__; \
  read(__VA_ARGS__)
#define LL(...)   \
  ll __VA_ARGS__; \
  read(__VA_ARGS__)
#define U32(...)   \
  u32 __VA_ARGS__; \
  read(__VA_ARGS__)
#define U64(...)   \
  u64 __VA_ARGS__; \
  read(__VA_ARGS__)
#define STR(...)      \
  string __VA_ARGS__; \
  read(__VA_ARGS__)
#define CHAR(...)   \
  char __VA_ARGS__; \
  read(__VA_ARGS__)
#define DBL(...)      \
  double __VA_ARGS__; \
  read(__VA_ARGS__)

#define VEC(type, name, size) \
  vector<type> name(size);    \
  read(name)
#define VV(type, name, h, w)                     \
  vector<vector<type>> name(h, vector<type>(w)); \
  read(name)

void YES(bool t = 1) { print(t ? "YES" : "NO"); }
void NO(bool t = 1) { YES(!t); }
void Yes(bool t = 1) { print(t ? "Yes" : "No"); }
void No(bool t = 1) { Yes(!t); }
void yes(bool t = 1) { print(t ? "yes" : "no"); }
void no(bool t = 1) { yes(!t); }
#line 3 "main.cpp"

#line 2 "library/flow/bflow.hpp"
template <class Flow = ll, class Cost = ll>
struct MinCostFlow {
private:
  static constexpr int SCALING_FACTOR = 2;
  using V_id = uint32_t;
  using E_id = uint32_t;

  struct Edge {
    friend struct MinCostFlow;

  private:
    V_id frm, to;
    Flow flow, cap;
    Cost cost;
    E_id rev;

  public:
    Edge() = default;

    Edge(const V_id frm, const V_id to, const Flow cap, const Cost cost,
         const E_id rev)
        : frm(frm), to(to), flow(0), cap(cap), cost(cost), rev(rev) {}

    [[nodiscard]] Flow residual_cap() const { return cap - flow; }
  };

public:
  struct EdgePtr {
    friend struct MinCostFlow;

  private:
    const MinCostFlow *instance;
    const V_id v;
    const E_id e;

    EdgePtr(const MinCostFlow *instance, const V_id v, const E_id e)
        : instance(instance), v(v), e(e) {}

    [[nodiscard]] const Edge &edge() const { return instance->g[v][e]; }
    [[nodiscard]] const Edge &rev() const {
      const Edge &e = edge();
      return instance->g[e.to][e.rev];
    }

  public:
    [[nodiscard]] V_id frm() const { return rev().to; }
    [[nodiscard]] V_id to() const { return edge().to; }
    [[nodiscard]] Flow flow() const { return edge().flow; }
    [[nodiscard]] Flow lower() const { return -rev().cap; }
    [[nodiscard]] Flow upper() const { return edge().cap; }
    [[nodiscard]] Cost cost() const { return edge().cost; }
    [[nodiscard]] Cost gain() const { return -edge().cost; }
  };

private:
  V_id n;
  std::vector<std::vector<Edge>> g;
  std::vector<Flow> b;

public:
  MinCostFlow(int n) : n(n) {
    g.resize(n);
    b.resize(n);
  }

  V_id add_vertex() {
    ++n;
    g.resize(n);
    b.resize(n);
    return n - 1;
  }

  std::vector<V_id> add_vertices(const size_t size) {
    std::vector<V_id> ret;
    for (V_id i = 0; i < size; ++i) ret.emplace_back(n + i);
    n += size;
    g.resize(n);
    b.resize(n);
    return ret;
  }

  void add(const V_id frm, const V_id to, const Flow lo, const Flow hi,
           const Cost cost) {
    const E_id e = g[frm].size(), re = frm == to ? e + 1 : g[to].size();
    assert(lo <= hi);
    g[frm].emplace_back(Edge{frm, to, hi, cost, re});
    g[to].emplace_back(Edge{to, frm, -lo, -cost, e});
    edges.eb(EdgePtr{this, frm, e});
  }

  void add_source(const V_id v, const Flow amount) { b[v] += amount; }
  void add_sink(const V_id v, const Flow amount) { b[v] -= amount; }

private:
  static Cost constexpr unreachable = std::numeric_limits<Cost>::max();
  Cost farthest;
  vc<Cost> potential, dist;
  vc<Edge *> parent;
  pqg<pair<Cost, int>> pq;
  vc<V_id> excess_vs, deficit_vs;
  vc<EdgePtr> edges;
  Edge &rev(const Edge &e) { return g[e.to][e.rev]; }

  void push(Edge &e, const Flow amount) {
    e.flow += amount;
    g[e.to][e.rev].flow -= amount;
  }

  Cost residual_cost(const V_id frm, const V_id to, const Edge &e) {
    return e.cost + potential[frm] - potential[to];
  }

  bool dual(const Flow delta) {
    dist.assign(n, unreachable);
    parent.assign(n, nullptr);
    excess_vs.erase(
        remove_if(all(excess_vs), [&](const V_id v) { return b[v] < delta; }),
        end(excess_vs));
    deficit_vs.erase(
        remove_if(all(deficit_vs), [&](const V_id v) { return b[v] > -delta; }),
        end(deficit_vs));
    for (const auto v: excess_vs) pq.emplace(dist[v] = 0, v);
    farthest = 0;
    size_t deficit_count = 0;
    while (!pq.empty()) {
      const auto [d, u] = pq.top();
      pq.pop();
      if (dist[u] < d) continue;
      farthest = d;
      if (b[u] <= -delta) ++deficit_count;
      if (deficit_count >= deficit_vs.size()) break;
      for (auto &e: g[u]) {
        if (e.residual_cap() < delta) continue;
        const auto v = e.to;
        const auto new_dist = d + residual_cost(u, v, e);
        if (new_dist >= dist[v]) continue;
        pq.emplace(dist[v] = new_dist, v);
        parent[v] = &e;
      }
    }
    pq = decltype(pq)();
    for (V_id v = 0; v < n; ++v) {
      potential[v] += std::min(dist[v], farthest);
    }
    return deficit_count > 0;
  }

  void primal(const Flow delta) {
    for (const auto t: deficit_vs) {
      if (dist[t] > farthest) continue;
      Flow f = -b[t];
      V_id v;
      for (v = t; parent[v] != nullptr && f >= delta; v = parent[v]->frm) {
        f = std::min(f, parent[v]->residual_cap());
      }
      f = std::min(f, b[v]);
      if (f < delta) continue;
      for (v = t; parent[v] != nullptr;) {
        auto &e = *parent[v];
        push(e, f);
        const size_t u = parent[v]->frm;
        parent[v] = nullptr;
        v = u;
      }
      b[t] += f;
      b[v] -= f;
    }
  }

  void saturate_negative(const Flow delta) {
    excess_vs.clear();
    deficit_vs.clear();
    for (auto &es: g)
      for (auto &e: es) {
        const Flow rcap = e.residual_cap();
        const Cost rcost = residual_cost(e.frm, e.to, e);
        if (rcost < 0 && rcap >= delta) {
          push(e, rcap);
          b[e.frm] -= rcap;
          b[e.to] += rcap;
        }
      }
    for (V_id v = 0; v < n; ++v)
      if (b[v] != 0) { (b[v] > 0 ? excess_vs : deficit_vs).emplace_back(v); }
  }

public:
  std::pair<bool, i128> solve() {
    potential.resize(n);
    for (auto &es: g)
      for (auto &e: es) {
        const Flow rcap = e.residual_cap();
        if (rcap < 0) {
          push(e, rcap);
          b[e.frm] -= rcap;
          b[e.to] += rcap;
        }
      }
    Flow inf_flow = 1;
    for (const auto &es: g)
      for (const auto &e: es) inf_flow = std::max(inf_flow, e.residual_cap());
    Flow delta = 1;
    while (delta <= inf_flow) delta *= SCALING_FACTOR;

    for (delta /= SCALING_FACTOR; delta; delta /= SCALING_FACTOR) {
      saturate_negative(delta);
      while (dual(delta)) primal(delta);
    }

    i128 value = 0;
    for (const auto &es: g)
      for (const auto &e: es) { value += i128(e.flow) * e.cost; }
    value /= 2;

    if (excess_vs.empty() && deficit_vs.empty()) {
      return {true, value};
    } else {
      return {false, value};
    }
  }

  template <class T>
  T get_result_value() {
    T value = 0;
    for (const auto &es: g)
      for (const auto &e: es) { value += (T)(e.flow) * (T)(e.cost); }
    value /= (T)2;
    return value;
  }

  std::vector<Cost> get_potential() {
    std::fill(potential.begin(), potential.end(), 0);
    for (int i = 0; i < (int)n; i++)
      for (const auto &es: g)
        for (const auto &e: es)
          if (e.residual_cap() > 0)
            potential[e.to]
                = std::min(potential[e.to], potential[e.frm] + e.cost);
    return potential;
  }

  std::vector<EdgePtr> get_edges() { return edges; }
};
#line 5 "main.cpp"

void solve() {
  LL(N, M);
  
  VEC(ll, who, M);
  for (auto& x: who) --x;
  VV(ll, A, N, M);

  
  vi CNT(M);
  CNT[0] = 1;
  FOR(i, 1, M) {
    if (who[i] == who[i - 1]) {
      CNT[i] = CNT[i - 1];
    } else {
      if (who[i] < who[i - 1]) {
        CNT[i] = CNT[i - 1];
      } else {
        CNT[i] = CNT[i - 1] + 1;
      }
    }
  };
  
  auto idx1 = [&](int i, int j) -> int {
    assert(0 <= i && i < N);
    assert(0 <= j && j <= M);
    return (M + 1) * i + j;
  };
  auto idx2 = [&](int i) -> int {
    assert(0 <= i && i < M);
    
    return (M + 1) * N + i;
  };
  int t = idx2(M - 1) + 1;

  MinCostFlow<ll, ll> G(t + 1);
  
  FOR(i, N) FOR(j, M) {
    ll lo = 0, hi = 0;
    if (i < who[j]) { lo = 0, hi = CNT[j] - 1; }
    if (i == who[j]) { lo = CNT[j], hi = CNT[j]; }
    if (i > who[j]) { lo = 0, hi = CNT[j]; }
    G.add(idx1(i, j), idx1(i, j + 1), lo, hi, 0);
  }
  
  FOR(i, N) FOR(j, M) { G.add(idx2(j), idx1(i, j), 0, 1, -A[i][j]); }
  
  FOR(j, M) G.add_source(idx2(j), 1);
  
  FOR(i, N) G.add(idx1(i, M), t, 0, M, 0);
  G.add_sink(t, M);

  auto [ok, ans] = G.solve();
  if (!ok) return print(-1);

  vi ANS(M, -1);
  for (auto& e: G.get_edges()) {
    int a = e.frm(), b = e.to();
    if (e.flow() == 0) continue;
    if (!(idx2(0) <= a && a <= idx2(M - 1))) continue;
    int j = a - idx2(0);
    int i = b / (M + 1);
    assert(b == idx1(i, j));
    ANS[j] = i;
  }

  for (auto& x: ANS) assert(x != -1);
  for (auto& x: ANS) ++x;
  print(ANS);
}

signed main() {
  solve();
  return 0;
}
