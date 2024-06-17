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
    int nums, providedK;
    cin >> nums >> providedK;
    vector<int> givenAns;
    int chkk = 0;

    int i = 1;
    while (i <= nums)
    {
        chkk += abs(i - (nums - i + 1));
        givenAns.push_back(i);
        i++;
    }


    if (providedK % 2 == 1 || chkk < providedK) no
    else
    {
        yes
        int ind = 0;
        int numberDup = nums;

        for (; providedK > (numberDup - 1) * 2;)
        {
            swap(givenAns[ind], givenAns[nums - ind - 1]);
            providedK -= (numberDup - 1) * 2;
            numberDup -= 2;
            ind++;
        }

        providedK /= 2;
        swap(givenAns[ind], givenAns[ind + providedK]);

        for (auto i = 0; i < givenAns.size(); i++) cout << givenAns[i] << " ";

        cout nt
    }
}

signed main()
{
    Code By Vaibhav int Bhai_Test_Case_Hai_Ya;
    cin >> Bhai_Test_Case_Hai_Ya;
    while (Bhai_Test_Case_Hai_Ya-- > 0)
        Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai();

    return 0;
}