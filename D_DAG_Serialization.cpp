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

const int N=101000;
PII eg[N];
int n,m,ind[N],rk[N],wt[N];
VI e[2][2],g[N];
char s1[20],s2[20];
PII pd[N];
int main() {
	scanf("%d",&n);
	int se=0;
	rep(i,1,n+1) {
		scanf("%s%s",s1,s2);
		if (s2[0]=='t') {
			se+=1;
			if (s1[0]=='s') pd[i]=mp(0,1),wt[i]=2;
			else pd[i]=mp(1,0),wt[i]=0;
		} else {
			if (s1[0]=='s') pd[i]=mp(1,1),wt[i]=1;
			else pd[i]=mp(0,0),wt[i]=3;
		}
		//printf("!! %d %d->%d\n",i,pd[i].fi,pd[i].se);
		e[pd[i].fi][pd[i].se].pb(i);
	}
	scanf("%d",&m);
	rep(i,0,m) {
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].pb(v);
		eg[i]=mp(u,v);
	}
	auto gettop=[&]() {
		rep(i,1,n+1) ind[i]=0;
		rep(u,1,n+1) for (auto v:g[u]) ind[v]+=1;
		priority_queue<PII> q;
		rep(i,1,n+1) if (ind[i]==0) q.push(mp(wt[i],i));
		VI ord;
		while (!q.empty()) {
			int u=q.top().se;
			q.pop();
			ord.pb(u);
			for (auto v:g[u]) {
				--ind[v];
				if (ind[v]==0) q.push(mp(wt[v],v));
			}
		}
		return ord;
	};
	auto output=[&](VI v) {
		if (SZ(v)<n) {
			puts("-1"); exit(0);
		}
		rep(i,0,n) rk[v[i]]=i; 
		rep(i,0,m) {
			auto [u,v]=eg[i];
			if (rk[u]>rk[v]) {
				puts("-1"); exit(0);
			}
		}
		rep(i,1,n) if (pd[v[i-1]].se!=pd[v[i]].fi) {
			puts("-1"); exit(0);
		}
		rep(i,0,n) printf("%d ",v[i]); puts("");
		exit(0);
	};
	if (se==0) {
		if (SZ(e[1][1])) { puts("-1"); return 0; }
		auto ord=gettop();
		output(ord);
	}
	if (se==1) {
		if (SZ(e[0][1])!=1) { puts("-1"); return 0; }
		int p=e[0][1][0];
		rep(i,1,n+1) {
			if (pd[i]==mp(0,0)) g[i].pb(p);
			if (pd[i]==mp(1,1)) g[p].pb(i);
		}
		auto ord=gettop();
		output(ord);
	}
	if (se==2) {
		if (SZ(e[0][1])!=1||SZ(e[1][0])!=1) {
			puts("-1"); return 0;
		}
		int p1=e[0][1][0],p2=e[1][0][0];
		g[p1].pb(p2);
		rep(i,1,n+1) if (pd[i]==mp(1,1)) {
			g[p1].pb(i); g[i].pb(p2);
		}
		rep(i,0,m) {
			auto [u,v]=eg[i];
			if (pd[u]==mp(0,0)&&pd[v].fi==1) {
				g[u].pb(p1);
			}
			if (pd[u].se==1&&pd[v]==mp(0,0)) {
				g[p2].pb(v);
			}
		}
		auto ord=gettop();
		output(ord);
	}
}