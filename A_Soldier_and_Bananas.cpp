#include<bits/stdc++.h>
using namespace std;

int main () {
    int k, n, w; cin >> k >> n >> w;
    int amt = 0;
    
    for (int i = 1; i <= w; i++) amt += i * k;

    cout << (amt > n ? amt - n : 0) << endl;

    return 0;
}