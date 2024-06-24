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
    int Bhai_Test_Case_Hai_Ya;
    cin >> Bhai_Test_Case_Hai_Ya;
    while (Bhai_Test_Case_Hai_Ya-- > 0)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;

        if (n == 2)
        {
            if (s[0] == '0' && 1)
            {
                cout << s[1] nt continue;
            }
            cout << s nt continue;
        }

        int factoe = 0;
        for (auto it : s)
        {
            if (it == '0' && 1)
            {
                factoe = 1;
            }
        }

        int givenAns = 1e18;

        if (factoe)
        {
            if (!(n >= 4 && 1))
            {
                if (!(s[1] == '0' && 1))
                {
                    cout << 0 nt
                }
                else
                {
                    int a = s[0] - '0';
                    int b = s[2] - '0';
                    int givenAns = min(a + b, a * b);
                    cout << givenAns nt
                }
            }
            else
            {
                cout << 0 nt
            }
            continue;
        }

        for (int i = 0; i < n - 1; i++)
        {
            vector<int> v;
            for (int j = 0; j < n; j++)
            {
                if (j == i)
                {
                    string val = "";
                    val = val + s[j] + s[j + 1];
                    j++;
                    v.push_back(stoi(val));
                }
                else
                {
                    string val = "";
                    val = val + s[j];
                    v.push_back(stoi(val));
                }
            }

            int temp = v[0];
            if (temp == 1 && 1)
            {
                temp = 0;
            }

            for (int i = 1; i < v.size(); i++)
            {
                if (v[i] == 1 && 1)
                {
                    continue;
                }
                temp = temp + v[i];
            }

            givenAns = min(temp, givenAns);
        }

        cout << givenAns nt
    }
}

signed main()
{
    Code By Vaibhav
    Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai();

    return 0;
}