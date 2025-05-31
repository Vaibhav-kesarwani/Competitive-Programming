/*
 * Author        :         Vaibhav Kesarwani
 * Date          :         2025-05-31
 * Time          :         10:50
 * Website       :         https://vaibhavkesarwani.vercel.app/
 * Github        :         https://github.com/Vaibhav-kesarwani
 * LinkedIn      :         https://www.linkedin.com/in/vaibhavdev
*/


// including the files
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

// <============================================STARTING OF THE TEMPLATE===========================================================>

// some of the constant values
const long double pi = 3.141592653589793238;
const int INF = INT_MAX;
const int mod = 1000000007;

// different kind of for states
#define for0(i, n) for (int i = 0; i < (int)(n); ++i) // 0 based indexing
#define for01(i, n) for (int i = 0; i <= (int)(n); ++i) // 0 based indexing from 0 to n
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i) // 1 based indexing
#define for10(i, n) for (int i = 1; i < (int)(n); ++i) // 1 based indexing from 1 to n-1
#define forl0(i, l, r) for (int i = (int)(l); i < (int)(r); ++i) // closed interver from l to r r exclusive
#define forc(i, l, r) for (int i = (int)(l); i <= (int)(r); ++i) // closed interver from l to r r inclusive
#define forr0(i, n) for (int i = (int)(n) - 1; i >= 0; --i) // reverse 0 based.
#define forr1(i, n) for (int i = (int)(n); i >= 1; --i) // reverse 1 based
#define fora(a) for(auto i:a) // for the linear traveral

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

// Custom Functions
int binpow (int a, int n) {
  if (n == 0) return 1;
  if (n % 2 == 1) return (a * binpow(a, n / 2)) % mod;
  else {
    int temp = binpow(a, n / 2);
    return (temp * temp) % mod;  
  }
}

int inverse (int x) {
  return binpow(x, (mod - 2));
}

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
typedef set<ll> sll;
typedef unordered_set<int> usi;
typedef unordered_set<ll> usll;
typedef unordered_map<int, int> umii;
typedef unordered_map<ll, ll> umll;
typedef map<int, int> mii;
typedef map<ll, ll> mll;
typedef double ld;

// pre-intialised values
ll n, x, y, z, a, b, c, d, k, l, m;
string s, t;
ll cnt = 0, ans = 0, sum = 0;

// <============================================ENDING OF THE TEMPLATE===========================================================>

// solve function
void Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai() {
    cin >> n;
    cnt = 0;

    for0 (i, n) {
        cin >> x;
        if (x % 2 != 0) cnt++;
    }

    ((cnt % 2 == 0) ? yes : no) nt
}

// main function
int32_t main () {
    Code By Vaibhav
    int Bhai_Test_Case_Hai_Ya; cin >> Bhai_Test_Case_Hai_Ya; while (Bhai_Test_Case_Hai_Ya-- > 0)
        Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai();

    return 0;
}