/*
 * Author        :         Vaibhav Kesarwani
 * Created       :         December 27, 2024 08:52:27
 * Workspace     :         ~/Desktop/Competitive-Programming
 * Problem name  :         M_Mirror_Maze
*/


// including the files
#include <bits/stdc++.h>
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
ll n, x, y, z, a, b, c, d;
string s, t;
ll cnt = 0, ans = 0, sum = 0;

// <============================================ENDING OF THE TEMPLATE===========================================================>

// solve function
void Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai() {
    int R, C;
	cin >> R >> C;
	vector<string> grid(R);
	for(int i = 0; i < R; i++){
		cin >> grid[i];
	}
	vector<pair<int,int>> slocs;
	vector<int> sdirs;
	vector<string> outputs;
	vector<int> dx = {-1, 0, 1, 0};
	vector<int> dy = {0, 1, 0, -1};
	for(int i = 0; i < R; i++){
		outputs.push_back("W" + to_string(i+1));
		slocs.push_back({i, 0});
		sdirs.push_back(1);
	}
	for(int i = 0; i < R; i++){
		outputs.push_back("E" + to_string(i+1));
		slocs.push_back({i, C-1});
		sdirs.push_back(3);
	}
	for(int i = 0; i < C; i++){
		outputs.push_back("N" + to_string(i+1));
		slocs.push_back({0, i});
		sdirs.push_back(2);
	}
	for(int i = 0; i < C; i++){
		outputs.push_back("S" + to_string(i+1));
		slocs.push_back({R-1, i});
		sdirs.push_back(0);
	}
 
	int nlaser = 0;
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			if(grid[i][j] == '/' || grid[i][j] == '\\') nlaser++;
		}
	}
 
	vector<string> ans;
 
	for(int idx = 0; idx < (int)outputs.size(); idx++){
		pair<int,int> loc = slocs[idx];
		int dir = sdirs[idx];
		bitset<200*200> bs;
		while(true){
			if(loc.first < 0 || loc.second < 0 || loc.first >= R || loc.second >= C) break;
			if(grid[loc.first][loc.second] == '/'){
				dir ^= 1;
				bs[loc.first*C + loc.second] = 1;
			} else if(grid[loc.first][loc.second] == '\\'){
				dir ^= 3;
				bs[loc.first*C + loc.second] = 1;
			}
			loc.first += dx[dir];
			loc.second += dy[dir];
		}
		if(bs.count() == nlaser){
			ans.push_back(outputs[idx]);
		}
	}
	cout << ans.size() << '\n';
	if(!ans.empty()){
		for(int i = 0; i < (int)ans.size(); i++){
			cout << ans[i] << " \n"[i+1 == (int)ans.size()];
		}
	}
}

// main function
int32_t main () {
    Code By Vaibhav
    // int Bhai_Test_Case_Hai_Ya; cin >> Bhai_Test_Case_Hai_Ya; while (Bhai_Test_Case_Hai_Ya-- > 0)
        Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai();

    return 0;
}