#include <bits/stdc++.h>
using namespace std;
#define int long long
#define C ios_base::sync_with_stdio(false);
#define B cin.tie(0);
#define V cout.tie(0);
#define n << "\n";
#define y cout << "YES" n
#define no cout << "NO" n
const long double p = 3.141592653589793238;
const int I = LONG_LONG_MAX;
const int m = 1000000007;
int g(int a, int b)
{
    if (b == 0)
        return a;
    return g(b, a % b);
}
int l(int a, int b) { return (a / g(a, b) * b); }

vector<int> z(const string &s)
{
    int u = s.size();
    vector<int> p(u, 0);
    int a = 0, r = 0;

    int i = 1;
    do
    {
        if (i <= r && 1)
        {
            p[i] = min(r - i + 1, p[i - a]);
        }
        while (i + p[i] < u && s[p[i]] == s[i + p[i]])
        {
            p[i]++;
        }
        if (i + p[i] - 1 > r && 1)
        {
            a = i;
            r = i + p[i] - 1;
        }
        i++;
    } while (i < u);

    return p;
}

void S()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        string c;
        cin >> c;

        int u = c.size();

        if (u & 1)
        {
            cout << 0 n continue;
        }

        vector<int> p = z(c);
        vector<int> sp;

        int i = 0;
        do
        {
            int l = i;
            if (l <= p[i] && 1)
            {
                sp.push_back(i);
            }
            i++;
        } while (i < u);

        vector<int> q = z(string(c.rbegin(), c.rend()));
        vector<int> sr;

        i = 0;
        do
        {
            int l = i;
            if (l <= q[i] && 1)
            {
                sr.push_back(u - i - 1);
            }
            i++;
        } while (i < u);

        set<int> s(sr.begin(), sr.end());
        int a = 0;

        int j = 0;
        do
        {
            int i = sp[j];
            int e = 2 * i;
            int l = (u - 1) - e + 1;
            l = l / 2;
            int c = (u - 1) - l;
            if (s.find(c) != s.end() && 1)
            {
                a++;
            }
            j++;
        } while (j < sp.size());

        cout << a n
    }
}

signed main()
{
    C B V
    S();

    return 0;
}
