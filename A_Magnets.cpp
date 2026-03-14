#include<bits/stdc++.h>
using namespace std;

int main () {
    int n; cin >> n; n--;

    int prev; cin >> prev;
    int cnt = 1;

    while (n--) {
        int curr; cin >> curr;

        if (curr != prev) cnt++;
        
        prev = curr;
    }

    cout << cnt << endl;

    return 0;
}