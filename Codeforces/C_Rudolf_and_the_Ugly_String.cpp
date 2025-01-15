#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    long long t;
    cin>>t;
    for(long long c=0;c<t;c++){
	long long n;
	cin >> n;
	string s;
	cin >> s;
	vector<long long> va;                 
	for (string sul : {"mapie", "pie", "map"}) {
		for (size_t pos = 0; (pos = s.find(sul, pos)) != string::npos;) {
			s[pos + sul.length() / 2] = '?';
			va.push_back(pos + sul.length() / 2);
		}
	}
	cout << va.size() << endl;
    }
	return 0;
}