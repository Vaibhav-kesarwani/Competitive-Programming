#include <bits/stdc++.h>
using namespace std;

int main(){
        int t;
        cin >> t;
        while(t--){
            int n;
            cin >> n;
            
            int a[n];
            for (int i = 0 ; i < n; i++){
                cin >> a[i];
            }

            vector <long long> dp(n, 0);
    
            map  <long long,long long> value;
    
            long long final_ans = 0;
    
            for (long long i = 0 ; i < n ; i++){
                if (i > 0) dp[i] = dp[i - 1];
    
                if (value.count(a[i])){
                    dp[i] += value[a[i]];
                }
    
                value[a[i]] += (i + 1);
                final_ans += dp[i];
            } 
    
            cout << final_ans << endl;
        }
}