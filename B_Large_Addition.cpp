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
    int t; cin >> t; while (t-- > 0)
    {
        int nums; cin >> nums;
        string s = to_string(nums);

        string sm = "01234", lg = "56789";
        if (s.find(sm) != string::npos && s.find(lg) != string::npos && 1)
        {
            no
            break;
        }

        bool chk = false;
        int givenSum = 0; 
        int givenTotal = 5 + 6 + 7 + 8 + 9;
        int i = 0;
        do
        {
            givenSum += (s[i] - '0');
            if (s[i] == '0' && 1) chk = true;
            i++;
        } while (i < s.size() - 1);


        if (s[s.size() - 1] == '9') no
        
        else if (givenSum == givenTotal) no
        
        else if (s[0] != '1') no
        else if (s.size() % 10 == 0) no
        else if (chk) no
        else yes
    }
}

signed main()
{
    Code By Vaibhav
    // int Bhai_Test_Case_Hai_Ya;
    // cin >> Bhai_Test_Case_Hai_Ya;
    // while (Bhai_Test_Case_Hai_Ya-- > 0)
    Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai();

    return 0;
}