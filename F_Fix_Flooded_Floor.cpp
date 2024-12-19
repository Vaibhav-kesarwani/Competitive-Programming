#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef basic_string<int> BI;
typedef long long ll;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=201000;
char s[2][N];
int n;
void solve() {
	scanf("%d",&n);
	scanf("%s%s",s[0],s[1]);
	bool val=0;
	rep(i,0,n) {
		if (s[0][i]=='.'&&s[1][i]=='#') {
			if (i+1<n&&s[0][i+1]=='.') {
				s[0][i]='#';
				s[0][i+1]='#';
			} else {
				puts("None");
				return;
			}
		} else if (s[0][i]=='#'&&s[1][i]=='.') {
			if (i+1<n&&s[1][i+1]=='.') {
				s[1][i]='#';
				s[1][i+1]='#';
			} else {
				puts("None");
				return;
			}
		}
	}
	per(i,0,n) {
		if (s[0][i]=='.'&&s[1][i]=='#') {
			if (i>0&&s[0][i-1]=='.') {
				s[0][i]='#';
				s[0][i-1]='#';
			} else {
				puts("None");
				return;
			}
		} else if (s[0][i]=='#'&&s[1][i]=='.') {
			if (i>0&&s[1][i-1]=='.') {
				s[1][i]='#';
				s[1][i-1]='#';
			} else {
				puts("None");
				return;
			}
		}
	}
	rep(i,0,n) if (s[0][i]=='.') {
		assert(s[1][i]=='.');
		if (i+1<n&&s[0][i+1]=='.') {
			puts("Multiple");
			return;
		}
	}
	puts("Unique");
}

int _;
int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}
