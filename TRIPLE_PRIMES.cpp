#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main()
{

    ios::sync_with_stdio(0);

    cin.tie(0), cout.tie(0);

    const int mx = 1e5;

    vector<int> flg(mx + 1, 1);

    for (int i = 2; i <= mx; i++)
        for (int j = i * 2; j <= mx; j += i)
            flg[j] = 0;

    vector<int> primes;

    for (int i = 3; i <= mx; i++)
        if (flg[i])
            primes.push_back(i);

    int T;
    cin >> T;

    while (T--)
    {

        int N;
        cin >> N;

        N -= 4;

        if (N < 34)
        {

            cout << "No\n";
            continue;
        }

        bool flag = false;

        for (int &p : primes)
        {

            if (p * p * 2 >= N)
                break;

            int r = N - p * p;

            int t = sqrtl(r + 0.5);

            if (flg[t] && t * t == r)
            {

                flag = true;

                break;
            }
        }

        if (flag)
            cout << "Yes\n";

        else
            cout << "No\n";
    }

    return 0;
}