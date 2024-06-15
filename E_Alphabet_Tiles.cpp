#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include<bits/stdc++.h>
#define pp pair<ll,ll>
#define ll int
#define True 1
#define gcd __gcd
#define range(i,a,b,c) for(ll i=a;i<b;i+=c)
#define int long long
#define lb lower_bound
#define ub upper_bound
#define False 0
#define prmap(m) {for(auto i: m) cout<<(i.fi)<<": "<<i.sec<<"  "; print("")}
#define maxa(p,q) *max_element(p,q)
#define mina(p,q) *min_element(p,q)
#define pq priority_queue<int>
#define all(v) v.begin(),v.end()
#define len(p) p.size()
#define append pb
#define foi(p,n) for(int i=p;i<n;i++)
#define ini(x,y) memset(x,y,sizeof(x))
#define pb push_back
#define fi first
#define sec second
#define mp make_pair
#define tc while(t--)
#define N ((ll)800009)
#define gtc(a,b) cout<<"Case #"<<a<<": "<<b<<endl;
#define va(n) vector<ar<ll,n>>
#define fo(n) for(int i=0;i<n;i++)
#define rev(n) for(int i=n-1;i>=0;i--)
#define foj(m,n) for(int j=m;j<n;j++)
#define ar array
#define vp vector<pair<int,int>>
#define vc vector<int>
#define print(p) cout<<p<<"\n";
#define pr(p) cout<<p<<" ";
#define pr2(p,q) cout<<p<<" "<<q<<endl;
#define pr3(p,q,r) cout<<p<<" "<<q<<" "<<r<<endl;
#define pr4(p,q,r,s) cout<<p<<" "<<q<<" "<<r<<" "<<s<<endl;
#define pra(a) {for(auto i: a) cout<<i<<" "; cout<<endl;}
#define prm(a) {for(auto i: a) pra(i) cout<<endl;}
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define isvalid(i,j,n,m) (1<=i and i<=n and 1<=j and j<=m)
#define gh fflush(stdout)
#define why {print("LOL") return 0;}
using namespace std;


ll n,t,k,maxn,x,y,flag=0,l1,r1,l2,r2,parity[2]={0,0},ok,need,c=0,m;
ll mod=1e9+7,INF=1e18,MAX=5e5;


int dp[1004][26],a[26],fa[1004],inv[1004];


ll power(ll x,ll y){
	if(y==0)
		return 1;
	ll ans=power(x,y/2);
	ans=(ans%mod*ans%mod)%mod;
	if(y%2)
		return (ans%mod*x%mod)%mod;
	else
		return ans;
}

ll rec(ll i,ll j){
	if(i==0) return 1;
	if(j==26) return 0;
	if(dp[i][j]!=-1) return dp[i][j];
	ll ans=0;
	for(int k=0;k<=min(i,a[j]);k++) ans=(ans+rec(i-k,j+1)*inv[k]%mod)%mod;
	return dp[i][j]=ans;
}

signed main()
{

fio
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); 
	freopen("all.txt", "w", stdout);
#endif

t=1;
// cin>>t;
ll uu=t;
fa[0]=inv[0]=1;
mod=998244353;
for(int i=1;i<=1000;i++){
	fa[i]=(i*fa[i-1])%mod;
	inv[i]=power(fa[i],n=mod-2);
}

tc{
	memset(dp,-1,sizeof(dp));
	ll k;
	cin>>k;
	fo(26) cin>>a[i];
	ll ans=0;
	foi(1,k+1) ans=(ans+rec(i,0)*fa[i]%mod)%mod;
	print(ans)
}

return 0;}
