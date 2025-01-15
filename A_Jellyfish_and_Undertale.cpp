#include<bits/stdc++.h>

using namespace std;

int n = 0, a = 0, b = 0;
long long ans = 0;

inline void solve(){
	scanf("%d %d %d", &a, &b, &n);
	ans = b;
	for(int i = 0, x = 0 ; i < n ; i ++){
		scanf("%d", &x);
		ans += min(a - 1, x);
	}
	printf("%lld\n", ans);
}

int T = 0;

int main(){
	scanf("%d", &T);
	for(int i = 0 ; i < T ; i ++) solve();
	return 0;
}