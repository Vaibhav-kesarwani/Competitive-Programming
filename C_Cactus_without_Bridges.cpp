#include<bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
map<pair<int,int>,int> mp;
pair<int,int> edge[200003];
vector<int> e[200003],g[200003];
int dfn[200003],low[200003],cnt;
int n,m,N;
int stk[200003],top;
bool vis[200003];
int a[200003];
void dfs(int x,int fa=0)
{
    vis[x]=1,dfn[x]=low[x]=++cnt,stk[++top]=x;
    for(int y:e[x]) if(y!=fa)
	{
        if(!vis[y])
		{
			dfs(y,x),low[x]=min(low[x],low[y]);
			if(low[y]>=dfn[x])
			{
				++N;
				while(stk[top]!=y)
					g[N].push_back(stk[top]),
					g[stk[top]].push_back(N),--top;
				g[N].push_back(y),
				g[y].push_back(N),--top;
				g[N].push_back(x),
				g[x].push_back(N);
			}
		}
		else low[x]=min(low[x],dfn[y]);
	}
	return ;
}
int mn=1e9,mx=-1e9;
int b[1<<18];
int id[1<<18],c[1<<18],d[1<<18];
int tag[1<<18];
int to[1<<18];
void dfs2(int x,int fa=0)
{
	for(int y:g[x]) if(y!=fa) dfs2(y,x);
	if(x<=n)
	{
		a[x]=1;
		for(int y:g[x]) if(y!=fa) a[x]^=(a[y]^1);
		// printf("%d %d\n",x,a[x]);
	}
	else
	{
		for(int y:g[x]) if(y!=fa) a[x]^=a[y],b[y]=a[y];
		b[fa]=a[x];
		int sz=g[x].size();
		int p=0;
		for(int i=0; i<sz; ++i)
			if(b[g[x][i]]==0&&b[g[x][(i+1)%sz]]==1) p=i;
		for(int i=0; i<sz; ++i)
			c[i]=b[g[x][(p+i)%sz]],id[i]=g[x][(p+i)%sz];
		d[0]=0;
		// assert(d[0]==0||d[1]==0);
		for(int i=1; i<sz; ++i) d[i]=d[i-1]^(c[i]==0?2:1);
		if(d[0]==d[sz-1]) d[0]=2;
		for(int i=0; i<sz; ++i)
		{
			// printf("%d %d %d\n",id[i],id[(i+1)%sz],d[i]);
			if(id[i]==fa||id[(i+1)%sz]==fa)
				to[x]=min(to[x],d[i]);
			if(id[i]!=fa) to[id[i]]=min(to[id[i]],d[i]);
			if(id[(i+1)%sz]!=fa)
				to[id[(i+1)%sz]]=min(to[id[(i+1)%sz]],d[i]);
		}
	}
}
void dfs3(int x,int fa=0)
{
	int pos=-1;
	int qwq=0;
	int neg=0;
	if(x<=n)
	{
		if(fa)
		{
			if(a[x])
			{
				neg=to[x]+tag[fa]+2;
				pos=to[x]+tag[fa]+2;
				tag[fa]=(neg-=2)-to[x];
			}
			else
			{
				neg=to[x]+tag[fa];
				pos=to[x]+tag[fa];
				tag[fa]=pos-to[x];
				if(qwq) qwq=0,pos+=3;
				else qwq=1,pos++;
			}
		}
		for(int y:g[x]) if(y!=fa)
		{
			if(a[y])
			{
				tag[y]=(neg-=2)-to[y];
			}
			else
			{
				tag[y]=pos-to[y];
				if(qwq) qwq=0,pos+=3;
				else qwq=1,pos++;
			}
		}
		// assert(qwq==0);
	}
	for(int y:g[x]) if(y!=fa) dfs3(y,x);
}
void dfs4(int x,int fa=0)
{
	for(int y:g[x]) if(y!=fa) dfs4(y,x);
	if(x>n)
	{
		// printf("%d %d\n",x,tag[x]);
		// printf("%d %d %d %d\n",x,g[x][0],g[x][1],tag[x]);
		for(int y:g[x]) if(y!=fa) b[y]=a[y];
		b[fa]=a[x];
		int sz=g[x].size();
		int p=0;
		for(int i=0; i<sz; ++i)
			if(b[g[x][i]]==0&&b[g[x][(i+1)%sz]]==1) p=i;
		for(int i=0; i<sz; ++i)
			c[i]=b[g[x][(p+i)%sz]],id[i]=g[x][(p+i)%sz];
		d[0]=0;
		for(int i=1; i<sz; ++i) d[i]=d[i-1]^(c[i]==0?2:1);
		if(d[0]==d[sz-1]) d[0]=2;
		for(int i=0; i<sz; ++i)
		{
			mp[{id[i],id[(i+1)%sz]}]=
			mp[{id[(i+1)%sz],id[i]}]=d[i]+tag[x];
		}
	}
}
vector<int> st[1<<17];
signed main()
{
    n=read(),m=read(),N=n;
    for(int i=1,u,v; i<=m; ++i)
    {
        u=read(),v=read(),
    	edge[i]={u,v};
        e[u].push_back(v),
        e[v].push_back(u);
    }
    dfs(1);
    int cnt=0;
    for(int i=n+1; i<=N; ++i)
    	if(g[i].size()&1) ++cnt;
    if(cnt&1) puts("NO"),exit(0);
	memset(to,0x3f,sizeof(to));  
    dfs2(1);
    dfs3(1);
    dfs4(1);
    // return 0;
    // printf("%d %d %d %d\n",a[10],to[10],a[5],to[5]);
    puts("YES");
    set<int> ST;
    for(auto [_,i]:mp) mn=min(mn,i),mx=max(mx,i),ST.insert(i);
    printf("%d\n",mx-mn+1);
    // for(int i=mn; i<=mx; ++i) assert(ST.count(i));
    for(int i=1; i<=m; ++i)
    {
    	if(!mp.count(edge[i])) swap(edge[i].first,edge[i].second);
    	assert(mp.count(edge[i]));
    	printf("%d ",mp[edge[i]]-mn+1);
    	auto [u,v]=edge[i];
    	int val=mp[edge[i]]-mn+1;
    	st[u].push_back(val);
    	st[v].push_back(val);
    }
    puts("");
	for(int i=1; i<=n; ++i)
	{
		sort(st[i].begin(),st[i].end());
		int sz=st[i].size();
		for(int j=1; j<sz; ++j)
			assert(st[i][j]==st[i][j-1]+1);
	}
	return 0;
}