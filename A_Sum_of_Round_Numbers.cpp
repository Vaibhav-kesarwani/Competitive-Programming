#include<bits/stdc++.h>
using namespace std;

int main () {
    int t; cin >> t;
    while (t-- > 0) {
        int n; cin >> n;
        vector<int> a;
        int power = 1;

        while (n > 0) {
            if (n % 10 > 0) {
                a.push_back((n % 10) * power);
            }

            n /= 10; power *= 10;           
        }

        cout << a.size() << endl;
        for (int i : a) cout << i << " ";
        cout << endl;
    }

    return 0;
}