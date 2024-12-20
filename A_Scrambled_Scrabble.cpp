#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	string S;
	cin >> S;
	vector<int> f(26);
	for(char& c : S) f[c-'A']++;

	int N = 'N' - 'A';
	int G = 'G' - 'A';
	int Y = 'Y' - 'A';
	vector<int> vowels = {'A'-'A', 'E'-'A', 'I'-'A', 'O'-'A', 'U'-'A'};
	auto is_vowel = [&](int c){
		for(int x : vowels) if(x == c) return true;
		return false;
	};
	int ans = 0;
	for(int x = 0; x <= min(f[N], f[G]); x++){
		f[N] -= x;
		f[G] -= x;
		int nv = 0;
		int nc = x;
		for(int i = 0; i < 26; i++){
			if(i == Y) continue;
			if(is_vowel(i)){
				nv += f[i];
			} else {
				nc += f[i];
			}
		}
		f[N] += x;
		f[G] += x;

		int letters = (nv + nc + f[Y]);
		int w = min(nv + f[Y], min((nc + f[Y]) / 2, letters / 3));
		ans = max(ans, 3 * w + min(2*w, x));
	}
	cout << ans << '\n';
}
