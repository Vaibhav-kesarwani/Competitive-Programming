/*
 * Author        :         Phoneix blaze
 * Date          :         2025-07-02
 * Time          :         20:28
*/

// <============================================INCLUDES===========================================================>

//Standard Headers
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

// <============================================MACROS & CONSTANTS===========================================================>

// Constants
const long double pi = 3.141592653589793238;
const int INF = INT_MAX;
const int mod = 1000000007;

// Loop Macros
#define for0(i, n) for (int i = 0; i < (int)(n); ++i)
#define for01(i, n) for (int i = 0; i <= (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define for10(i, n) for (int i = 1; i < (int)(n); ++i)
#define forl0(i, l, r) for (int i = (int)(l); i < (int)(r); ++i)
#define forc(i, l, r) for (int i = (int)(l); i <= (int)(r); ++i)
#define forr0(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define forr1(i, n) for (int i = (int)(n); i >= 1; --i)
#define fora(a) for(auto &i:a)

// Shorthand Macros
#define pb push_back
#define fi first
#define se second
#define nt << "\n";
#define yes cout << "YES"
#define no cout << "NO"
#define Yes cout << "Yes"
#define No cout << "No"
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b)))
#define sz(a) int((a).size())
#define tr(c,i) for(__typeof__((c)).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())

// Fast IO
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(0);
#define Vaibhav cout.tie(0);

// Debug (Optional)
#ifdef DEBUG
    #define debug(x) cerr << #x << " = " << x << endl;
#else
    #define debug(x)
#endif

// <============================================TYPEDEFS===========================================================>

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
typedef set<ll> sll;
typedef unordered_set<int> usi;
typedef unordered_set<ll> usll;
typedef unordered_map<int, int> umii;
typedef unordered_map<ll, ll> umll;
typedef map<int, int> mii;
typedef map<ll, ll> mll;
typedef double ld;

// <============================================INPUT/OUTPUT OPERATORS===========================================================>

template<typename T>
istream& operator>>(istream &in, vector<T> &v) { for (auto &x : v) in >> x; return in; }

template<typename T>
ostream& operator<<(ostream &out, const vector<T> &v) { for (const auto &x : v) out << x << " "; return out; }

// <============================================CUSTOM FUNCTIONS===========================================================>

int binpow(int a, int n) {
    if (n == 0) return 1;
    if (n % 2 == 1) return (1LL * a * binpow(a, n / 2) % mod * binpow(a, n / 2)) % mod;
    int temp = binpow(a, n / 2);
    return (1LL * temp * temp) % mod;
}

int inverse(int x) {
    return binpow(x, mod - 2);
}

// <============================================PRE-DECLARED VARIABLES===========================================================>

ll n, x, y, z, a, b, c, d, k, l, m;
string s, t;
ll cnt = 0, ans = 0, sum = 0;

// <============================================SOLVE FUNCTION===========================================================>

void Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai() {
    cin >> n;
    int odd{}, even{};

    for1(i, n) {
        if (n % i == 0) (i % 2 == 0 ? even++ : odd++);
    }

    cout << odd << " " << even nt
}

// <============================================MAIN FUNCTION===========================================================>

int32_t main() {
    Code By Vaibhav
    int Bhai_Test_Case_Hai_Ya; cin >> Bhai_Test_Case_Hai_Ya; while (Bhai_Test_Case_Hai_Ya-- > 0)
        Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai();
    return 0;
}