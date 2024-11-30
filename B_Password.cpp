#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define N 200005
#define mem(arr, val) memset(arr, val, sizeof(arr))
#define pii pair<int, int>
using namespace std;

string s;
int len;
vector<int> ans, pi;

void pre_fix() {
    pi.assign(len + 1, 0);
    for(int i = 1; i < len; i ++) {
        int j = pi[i - 1];
        while(j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }
        if(s[i] == s[j]) j ++;
        pi[i] = j; 
    }    
}

void solve(){
    cin >> s;
    len = s.size();
    pre_fix();
    ans.assign(len + 1, 0);
    for (int i = 0; i < len; i++) ans[pi[i]]++; 
    for (int i = len - 1; i > 0; i--) { 
        ans[pi[i - 1]] += ans[i]; 
    }
    for (int i = 0; i <= len; i++) ans[i]++;
    int res = 0;
    int k = pi[len - 1];
    while(k > 0) {
        if(ans[k] >= 3) {
            res = k;
            break;
        } else {
            k = pi[k - 1];
        }
    }
    if(res == 0) {
        cout << "Just a legend";
    } else {
        cout << s.substr(0, res);   
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    solve();
      
    return 0;
}