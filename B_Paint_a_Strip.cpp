#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        for (int ans = 1, cur = 1; ; ans++, cur = cur * 2 + 2) {
            if (cur >= n) {
                cout << ans << '\n';
                break;
            }
        }
    }
    
    return 0;
}