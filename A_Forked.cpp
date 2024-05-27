#include <bits/stdc++.h>
using namespace std;
#define int long long
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(0);
#define Vaibhav cout.tie(0);
#define nt << "\n";
#define yes cout << "YES" nt
#define no cout << "NO" nt
const long double pi = 3.141592653589793238;
const int INF = LONG_LONG_MAX;
const int mod = 1000000007;
int gcd(int a, int b){if (b == 0)return a;return gcd(b, a % b);}
int lcm(int a, int b){return (a/gcd(a,b)*b);}


int dx[4] = {-1, 1, -1, 1}, dy[4] = {-1, -1, 1, 1};

void Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai() {
    int a, b; cin >> a >> b;
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    set<pair<int, int>> st1, st2;
    for(int j = 0; j < 4; j++){
        st1.insert({x1+dx[j]*a, y1+dy[j]*b});
        st2.insert({x2+dx[j]*a, y2+dy[j]*b});
        st1.insert({x1+dx[j]*b, y1+dy[j]*a});
        st2.insert({x2+dx[j]*b, y2+dy[j]*a});
    }
    int ans = 0;
    for(auto x : st1) if(st2.find(x) != st2.end()) ans++;

    cout << ans nt
}

signed main () {
    Code By Vaibhav
    int Bhai_Test_Case_Hai_Ya; cin >> Bhai_Test_Case_Hai_Ya; while (Bhai_Test_Case_Hai_Ya-- > 0)
        Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai();

    return 0;
}