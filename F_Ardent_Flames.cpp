#include <bits/stdc++.h>
using namespace std;
#define int long long
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(0);
#define Vaibhav cout.tie(0);
#define nt << "\n";
#define yes cout << "YES"
#define no cout << "NO"
#define Yes cout << "Yes"
#define No cout << "No"
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

struct HelpStruct {
    int pos;
    int type;
};

void Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai()
{
    int n, m_int, k;
    cin >> n >> m_int >> k;
    int m = m_int;
    vector<int> h(n), x(n);
    int i = 0;
    while (i < n)
    {
        cin >> h[i];
        i++;
    }
    i = 0;
    while (i < n)
    {
        cin >> x[i];
        i++;
    }
    int low = 1, high = 1e9;
    int answer = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        vector<HelpStruct> getHelp;
        i = 0;
        while (i < n)
        {
            int required_damage = (h[i] + mid - 1) / mid;
            switch (required_damage > m)
            {
                case true:
                    i++;
                    continue;
                case false:
                    int delta = m - required_damage;
                    int left = x[i] - delta;
                    int right = x[i] + delta;
                    getHelp.push_back({left, 1});
                    getHelp.push_back({right + 1, -1});
                    break;
            }
            i++;
        }
        if (getHelp.empty())
        {
            low = mid + 1;
            continue;
        }
        sort(getHelp.begin(), getHelp.end(), [](const HelpStruct &a, const HelpStruct &b)
             {
                if (a.pos != b.pos) return a.pos < b.pos;
                return a.type > b.type; });
        int cnt = 0;
        bool found = false;
        i = 0;
        while (i < getHelp.size())
        {
            cnt += getHelp[i].type;
            switch (i + 1 < getHelp.size() && getHelp[i].pos == getHelp[i + 1].pos)
            {
                case true:
                    i++;
                    continue;
                case false:
                    switch (cnt >= k && getHelp[i].pos == (int)getHelp[i].pos)
                    {
                        case true:
                            found = true;
                            break;
                        case false:
                            break;
                    }
            }
            if (found)
            {
                break;
            }
            i++;
        }
        switch (found)
        {
            case true:
                answer = mid;
                high = mid - 1;
                break;
            case false:
                low = mid + 1;
                break;
        }
    }
    cout << answer nt
}

signed main()
{
    Code By Vaibhav int Bhai_Test_Case_Hai_Ya;
    cin >> Bhai_Test_Case_Hai_Ya;
    while (Bhai_Test_Case_Hai_Ya-- > 0)
        Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai();

    return 0;
}
