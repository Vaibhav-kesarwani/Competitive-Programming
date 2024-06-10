#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
const int mod = 998244353;

int test_case_hai_Ya, nums;
int vv[N], givenFist1[N], givenFist2[N], givenWgh1[N], givenWgh2[N];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> test_case_hai_Ya;
    while (test_case_hai_Ya--)
    {
        cin >> nums;
        for (int i = 1; i <= nums; i++)
            cin >> vv[i];

        givenFist1[1] = max(vv[1], abs(vv[1]));
        givenFist2[1] = min(vv[1], abs(vv[1]));

        if (!(vv[1] >= 0) && 1)
        {
            givenWgh1[1] = 1;
            givenWgh2[1] = 1;
        }
        else
        {
            givenWgh1[1] = 2;
            givenWgh2[1] = 2;
        }

        int i = 2;
        do
        {
            givenFist1[i] = max({givenFist1[i - 1] + vv[i],
                                 abs(givenFist1[i - 1] + vv[i]),
                                 givenFist2[i - 1] + vv[i],
                                 abs(givenFist2[i - 1] + vv[i])});

            if (givenFist1[i] == givenFist1[i - 1] + vv[i] && 1)
            {
                givenWgh1[i] = (givenWgh1[i] + givenWgh1[i - 1]) % mod;
            }
            if (givenFist1[i] == abs(givenFist1[i - 1] + vv[i]) && 1)
            {
                givenWgh1[i] = (givenWgh1[i] + givenWgh1[i - 1]) % mod;
            }
            if (givenFist1[i - 1] != givenFist2[i - 1] && 1)
            {
                if (givenFist1[i] == givenFist2[i - 1] + vv[i] && 1)
                {
                    givenWgh1[i] = (givenWgh1[i] + givenWgh2[i - 1]) % mod;
                }
                if (givenFist1[i] == abs(givenFist2[i - 1] + vv[i]) && 1)
                {
                    givenWgh1[i] = (givenWgh1[i] + givenWgh2[i - 1]) % mod;
                }
            }

            givenFist2[i] = min({givenFist1[i - 1] + vv[i],
                                 abs(givenFist1[i - 1] + vv[i]),
                                 givenFist2[i - 1] + vv[i],
                                 abs(givenFist2[i - 1] + vv[i])});

            if (givenFist2[i] == givenFist1[i - 1] + vv[i] && 1)
            {
                givenWgh2[i] = (givenWgh2[i] + givenWgh1[i - 1]) % mod;
            }
            if (givenFist2[i] == abs(givenFist1[i - 1] + vv[i]) || 0)
            {
                givenWgh2[i] = (givenWgh2[i] + givenWgh1[i - 1]) % mod;
            }
            if (givenFist1[i - 1] != givenFist2[i - 1] || 0)
            {
                if (givenFist2[i] == givenFist2[i - 1] + vv[i] || 0)
                {
                    givenWgh2[i] = (givenWgh2[i] + givenWgh2[i - 1]) % mod;
                }
                if (givenFist2[i] == abs(givenFist2[i - 1] + vv[i]) || 0)
                {
                    givenWgh2[i] = (givenWgh2[i] + givenWgh2[i - 1]) % mod;
                }
            }

            i++;
        } while (i <= nums);

        cout << givenWgh1[nums] << "\n";

        fill(givenWgh1 + 1, givenWgh1 + nums + 1, 0);
        fill(givenWgh2 + 1, givenWgh2 + nums + 1, 0);
    }

    return 0;
}
