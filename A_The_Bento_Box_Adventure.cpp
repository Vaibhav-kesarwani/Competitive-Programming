#include <bits/stdc++.h>
using namespace std;
int main() {
    int a,b,c,d;cin >> a >> b >> c >> d;
    int f[6] = {0} ;
    f[a] = f[b] = f[c] = f[d] = 1;
    for(int i = 1;i <= 5;i++) {
        if(!f[i]) {
            cout << i << '\n' ; return 0;
        }
    }
}