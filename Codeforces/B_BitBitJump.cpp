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
int a[100003];
signed main()
{
	int n=read();
	for(int i=0,j=0; i<16; ++i)
	{
		a[j*1024+i*3+0]=65520+i;
		a[j*1024+i*3+1]=(j*1024+i*3+2)*16+10;
		int k=((n>>i)&1)^1;
		a[j*1024+i*3+2]=(i+1)*3;
		a[k*1024+(i+1)*3+0]=0;
		a[k*1024+(i+1)*3+1]=65520;
		a[k*1024+(i+1)*3+2]=65535;
		j=k^1;
		if(i==15)
		{
			k^=1;
			a[k*1024+(i+1)*3+0]=15;
			a[k*1024+(i+1)*3+1]=65520;
			a[k*1024+(i+1)*3+2]=65535;
		}
		
	}
	auto print=[&](int x)
	{
		if(x<10) printf("%d",x);
		else printf("%c",(x-10)+'a');
		return ;
	};
	// a[0]=65520;
	for(int i=0; i<2000; ++i)
	{
		print(a[i]/16/16/16);
		print((a[i]/16/16)%16);
		print((a[i]/16)%16);
		print(a[i]%16);
		printf(" ");
	}
	return 0;
}