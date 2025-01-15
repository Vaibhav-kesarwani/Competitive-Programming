#include<bits/stdc++.h>
using namespace std;
 
int main() {
	int t; cin >> t;
	while (t--) {
		int X, Y, K;
		cin >> X >> Y >> K;
		int M = min(X, Y);
		cout << "0 0 " << M << " " << M << endl;
		cout << "0 " << M << " " << M << " 0" << endl;
	}
}