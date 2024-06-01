#include <bits/stdc++.h>
using namespace std;

#define ll long long int

void solve()
{
    ll n;
    cin >> n;

    ll neg = 0, pos = 0;
    for (ll i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        if (a < 0)
        {
            neg++;
        }
        else
        {
            pos++;
        }
    }
    ll op = 0;
    while (pos < neg || neg % 2 != 0)
    {
        neg--;
        pos++;
        op++;
    }
    cout << op << endl;
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}