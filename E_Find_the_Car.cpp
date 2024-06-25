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


void Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai() {
    int n, k, q;
    cin >> n >> k >> q;
    vector<long long> a(k+1), b(k+1);
    a[0] = 0;
    b[0] = 0;
    for(int i = 1; i <= k; i++)
    {
        cin >> a[i];
    }
    for(int i = 1; i <= k; i++)
    {
        cin >> b[i];
    }
    for(int i = 0; i < q; i++)
    {
        long long c;
        cin >> c;
        int l = 0, r = k;
        while(l <= r)
        {
            int mid = l+r>>1;
            if(a[mid] > c)
            {
                r = mid-1;
            }
            else
            {
                l = mid+1;
            }
        }
        if(a[r] == c)
        {
            cout << b[r] << " ";
            continue;
        }
        long long ans = b[r] + (c-a[r])*(b[r+1]-b[r])/(a[r+1]-a[r]);
        cout << ans << " ";
    }
    cout nt
}

signed main () {
    Code By Vaibhav
    int Bhai_Test_Case_Hai_Ya; cin >> Bhai_Test_Case_Hai_Ya; while (Bhai_Test_Case_Hai_Ya-- > 0)
        Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai();

    return 0;
}