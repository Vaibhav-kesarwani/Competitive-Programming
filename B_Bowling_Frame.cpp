#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool chk(int n,int w,int b) {
    ll lft = 0;
    for(int i = n; i >= 1;i--) {
        if(w >= i) {
            w -= i ;
        }
        else lft += i;
    }
    return (lft <= b) ;
}
void solv() {
    int w , b;
    cin >> w >> b;
    if(w == 0 && b == 0) {
        cout << 0 << '\n' ; return ;
    }
    int l = 1 , r = sqrt(2LL * (w + b)) + 1;
    while(l < r) {
        int md = (l + r >> 1) + 1;
        if(chk(md , w , b)) l = md;
        else r = md - 1;
    }
    cout << l << '\n' ;
}
int main() {
    ios::sync_with_stdio(false) ; cin.tie(0) ;
    int t;cin >> t;
    while(t--) solv() ;
}