#include <bits/stdc++.h>

using  namespace std;
using Long = long long;
const Long maximo = 100000000000000ll;

int main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string cad;
	Long money;

	cin >> cad;

	vector <Long> need(3);
	vector <Long> have(3);
	vector <Long> cost(3);

	for (int i = 0; i < cad.size(); ++i)
	{
		if(cad[i] == 'B')
			need[0]++;

		if(cad[i] == 'S')
			need[1]++;

		if(cad[i] == 'C')
			need[2]++;
	}

	for (int i = 0; i < 3; ++i)
		cin >> have[i];
	
	for (int i = 0; i < 3; ++i)
		cin >> cost[i];

	cin >> money;
	

	Long minBurger = 0;
	Long maxBurger = maximo;
	Long middle;
	Long din = 0ll;
	Long ans = 0ll;
	Long aux = 0;

	while(minBurger <= maxBurger){

		din = 0ll;

		middle = (minBurger + maxBurger) / 2ll;

		for (int i = 0; i < 3; ++i)
		{
			aux = need[i] * middle;
			aux = have[i] - aux;

			if(aux < 0)
				din += abs(aux) * cost[i];
		}

		if(din <= money){

			ans = middle;
			minBurger = middle + 1ll;

		}
		else{
			maxBurger = middle - 1ll;
		}


	}

	cout << ans;

	return 0;
}