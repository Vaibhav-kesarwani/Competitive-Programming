#include<bits/stdc++.h>
#include<math.h>
#include<iostream>
using namespace std;
int T,n;
string s;
int main(){
	cin>>T;
	while(T--){
		int ans=-1;
		cin>>n>>s;
		for(int i=0;i<n;i++)
			ans+=((!i&&s[i]=='1')||(i&&s[i]!=s[i-1]));
		cout<<max(0,ans)<<endl;
	}
	return 0;
}
