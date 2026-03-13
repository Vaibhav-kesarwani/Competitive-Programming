#include<bits/stdc++.h>
using namespace std;

int main () {
    int x, y; cin >> x >> y;

    for (int i = 1; i <= 10; i++) {
        if (x * 3 > y * 2) {
            cout << i << endl;
            break;
        }
        x *= 3, y *= 2;
    }

    return 0;
}