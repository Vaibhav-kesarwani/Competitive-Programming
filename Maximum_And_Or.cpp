#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
// using namespace std;

using namespace __gnu_pbds;

 

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; 

typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update> pbdsg;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbdsm;

// find_by_order(x) : returns the elements at index x;(iterator is returned)

// order_of_key(x) : tells nuber of elements less than x

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define MOD 1000000007

#define MOD1 998244353

#define INF 1e18

#define eb emplace_back

#define e emplace

#define endl "\n"

#define pb push_back

#define ppb pop_back

#define mp make_pair

#define ff first

#define ss second

#define PI 3.141592653589793238462

#define set_bits __builtin_popcountll

#define sz(x) ((int)(x).size())

#define all(x) (x).begin(), (x).end()

#define sqrt sqrtl

 

typedef long long ll;

typedef unsigned long long ull;

typedef long double lld;

// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

 

#ifndef ONLINE_JUDGE

#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;

#else

#define debug(x)

#endif

 

void _print(ll t) {cerr << t;}

void _print(int t) {cerr << t;}

void _print(string t) {cerr << t;}

void _print(char t) {cerr << t;}

void _print(lld t) {cerr << t;}

void _print(double t) {cerr << t;}

void _print(ull t) {cerr << t;}

 

template <class T, class V> void _print(pair <T, V> p);

template <class T> void _print(vector <T> v);

template <class T> void _print(set <T> v);

template <class T, class V> void _print(map <T, V> v);

template <class T> void _print(multiset <T> v);

template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}

template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}

template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}

template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}

template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";};







// 1









void solve(){

  ll a,b,c;

  cin>>a>>b>>c;

  ll ans=1;

  for(ll i=0;i<c;i++){

    ll num1=a&(1ll<<i);

    ll num2=b&(1ll<<i);

    if(num1==num2){

      ans=ans*1;

    }

    else{

      ans=ans*2;

    }

  }

  cout<<ans<<endl;

}



 

 

 

int main() {

ios_base::sync_with_stdio(false);
cin.tie(nullptr);

// #ifndef ONLINE_JUDGE

// 	freopen("Error.txt", "w", stderr);

//   freopen("input.txt", "r", stdin);

//   freopen("output.txt", "w", stdout);

// #endif

ll t=1;

cin>>t;

while(t--){

  solve();

}

return 0;

}