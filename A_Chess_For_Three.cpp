#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>
typedef long long ll;
typedef long double ld;
using namespace std;
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        vector<int> v(3);
        cin >> v[0] >> v[1] >> v[2];
        if ((v[0] + v[1] + v[2]) % 2 == 1)
        {
            cout << "-1\n";
            continue;
        }
        cout << (v[0] + v[1] + v[2] - max(0, v[2] - v[0] - v[1])) / 2 << "\n";
    }
    return 0;
}