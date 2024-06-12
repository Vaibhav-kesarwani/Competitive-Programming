#include<iostream>
#include<set>
#include<map>
#include<cassert>
using namespace std;
int N,A[2<<17],B[2<<17];
int M,D[2<<17];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=0;i<N;i++)cin>>A[i];
		for(int i=0;i<N;i++)cin>>B[i];
		cin>>M;
		for(int i=0;i<M;i++)cin>>D[i];
		set<int>OK;
		map<int,int>need;
		for(int i=0;i<N;i++)
		{
			if(A[i]==B[i])OK.insert(A[i]);
			else need[B[i]]++;
		}
		bool out=false;
		for(int i=M;i--;)
		{
			int d=D[i];
			auto it=need.find(d);
			if(it!=need.end())
			{
				it->second--;
				if(it->second==0)need.erase(it);
				continue;
			}
			if(i+1<M||OK.find(d)!=OK.end())continue;
			out=true;
			break;
		}
		cout<<(out||!need.empty()?"NO":"YES")<<"\n";
	}
}
