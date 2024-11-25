#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 2e5 + 5;
 
int n, x;
int deg[N];
vector<int> g[N];
 
int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		memset(deg, 0, sizeof(deg));
		cin >> n >> x;
		for(int i = 1; i <= n - 1; i++)
		{
			int u, v;
			cin >> u >> v;
			deg[u]++, deg[v]++;
		}
		if(deg[x] <= 1)
			cout << "Ayush" << endl;
		else
		{
			if(n % 2)
				cout << "Ashish" << endl;
			else
				cout << "Ayush" << endl;
		}
	}
	return 0;
}