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
    int n, k;
    cin >> n >> k;
    long long arr[n + 8] = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (i)
        {
            arr[i] = arr[i - 1] + arr[i];
        }
    }

    int min = 150000010;
    long long minindex = 0;
    for (int i = 0; i <= n - k; i++)
    {
        long long sum = 0;
        if (!i)
        {
            sum = arr[i + k - 1];
            if (sum <= min)
            {
                min = sum;
                minindex = i;
            }
        }
        else
        {
            sum = arr[i + k - 1] - arr[i - 1];

            if (sum <= min)
            {
                min = sum;
                minindex = i;
            }
        }
    }
    cout << ++minindex nt
}

signed main()
{
    Code By Vaibhav
    // int Bhai_Test_Case_Hai_Ya; cin >> Bhai_Test_Case_Hai_Ya; while (Bhai_Test_Case_Hai_Ya-- > 0)
    Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai();

    return 0;
}