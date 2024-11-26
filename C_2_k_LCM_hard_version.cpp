#include <bits/stdc++.h>
using namespace std;

vector<int> solve3(int n) {
    if (n % 2 == 1) return {1, n / 2, n / 2};
    if (n % 4 == 0) return {n / 2, n / 4, n / 4};
    if (n % 2 == 0) return {2, n / 2 - 1, n / 2 - 1};
}

int main() {
    int T;
    cin >> T;
    while (T --> 0) {
        int n, k;
        cin >> n >> k;
        vector<int> added = solve3(n - k + 3);
        for (int i = 0; i < k; ++i) {
            cout << (i <3 ? added[i] : 1) << ' '; // <3
        }
        cout << '\n';
    }
    return 0;
}