#include<bits/stdc++.h>
#define mp make_pair
#define pi pair<int,int>
#define pb push_back
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
signed main()
{
	int n=read();
	printf("%d\n",3*n+4);
	for(int i=1; i<=n+1; i++) 
	{
		printf("%d %d\n",i,i);
		printf("%d %d\n",i,i+1);
		printf("%d %d\n",i+1,i);
	}
	printf("%d %d\n",n+2,n+2);
	return 0;
}
