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

bool check(vector<int> &v, int mid, int ori)
{
    vector<int> frekbit(31);
    for (int i = 0; i < mid; i++)
    {
        int x = v[i];

        for (int j = 30; j >= 0; j--)
        {
            if (x >= (1 << j))
            {
                x -= (1 << j);
                frekbit[j]++;
            }
        }
    }
    int or2 = 0;
    for (int i = 0; i < frekbit.size(); i++)
    {
        if (frekbit[i] > 0)
        {
            or2 += (1 << i);
        }
    }
    if (or2 != ori)
    {
        return false;
    }
    for (int i = 1; i + mid - 1 < v.size(); i++)
    {
        int x = v[i - 1];
        for (int j = 30; j >= 0; j--)
        {
            if (x >= (1 << j))
            {
                x -= (1 << j);
                frekbit[j]--;
                if (frekbit[j] == 0)
                {
                    or2 -= (1 << j);
                }
            }
        }
        x = v[i + mid - 1];
        for (int j = 30; j >= 0; j--)
        {
            if (x >= (1 << j))
            {
                x -= (1 << j);
                frekbit[j]++;
                if (frekbit[j] == 1)
                {
                    or2 += (1 << j);
                }
            }
        }
        if (or2 != ori)
        {
            return false;
        }
    }
    return true;
}

void Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai()
{
    int n;
    cin >> n;
    vector<int> v(n);
    int ori = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        ori |= v[i];
    }
    int lo = 1;
    int hi = n;
    while (lo < hi)
    {
        int mid = (lo + hi) / 2;
        if (check(v, mid, ori) == true)
        {
            hi = mid;
        }
        else
        {
            lo = mid + 1;
        }
    }
    cout << lo nt
}

signed main()
{
    Code By Vaibhav int Bhai_Test_Case_Hai_Ya;
    cin >> Bhai_Test_Case_Hai_Ya;
    while (Bhai_Test_Case_Hai_Ya-- > 0)
        Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai();

    return 0;
}