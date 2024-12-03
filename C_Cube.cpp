#include<bits/stdc++.h>
using namespace std;

const int N=12;

int n;

int a[N][N][N];

int f[1<<N][1<<N];

vector<int> w[N+1];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            for(int k=0;k<n;k++)
                cin>>a[i][j][k];
    for(int S=0;S<(1<<n);S++)
        w[__builtin_popcount(S)].push_back(S);
    
    for(int p=0;p<=n;p++)
        for(auto x:w[p])
            for(auto y:w[p])
                f[x][y]=1e9;
    f[0][0]=0;
    for(int i=0;i<n;i++)
    {
        for(auto S:w[i])
            for(auto T:w[i])
            {
                for(int x=0;x<n;x++)
                    if(!(S>>x&1))
                        for(int y=0;y<n;y++)
                            if(!(T>>y&1))
                                f[S^(1<<x)][T^(1<<y)]=min(f[S^(1<<x)][T^(1<<y)],f[S][T]+a[i][x][y]);
            }
    }
    int ans=1e9;
    for(auto x:w[n])
        for(auto y:w[n])
            ans=min(ans,f[x][y]);
    cout<<ans<<"\n";
}