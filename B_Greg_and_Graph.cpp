# include <iostream>
# include <cstdio>
# include <algorithm>
using namespace std;
# define MAXN 505
# define ll long long
ll data[MAXN][MAXN],ans[MAXN];
int del[MAXN],n;
bool f[MAXN];
int main()
{
	//freopen("in","r",stdin);
	while(scanf("%d",&n)==1)
	{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			cin>>data[i][j];
			ans[0]+=data[i][j];
		}
		for(int i=n;i>=1;i--)
			scanf("%d",&del[i]);
		for(int i=0;i<=n;i++)
			f[i]=false;
		for(int x=1;x<=n;x++)
		{
			ans[x]=0;
			int k=del[x];
			f[k]=true;
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
				{
					data[i][j]=min(data[i][j],data[i][k]+data[k][j]);
					if(f[i]&&f[j])
						ans[x]+=data[i][j];
				}
		}
		for(int i=n;i>=1;i--)
			cout<<ans[i]<<" ";
		cout<<endl;
	}
	return 0;

}