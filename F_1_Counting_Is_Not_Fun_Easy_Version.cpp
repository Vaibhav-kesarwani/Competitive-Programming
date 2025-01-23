#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll md = 998244353;

int main()
{
    int t;
    cin >> t;
    vector<ll> ctl(5050);
    ctl[0] = 1;
    for (int n = 1; n < 5050; n++)
    {
        for (int i = 1; i <= n; i++)
        {
            ctl[n] = (ctl[n] + ctl[i - 1] * ctl[n - i] % md) % md;
        }
    }
    while (t--)
    {
        int n;
        cin >> n;
        ll ans = ctl[n];
        cout << ans << " ";
        string s(2 * n + 2, '.');
        s[0] = '(';
        s[2 * n + 1] = ')';
        for (int a = 0; a < n; a++)
        {
            int i, j;
            cin >> i >> j;
            ans = 1;
            s[i] = '(';
            s[j] = ')';
            string stk;
            for (char c : s)
            {
                if (c == ')')
                {
                    int cnt = 0;
                    while (stk.back() != '(')
                    {
                        cnt++;
                        stk.pop_back();
                    }
                    stk.pop_back();
                    ans = (ans * ctl[cnt / 2]) % md;
                }
                else
                    stk += c;
            }
            cout << ans << " \n"[a + 1 == n];
        }
    }
}