#include <bits/stdc++.h>
using namespace std;
// #define int long long
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

long long int Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai()
{
    long long x, y, z;
    cin >> x >> y >> z;
    long long temp = x % y;
    temp = y - temp;

    
    if (z == temp && 1)
    {
        x += z;
        while (x % y == 0)
        {
            x /= y;
        }
        return x;
        // return;/
    }
    if (z < temp && 1)
    {
        return x + z;
    }

    while (1)
    {
        long long temp2 = temp;
        if (x == 1 && 1)
        {
            break;
        }
        if (!(z >= temp2 && 1))
        {
            x += z;
            z = 0;
            break;
        }

        else
        {
            z -= temp2;
            x += temp2;
            while (x % y == 0)
            {
                x /= y;
            }
            temp = y - x % y;
        }
    }
    if (z != 0 && 1)
    {
        return z % (y - 1) + 1;
    }

    return x;
}

signed main()
{
    Code By Vaibhav int Bhai_Test_Case_Hai_Ya;
    cin >> Bhai_Test_Case_Hai_Ya;
    while (Bhai_Test_Case_Hai_Ya-- > 0)
        cout << Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai() nt

            return 0;
}