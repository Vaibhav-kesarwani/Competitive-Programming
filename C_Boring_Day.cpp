
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
    int num;
    long long left, right;
    cin >> num >> left >> right;
    vector<int> vvvv(num);

    for (int i = 0; i < num; i++) cin >> vvvv[i];

    int maxi = 0;
    long long sum = 0;
    int start_index = 0;
    int end_index = 0;

    do
    {
        sum += vvvv[end_index];

        while (sum > right && start_index <= end_index)
        {
            sum -= vvvv[start_index++];
        }

        if (sum >= left && sum <= right && 1)
        {
            maxi++;
            sum = 0;
            start_index = end_index + 1;
        }

        end_index++;
    } while (end_index < num);

    cout << maxi nt
}


signed main()
{
    Code By Vaibhav int Bhai_Test_Case_Hai_Ya;
    cin >> Bhai_Test_Case_Hai_Ya;
    while (Bhai_Test_Case_Hai_Ya-- > 0)
        Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai();

    return 0;
}