#include<bits/stdc++.h>
using namespace std;
int main() {
	int t[5];
	int s = 0;
	for(int i = 0; i < 5; ++i) {
		scanf("%d", &t[i]);
		s += t[i];
	}
	int best = s;
	
	// discard 2 cards
	for(int a = 0; a < 5; ++a)
		for(int b = a + 1; b < 5; ++b)
			if(t[a] == t[b])
				best = min(best, s - 2 * t[a]);
	
	// or discard 3 cards
	for(int a = 0; a < 5; ++a)
		for(int b = a + 1; b < 5; ++b)
			for(int c = b + 1; c < 5; ++c)
				if(t[a] == t[b] && t[a] == t[c])
					best = min(best, s - 3 * t[a]);
	
	printf("%d\n", best);
	return 0;
}
