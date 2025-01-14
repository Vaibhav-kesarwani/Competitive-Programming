#include <iostream>

using namespace std;

int main(){
	int t; //read the number of test cases
	cin >> t;
	while(t--){
		long long n, x, k; //read n, x, k for each test case
		cin >> n >> x >> k;
		if(2*k>=x*(x+1) && 2*k<=n*(n+1)-(n-x)*(n-x+1)){ //check if k is between the minimum and maximum sum 
			cout << "YES\n";
		}
		else cout << "NO\n";
	}	
}