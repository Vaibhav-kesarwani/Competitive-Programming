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
    int n, f;
    cin >> n >> f;
    string s;
    cin >> s;
    unordered_map<string, int> m;
    int j = 1;
    string g(n, '0');
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            if (i - 1 >= 0 && s[i - 1] == '0')
            {
                g[i - 1] = '1';
            }
            if (i + 1 < n && s[i + 1] == '0')
            {
                g[i + 1] = '1';
            }
        }
    }

    set<int> st;
    for (int i = 0; i < n; i++)
    {
        if (g[i] == '1')
        {
            st.insert(i);
        }
    }
    vector<int> dist(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (g[i] == '0')
        {
            int z = 1e9, l = 1e9;
            auto it = st.lower_bound(i);
            if (it != st.end())
            {
                z = *it;
            }
            if (it != st.begin())
            {
                it--;
                l = *it;
            }

            dist[i] = min(abs(z - i), abs(l - i));
        }
    }
    f--;
    string ans;
    for (int i = 0; i < n; i++)
    {

        if (dist[i] > f)
        {
            cout << g[i];
        }
        else
        {

            int z = f - dist[i];
            if (z % 2 == 0)
            {
                cout << 1;
            }
            else
            {
                cout << 0;
            }
        }
    }
    cout << endl;
}

signed main()
{
    Code By Vaibhav int Bhai_Test_Case_Hai_Ya;
    cin >> Bhai_Test_Case_Hai_Ya;
    while (Bhai_Test_Case_Hai_Ya-- > 0)
        Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai();

    return 0;
}