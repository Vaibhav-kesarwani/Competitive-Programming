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

typedef array<ll,4> point; // a + b sqrt(2)/2 + c * i + d * sqrt(2)/2 * i

point operator + (point a,point b) {
	return {a[0]+b[0],a[1]+b[1],a[2]+b[2],a[3]+b[3]};
}
point operator - (point a,point b) {
	return {a[0]-b[0],a[1]-b[1],a[2]-b[2],a[3]-b[3]};
}
point operator * (point a,ll b) {
	return {a[0]*b,a[1]*b,a[2]*b,a[3]*b};
}
void print(point a) {
	printf("(%lld + %lld sqrt(2)/2, %lld + %lld sqrt(2)/2)\n",a[0],a[1],a[2],a[3]);
}

// 1/2 (sqrt(2) a + b - sqrt(2) c - d) + 1/2 i (sqrt(2) a + b + sqrt(2) c + d)
point rot45(point a) {
	assert((a[1]-a[3])%2==0);
	return {(a[1]-a[3])/2,(a[0]-a[2]),(a[1]+a[3])/2,(a[0]+a[2])};
}

int n;
point pos,dir;
vector<pair<point,point>> seg[4],fsg;
void removedup(vector<pair<point,point>> pc) {
	map<point,vector<point>> e;
	for (auto [x,y]:pc) {
		e[x].pb(y);
		e[y].pb(x);
	}
	vector<pair<point,point>> qc;
	for (auto [key,v]:e) if (SZ(v)==1) {
		auto cur=key;
		auto pre=cur;
		while (1) {
			bool nt=0;
			point nxt;
			for (auto v:e[cur]) if (v!=pre) {
				nxt=v;
				nt=1;
			}
			if (!nt) {
				break;
			}
			pre=cur; cur=nxt;
		}
		if (key<cur) {
			fsg.pb(mp(key,cur));
			//print(key); puts(" -> "); print(cur);
		}
		// key, cur
	}
}
void simplify(vector<pair<point,point>> &fsg) {
	point mn=fsg[0].fi;
	for (auto &[u,v]:fsg) {
		if (u>v) swap(u,v);
		mn=min(mn,u);
		mn=min(mn,v);
	}
	for (auto &[u,v]:fsg) {
		u=u-mn;
		v=v-mn;
	}
	sort(all(fsg));
}

char ss[111];
int d;
int main() {
	pos={0,0,0,0};
	dir={1,0,0,0};
	scanf("%d",&n);
	int dx=0;
	rep(i,0,n) {
		scanf("%s",ss);
		scanf("%d",&d);
		if (ss[0]=='r') {
			rep(j,0,d/45) dir=rot45(dir);
			dx=(dx+d/45)%8;
		} else if (ss[0]=='m') {
			pos=pos+dir*d;
		} else {
			auto p1=pos;
			auto p2=pos+dir*d;
			if (p1<p2) swap(p1,p2);
			seg[dx%4].pb(mp(p1,p2));
			pos=pos+dir*d;
		}
	}
	rep(i,0,4) removedup(seg[i]);
	simplify(fsg);

	auto cur=fsg;
	for (int i=1;i<=8;i++) {
		for (auto &[u,v]:cur) {
			u=rot45(u);
			v=rot45(v);
		}
		simplify(cur);
		/*for (auto &[u,v]:cur) {
			print(u); puts("       -> "); print(v);
		}
		puts("------");*/
		if (cur==fsg) {
			printf("%d\n",i*45);
			return 0;
		}
	}
}