#include<bits/stdc++.h>
using namespace std;
char s[200005];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		scanf("%s",s+1);
		if(n==1){
			puts(s[1]=='1'?"Yes":"No");
			continue;
		}
		if(s[1]=='1'&&s[n]=='1'){
			puts("Yes");
			continue;
		}
		int c0=0,c1=0;
		for(int i=1;i<=n;){
			int j=i;
			while(j<=n&&s[j]==s[i])++j;
			if(s[i]=='0')++c0;
			else c1+=j-i;
			i=j;
		}
		puts(c1>c0?"Yes":"No");
	}
	return 0;
}