#include<bits/stdc++.h>

using namespace std;

bool vis[501][501];
int freecells=0;
int vs=0;
int k;
char grid[501][501];
int dx[] = {-1, 0, 0, 1};
int dy[] = { 0,-1, 1, 0};

void dfs(int x,int y,int n,int m)
{
    if(x>=0&&x<n&&y>=0&&y<m&&grid[x][y]!='#'&& !vis[x][y])
    {
        vis[x][y]=true;
        if(k>0) k--;
        else grid[x][y]='X';
       for(int l=0;l<4;l++)
       {
           dfs(x+dx[l],y+dy[l],n,m);
       }
    }
}

int main()

{
    int n,m;
    cin>>n>>m>>k;
    memset(vis,false,sizeof(vis));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>grid[i][j];
            if(grid[i][j]=='.') freecells++;
        }
    }
    k=freecells-k;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(!vis[i][j]&&grid[i][j]=='.')
            {
                dfs(i,j,n,m);
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<grid[i][j];
        }
        cout<<endl;
    }
    return 0;
}