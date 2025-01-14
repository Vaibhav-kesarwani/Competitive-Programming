#import<bits/stdc++.h>
#define endl '\n'
using namespace std;
int k, n, t, x, y;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	for(cin >> t; t--;)
	{
		cin >> n >> x >> y;
		if(x > y)swap(x, y);
		if(x || !y || (n - 1) % y)
		{
			cout << -1 << endl;
			continue;
		}
		for(int k = 2; k <= n; k += y)
		{
			for(int i = 1; i <= y; i++)cout << k << ' ';
		}
		cout << endl;
	}
}