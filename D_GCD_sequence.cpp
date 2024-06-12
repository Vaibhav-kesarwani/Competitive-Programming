#include<iostream>
#include<cassert>
using namespace std;
int gcd(int a,int b)
{
	while(b)
	{
		int t=a%b;
		a=b;
		b=t;
	}
	return a;
}
int N,A[2<<17];
int B[2<<17];
bool L[2<<17],R[2<<17];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=0;i<N;i++)
		{
			cin>>A[i];
			if(i>0)B[i]=gcd(A[i],A[i-1]);
		}
		B[0]=0;B[N]=(int)1e9;
		L[0]=true;
		for(int i=1;i<=N;i++)
		{
			L[i]=L[i-1]&&B[i-1]<=B[i];
		}
		R[N]=true;
		for(int i=N-1;i>=0;i--)
		{
			R[i]=R[i+1]&&B[i]<=B[i+1];
		}
		bool fn=R[2]||L[N-2];
		for(int i=1;i+1<N;i++)
		{
			int nb=gcd(A[i-1],A[i+1]);
			if(L[i-1]&&B[i-1]<=nb&&nb<=B[i+2]&&R[i+2])fn=true;
		}
		cout<<(fn?"YES\n":"NO\n");
	}
}
