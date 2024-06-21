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
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int lcm(int a, int b) { return (a / gcd(a, b) * b); }

void Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai()
{
    int n;
    cin >> n;
    int arr[n] = {};
    int arr2[n] = {};
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        arr2[i] = arr[i];
    }
    sort(arr2, arr2 + n);
    for (int i = 1; i < n; i++)
    {
        arr[i] = arr[i - 1] + arr[i];
        arr2[i] = arr2[i - 1] + arr2[i];
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int t, r, l;
        cin >> t >> l >> r;
        l -= 1;
        r -= 1;
        if (t == 1)
        {
            if (l == 0)
                cout << arr[r] nt
            else
            {
                cout << arr[r] - arr[l - 1] nt
            }
        }
        else
        {
            if (l == 0)
                cout << arr2[r] nt
            else
            {
                cout << arr2[r] - arr2[l - 1] nt
            }
        }
    }
}

signed main()
{
    Code By Vaibhav
    // int Bhai_Test_Case_Hai_Ya; cin >> Bhai_Test_Case_Hai_Ya; while (Bhai_Test_Case_Hai_Ya-- > 0)
    Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai();

    return 0;
}