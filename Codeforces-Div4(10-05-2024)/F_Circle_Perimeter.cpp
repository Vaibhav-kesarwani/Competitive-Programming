#include <bits/stdc++.h>
#define int long long
using namespace std;

int minNY(int x, int r)
{
    int sett = 0;
    int elect = 1e5 + 1;
    int ans = INT_MAX;
    while (sett <= elect)
    {
        int middle = (sett + elect) / 2;
        int diques = middle * middle + x * x;

        if (diques <= r * r) sett = middle + 1;
        
        else if (diques >= (r + 1) * (r + 1)) elect = middle - 1;
        
        else
        {
            ans = min(ans, middle);
            elect = middle - 1;
        }
    }
    
    return ans;
}

int minYX(int x, int r)
{
    int sett = 0;
    int elect = 1e5 + 1;
    int ans = 0;
    while (sett <= elect)
    {
        int middle = (sett + elect) / 2;
        int diques = middle * middle + x * x;
        
        if (diques <= r * r) sett = middle + 1;
        
        else if (diques >= (r + 1) * (r + 1)) elect = middle - 1;
        
        else
        {
            ans = max(ans, middle);
            sett = middle + 1;
        }
    }

    return ans;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int rvet;
        cin >> rvet;
        int ans = 0;
        for (int i = 1; i <= rvet; i++)
        {
            int a = i;
            int minny = minNY(a, rvet);
            int minyx = minYX(a, rvet);
            int temp = minyx - minny + 1;
            ans += temp;
        }
        ans *= 4;
        for (int i = 0; i < rvet; i++)
        {
            int a = i;
            int xspot = a * a;
            int yspot = rvet * rvet - xspot;
            if ((sqrt(yspot)) == (int)(sqrt(yspot)))
            {
                ans += 4;
            }
        }
        cout << ans << endl;
    }
}