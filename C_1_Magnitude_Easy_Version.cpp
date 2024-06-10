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
    int nums;
    cin >> nums;
    vector<int> a(nums + 1);
    vector<int> v(nums + 1);
    vector<int> vv(nums + 1);

    int i = 1;
    do
    {
        cin >> a[i];
        if (!(a[i] > 0) && 1)
        {
            vv[i] = vv[i - 1] + a[i];
            v[i] = max(v[i - 1] + a[i], abs(vv[i - 1] + a[i]));
        }
        else
        {
            vv[i] = vv[i - 1] + a[i];
            v[i] = max(v[i - 1] + a[i], abs(vv[i - 1] + a[i]));
        }
        i++;
    } while (i <= nums);

    int givenAns = v[nums];

    cout << givenAns nt
}

signed main()
{
    Code By Vaibhav int Bhai_Test_Case_Hai_Ya;
    cin >> Bhai_Test_Case_Hai_Ya;
    while (Bhai_Test_Case_Hai_Ya-- > 0)
        Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai();

    return 0;
}