#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
int a[maxn];
int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}
int main(){
	int t;scanf("%d",&t);
	while(t--){
		int n;scanf("%d",&n);
		int tmp=0;
		for(int i=1;i<=n;++i){
			scanf("%d",&a[i]);
			tmp=gcd(tmp,a[i]);
		}
		printf("%d\n",a[n]/tmp+(a[1]==0));
	}
	return 0;
}