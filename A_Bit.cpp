#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    int t;
    cin >> t;
    int sum = 0;

    while (t--)
    {
        string s;
        cin >> s;
        
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '+')
            {
                sum++;
                break;
            }
            else if (s[i] == '-')
            {
                sum--;
                break;
            }
        }
    }

    cout << sum << endl;
}