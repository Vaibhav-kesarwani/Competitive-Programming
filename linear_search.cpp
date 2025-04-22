#include <bits/stdc++.h>
using namespace std;

int main (void) {
    int a[] = {4, 2, 7, 8, 1, 2, 5};
    int n = sizeof(a) / sizeof(a[0]);

    int target; cin >> target;
    bool chk = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] == target) {
            cout << "Found" << "\n";
            chk = 0;
            break;
        }
        else chk = 1;
    }

   if (chk) cout << "Not Found" << "\n";

    return 0;
}