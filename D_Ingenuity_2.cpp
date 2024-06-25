#include <bits/stdc++.h>
#define int long long
#define For(i, l, r) for (int i = l; i <= r; ++i)
#define foR(i, r, l) for (int i = r; i >= l; --i)
using namespace std;
const int N = 110;
const int mod = 1e18;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int f = 1;
    std::map<int, int> mp;
    For(i, 0, s.size() - 1)
    {
        if (s[i] == 'N')
            mp[1]++;
        else if (s[i] == 'S')
            mp[2]++;
        else if (s[i] == 'E')
            mp[3]++;
        else if (s[i] == 'W')
            mp[4]++;
    }
    if (s.size() == 2)
    {
        if (s[0] != s[1])
        {
            cout << "NO\n";
            return;
        }
    }
    if ((mp[1] + mp[2]) % 2)
    {
        cout << "NO\n";
        return;
    }
    if ((mp[3] + mp[4]) % 2)
    {
        cout << "NO\n";
        return;
    }

    std::map<int, int> mp2;
    For(i, 0, s.size() - 1)
    {
        if (s[i] == 'N')
        {
            mp2[1]++;
            if (mp[1] % 2 && mp2[1] == mp[1])
                cout << "R";
            else if (mp2[1] % 2)
                cout << "R";
            else
                cout << "H";
        }
        else if (s[i] == 'S')
        {
            mp2[2]++;
            if (mp[2] % 2 && mp2[2] == mp[2])
                cout << "R";
            else if (mp2[2] % 2)
                cout << "R";
            else
                cout << "H";
        }
        else if (s[i] == 'E')
        {
            mp2[3]++;
            if (mp[3] % 2 && mp2[3] == mp[3])
                cout << "H";
            else if (mp2[3] % 2)
                cout << "H";
            else
                cout << "R";
        }

        else if (s[i] == 'W')
        {
            mp2[4]++;
            if (mp[4] % 2 && mp2[4] == mp[4])
                cout << "H";
            else if (mp2[4] % 2)
                cout << "H";
            else
                cout << "R";
        }
    }
    cout << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}