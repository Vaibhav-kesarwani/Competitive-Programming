#include<bits/stdc++.h>
using namespace std;

int main () {
    int n, h; cin >> n >> h;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int cnt = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] > h) cnt+= 2;
        else cnt++;
    }

    cout << cnt << endl;

    return 0;
}