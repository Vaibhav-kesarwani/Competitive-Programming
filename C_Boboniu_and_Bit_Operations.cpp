#include<bits/stdc++.h>
#define ci const int&
using namespace std;
int n,m,p[210],d[210],ans;
bool Check(ci x){
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j)if(((p[i]&d[j])|x)==x)goto Next;
		return 0;
		Next:;
	}
	return 1;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d",&p[i]);
	for(int i=1;i<=m;++i)scanf("%d",&d[i]);
	ans=(1<<9)-1;
	for(int i=8;i>=0;--i)Check(ans^(1<<i))?ans^=(1<<i):0;
	printf("%d",ans);
	return 0;
}