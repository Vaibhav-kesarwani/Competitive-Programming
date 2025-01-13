#include<bits/stdc++.h>
using namespace std;
int main() {
	int t[5];
	for(int i = 0; i < 5; ++i)
		scanf("%d", &t[i]);
	sort(t, t + 5);
	int best_remove = 0;
	for(int i = 0; i < 5; ++i) {
		if(i + 1 < 5 && t[i] == t[i+1])
			best_remove = max(best_remove, 2 * t[i]);
		if(i + 2 < 5 && t[i] == t[i+2])
			best_remove = max(best_remove, 3 * t[i]);
	}
	printf("%dn", t[0]+t[1]+t[2]+t[3]+t[4]-best_remove);
	return 0;
}