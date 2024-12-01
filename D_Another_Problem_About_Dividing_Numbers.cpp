/*
 * author:     Normalizerr
 * created:    2024-12-01 09:26:35
*/


// including the files
#include <bits/stdc++.h>
using namespace std;

// <============================================STARTING OF THE TEMPLATE===========================================================>

// different kind of for states
#define for0(i, n) for (int i = 0; i < (int)(n); ++i) // 0 based indexing
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i) // 1 based indexing
#define forc(i, l, r) for (int i = (int)(l); i <= (int)(r); ++i) // closed interver from l to r r inclusive
#define forr0(i, n) for (int i = (int)(n) - 1; i >= 0; --i) // reverse 0 based.
#define forr1(i, n) for (int i = (int)(n); i >= 1; --i) // reverse 1 based
#define fora(a) for(auto u:a) // for the linear traveral

//short hand for usual tokens
#define pb push_back
#define fi first
#define se second
#define nt << "\n";
#define yes cout << "YES"
#define no cout << "NO"
#define Yes cout << "Yes"
#define No cout << "No"

// make the code to run faster
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(0);
#define Vaibhav cout.tie(0);

// to be used with algorithms that processes a container Eg: find(all(c),42)
#define all(x) (x).begin(), (x).end() //Forward traversal
#define rall(x) (x).rbegin, (x).rend() //reverse traversal
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b)))

// traversal function to avoid long template definition. Now with C++11 auto alleviates the pain.
#define tr(c,i) for(__typeof__((c)).begin() i = (c).begin(); i != (c).end(); i++)

// find if a given value is present in a container. Container version. Runs in log(n) for set and map
#define present(c,x) ((c).find(x) != (c).end())

//find version works for all containers. This is present in std namespace.
#define cpresent(c,x) (find(all(c),x) != (c).end())

// Avoiding wrap around of size()-1 where size is a unsigned int.
#define sz(a) int((a).size())

// Shorthand for commonly used types
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef set<int> si;
typedef map<int, int> mii;
typedef double ld;

// some of the constant values
const long double pi = 3.141592653589793238;
const int INF = INT_MAX;
const int mod = 1000000007;

// pre-intialised values
int x, y, z, a, b, c, d;
int cnt = 0, ans = 0;

// <============================================ENDING OF THE TEMPLATE===========================================================>
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

// solve function
void Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai() {
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
  cout << (check(divs, divs.begin(), divsA, divsB, low, high, k) ? "YES" : "NO") nt
}

// main function
signed main () {
    Code By Vaibhav
    int Bhai_Test_Case_Hai_Ya; cin >> Bhai_Test_Case_Hai_Ya; while (Bhai_Test_Case_Hai_Ya-- > 0)
        Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai();

    return 0;
}