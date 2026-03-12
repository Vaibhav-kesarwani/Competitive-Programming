#include<bits/stdc++.h>
using namespace std;

int main () {
    long long x, y, z; cin >> x >> y >> z;
    long long a = (x + z - 1) / z, b = (y + z - 1) / z;

    cout << a * b << endl;

    return 0;
}