#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using cd = complex<ld>;

const int N = 50'000;

bool isPrime[N];
vector<int> primes;

void precalc() {
  fill(isPrime + 2, isPrime + N, true);
  for (int i = 2; i * i < N; i++) {
    for (int j = i * i; j < N; j += i) {
      isPrime[j] = false;
    }
  }
  for (int i = 2; i < N; i++) {
    if (isPrime[i]) {
      primes.push_back(i);
    }
  }
}

int calcPrime(int n) {
  int res = 0;
  for (int i : primes) {
    if (i * i > n) {
      break;
    }
    while (n % i == 0) {
      n /= i;
      res++;
    }
  }
  if (n > 1) {
    res++;
  }
  return res;
}

map<int, int> decompose(int n) {
  map<int, int> a;
  for (int i : primes) {
    if (i * i > n) {
      break;
    }
    int p = 0;
    while (n % i == 0) {
      n /= i;
      p++;
    }
    if (p > 0) {
      a[i] = p;
    }
  }
  if (n > 1) {
    a[n] = 1;
  }
  return a;
}

bool check(const map<int, int> &divs,
           map<int, int>::const_iterator it,
           map<int, int> &divsA,
           map<int, int> &divsB,
           int low,
           int high,
           int k) {
  if (it == divs.end()) {
    return __builtin_popcount(low) <= k && k <= high;
  }
  for (int p = 0; p <= it->second; p++) {
    int pa = divsA[it->first];
    int pb = divsB[it->first];
    int nextLow = low;
    if (p != pa) {
      nextLow |= 1;
    }
    if (p != pb) {
      nextLow |= 2;
    }
    if (check(divs, next(it), divsA, divsB, nextLow, high + pa + pb - 2 * p, k)) {
      return true;
    }
  }
  return false;
}

void solve() {
  int a, b, k;
  cin >> a >> b >> k;
  int g = __gcd(a, b);
  int low = 0;
  int high = 0;
  {
    int t;
    int ta = 1;
    while ((t = __gcd(a, g)) != 1) {
      a /= t;
      ta *= t;
    }
    high += calcPrime(a);
    if (a != 1) {
      low |= 1;
    }
    a = ta;
  }
  {
    int t;
    int tb = 1;
    while ((t = __gcd(b, g)) != 1) {
      b /= t;
      tb *= t;
    }
    high += calcPrime(b);
    if (b != 1) {
      low |= 2;
    }
    b = tb;
  }
  auto divs = decompose(g);
  auto divsA = decompose(a);
  auto divsB = decompose(b);
  cout << (check(divs, divs.begin(), divsA, divsB, low, high, k) ? "YES" : "NO") << endl;
}

int main() {
  precalc();

  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}