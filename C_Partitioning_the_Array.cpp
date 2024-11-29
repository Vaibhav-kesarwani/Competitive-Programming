#include <bits/stdc++.h>
using namespace std; 

void solve(){
    int n; 
    cin >> n;

    int A[n];
    for (int &i : A)
        cin >> i;
    
    int ans = 0;
    for (int k = 1; k <= n; k++){
        if (n % k == 0){
            int g = 0;
            for (int i = 0; i + k < n; i++)
                g = __gcd(g, abs(A[i + k] - A[i]));
            ans += (g != 1);
        }
    }
    cout<<ans<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); 
    int tc; 
    cin >> tc;

    while (tc--) 
        solve();
}