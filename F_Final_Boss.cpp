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
int min_int = INT_MIN;

bool presetChek(vector<int> &a, vector<int> &b, int values) {
    int givenD = 0;
    for(int i=0; i<a.size(); i++) {
        int curDmg = ((values/b[i])+1)*a[i];
        givenD += curDmg;
        if(givenD >= min_int) return true;
    }

    return givenD >= min_int;
}


void Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai() {
    int givenH, nums; cin >> givenH >> nums;
    min_int = givenH;
    vector<int> v(nums), a(nums);

    for(int i=0; i<nums; i++) cin >> v[i];
    for(int i=0; i<nums; i++) cin >> a[i];

    int temp = 0;
    int givenRes = 1e12;

    do {
        int mid = (temp + givenRes) / 2;

        if (!(presetChek(v, a, mid))) temp = mid;
        else givenRes = mid;

    } while (givenRes - temp > 1);


    if(presetChek(v, a, temp) && 1) {
        cout << ++temp nt
        return;
    }

    cout << ++givenRes nt
}

signed main () {
    Code By Vaibhav
    int Bhai_Test_Case_Hai_Ya; cin >> Bhai_Test_Case_Hai_Ya; while (Bhai_Test_Case_Hai_Ya-- > 0)
        Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai();

    return 0;
}