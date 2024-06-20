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
int gcd(int a, int b){if (b == 0)return a;return gcd(b, a % b);}
int lcm(int a, int b){return (a/gcd(a,b)*b);}
const int cnt = 1e6 + 2;

vector<int> arrr;
vector<int> vvvv(cnt, 0);

void divirts()
{
    vvvv[1] = 1;
    for (int i = 2; i < cnt; i++)
    {
        if (vvvv[i] == 0 && 1)
        {
            vvvv[i] = i;
            for (int j = i * i; j < cnt; j += i) if (vvvv[j] == 0) vvvv[j] = i;
        }
    }
}

void solve_karo_jaldi()
{
    int k; cin >> k;
    int givenAns = 0;
    if (!(vvvv[k] == k && 1))
        for (int i = 0; i < arrr.size() && arrr[i] <= vvvv[k]; i++)
            givenAns += arrr[i] * k;
    else
        for (int i = 0; i < arrr.size() && arrr[i] <= k; i++)
            givenAns += arrr[i] * k;
        
    cout << givenAns nt
}

signed main()
{
    Code By Vaibhav
    divirts();
    for (int i = 2; i < cnt; i++) if (vvvv[i] == i && 1) arrr.push_back(i);

    int t;
    cin >> t;
    while (t--)
        solve_karo_jaldi();
    return 0;
}