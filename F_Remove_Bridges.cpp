#include<iostream>
#include<vector>
#include<algorithm>
#include<cassert>
using namespace std;
int N;
vector<int>G[3<<17];
vector<int>P;
int dfs(int u,int p)
{
	int mx=0;
	for(int v:G[u])if(v!=p)
	{
		int t=dfs(v,u)+1;
		if(mx<t)
		{
			if(mx>0)P.push_back(mx);
			mx=t;
		}
		else P.push_back(t);
	}
	return mx;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=0;i<N;i++)G[i].clear();
		for(int i=1;i<N;i++)
		{
			int u,v;cin>>u>>v;u--,v--;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		P.clear();
		int F=dfs(0,-1);
		sort(P.begin(),P.end());
		reverse(P.begin(),P.end());
		int ans=N-1-F;
		int t=0;
		for(int i=1;i<N;i++)
		{
			cout<<ans<<(i+1==N?"\n":" ");
			for(int _=0;_<2;_++)
			{
				if(t<P.size())ans-=P[t++];
			}
		}
	}
}
