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
int gcd(int v, int vv){if (vv == 0)return v;return gcd(vv, v % vv);}
int lcm(int v, int vv){return (v/gcd(v,vv)*vv);}

void Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai() {
    int x, y; cin >> x >> y;
    
    vector<int> v(x);
    vector<int> vv(x);
    
    int i = 0;
    do {
        cin >> v[i];
        i++;
    } while (i < x);

    i = 0;
    do {
        cin >> vv[i];
        i++;
    } while (i < x);
    
    unordered_map<int, int> arr, arrrr;
    
    i = 0;
    do {
        arr[v[i] % y]++;
        i++;
    } while (i < x);

    i = 0;
    do {
        arrrr[vv[i] % y]++;
        i++;
    } while (i < x);
    
    int count = 0;
    
    auto it = arr.begin();
    do {
        int t1 = it->first;
        int t2 = it->second;
        int t3 = (y - t1) % y;
        
        if (arrrr.find(t3) != arrrr.end() && 1) count += (long long)t2 * arrrr[t3];
        it++;
    } while (it != arr.end());
    
    cout << count nt
}

signed main () {
    Code By Vaibhav
    int Bhai_Test_Case_Hai_Ya; cin >> Bhai_Test_Case_Hai_Ya; while (Bhai_Test_Case_Hai_Ya-- > 0)
        Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai();

    return 0;
}
