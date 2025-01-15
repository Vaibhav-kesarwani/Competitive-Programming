// /*
//  * Author        :         Vaibhav Kesarwani
//  * Created       :         December 05, 2024 19:45:52
//  * Workspace     :         ~/Desktop/Competitive-Programming
//  * Problem name  :         B_osu_mania
// */


// // including the files
// #include <bits/stdc++.h>
// using namespace std;

// // <============================================STARTING OF THE TEMPLATE===========================================================>

// // different kind of for states
// #define for0(i, n) for (int i = 0; i < (int)(n); ++i) // 0 based indexing
// #define for1(i, n) for (int i = 1; i <= (int)(n); ++i) // 1 based indexing
// #define forc(i, l, r) for (int i = (int)(l); i <= (int)(r); ++i) // closed interver from l to r r inclusive
// #define forr0(i, n) for (int i = (int)(n) - 1; i >= 0; --i) // reverse 0 based.
// #define forr1(i, n) for (int i = (int)(n); i >= 1; --i) // reverse 1 based
// #define fora(a) for(auto i:a) // for the linear traveral

// //short hand for usual tokens
// #define pb push_back
// #define fi first
// #define se second
// #define nt << "\n";
// #define yes cout << "YES"
// #define no cout << "NO"
// #define Yes cout << "Yes"
// #define No cout << "No"

// // make the code to run faster
// #define Code ios_base::sync_with_stdio(false);
// #define By cin.tie(0);
// #define Vaibhav cout.tie(0);

// // to be used with algorithms that processes a container Eg: find(all(c),42)
// #define all(x) (x).begin(), (x).end() //Forward traversal
// #define rall(x) (x).rbegin, (x).rend() //reverse traversal
// #define gcd(a,b) __gcd(a,b)
// #define lcm(a,b) (a*(b/gcd(a,b)))

// // traversal function to avoid long template definition. Now with C++11 auto alleviates the pain.
// #define tr(c,i) for(__typeof__((c)).begin() i = (c).begin(); i != (c).end(); i++)

// // find if a given value is present in a container. Container version. Runs in log(n) for set and map
// #define present(c,x) ((c).find(x) != (c).end())

// //find version works for all containers. This is present in std namespace.
// #define cpresent(c,x) (find(all(c),x) != (c).end())

// // Avoiding wrap around of size()-1 where size is a unsigned int.
// #define sz(a) int((a).size())

// // Shorthand for commonly used types
// typedef vector<int> vi;
// typedef vector<vi> vvi;
// typedef pair<int, int> ii;
// typedef vector<ii> vii;
// typedef long long ll;
// typedef unsigned long long ull;
// typedef vector<char> vc;
// typedef vector<string> vs;
// typedef vector<ll> vll;
// typedef vector<vll> vvll;
// typedef set<int> si;
// typedef map<int, int> mii;
// typedef double ld;

// // some of the constant values
// const long double pi = 3.141592653589793238;
// const int INF = INT_MAX;
// const int mod = 1000000007;

// // pre-intialised values
// ll n, x, y, z, a, b, c, d;
// string s, t;
// ll cnt = 0, ans = 0;

// // <============================================ENDING OF THE TEMPLATE===========================================================>

// // solve function
// void Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai() {
//     cin >> n;
//     vi a;

//     for0(i, n) {
//         cin >> s;
//         for0(j, 4) {
//             if (s[j] == '#') {
//                 a.pb(j + 1);
//                 break;
//             }
//         }
//     }

//     forr0(i, n) cout << a[i] << " ";

//     cout nt
// }

// // main function
// int32_t main () {
//     Code By Vaibhav
//     int Bhai_Test_Case_Hai_Ya; cin >> Bhai_Test_Case_Hai_Ya; while (Bhai_Test_Case_Hai_Ya-- > 0)
//         Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai();

//     return 0;
// }

/*
 * Author        :         Vaibhav Kesarwani
 * Created       :         December 05, 2024 20:15:26
 * Workspace     :         ~/Desktop/Competitive-Programming
 * Problem name  :         B_osu_mania
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
ll n, x, y, z, a, b, c, d;
string s, t;
ll cnt = 0, ans = 0;

// <============================================ENDING OF THE TEMPLATE===========================================================>

// solve function
void Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai() {
    cin >> n;
    vector<vc> v(n, vc(4));

    for0(i, n) {
        for0(j, 4) {
            cin >> v[i][j];
        }
    }

    forr0(i, n) {
        forr0(j, 4) {
            if (v[i][j] == '#') cout << j + 1 << " ";
        }
    }

    cout nt
}

// main function
int32_t main () {
    Code By Vaibhav
    int Bhai_Test_Case_Hai_Ya; cin >> Bhai_Test_Case_Hai_Ya; while (Bhai_Test_Case_Hai_Ya-- > 0)
        Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai();

    return 0;
}