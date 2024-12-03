#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

int n,m;

string s[N];

int dx[]={0,1,0,-1},dy[]={1,0,-1,0};

int d[N][4][4];

queue<tuple<int,int,int> >q;

int gid(int x,int y)
{
    return (x-1)*m+y;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>s[i],s[i]=' '+s[i];
    int S=-1,T=-1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(s[i][j]=='S')
                S=gid(i,j);
            else if(s[i][j]=='T')
                T=gid(i,j);
    memset(d,-1,sizeof(d));
    q.push({S,0,0});
    d[S][0][0]=0;
    while(!q.empty())
    {
        auto [p,e,t]=q.front();
        q.pop();
        int x=(p-1)/m+1,y=(p-1)%m+1;
        for(int u=0;u<4;u++)
        {
            int nx=x+dx[u],ny=y+dy[u];
            if(nx<1||nx>n||ny<1||ny>m||s[nx][ny]=='#')
                continue;
            int np=gid(nx,ny),nd=u,nt=t*(u==e)+1;
            if(nt>3||d[np][nd][nt]!=-1)
                continue;
            q.push({np,nd,nt});
            d[np][nd][nt]=d[p][e][t]+1;
        }
    }
    int ans=1e9;
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            if(d[T][i][j]!=-1)
                ans=min(ans,d[T][i][j]);
    if(ans>1e8)
        ans=-1;
    cout<<ans<<"\n";
}