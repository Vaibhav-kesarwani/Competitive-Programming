#include<bits/stdc++.h>
using namespace std;

int main () {
    int n; cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) cin >> a[i];

    int maxi = 0, mini = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] > a[maxi]) maxi = i;
        if (a[i] <= a[mini]) mini = i;
    }

    int ans = maxi + n - mini - 1;

    cout << (maxi > mini ? --ans : ans) << endl;

    return 0;
}