#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin>>n;
		long long int ans = 0, MAX = INT_MIN;
		for(int i = 0;i < n;i++){
			long long int x;
			cin>>x;
			ans = ans + x;
		}
		for(int i = 0;i < n ;i++){
			long long int x;
			cin >> x;
			ans = ans + x;
			MAX = max(MAX, x);
		}
		cout << ans - MAX << '\n';
	}
}