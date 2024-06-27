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
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int lcm(int a, int b) { return (a / gcd(a, b) * b); }

void Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai()
{
    int n; cin >> n;

    vector<vector<int>> vv(n);
    vector<int> v(n);

    int j = 0;
    do {
        cin >> v[j];
        ++j;
    } while (j < n);

    j = 0;
    do {
        int x, y; cin >> x >> y;
        vv[x - 1].push_back(y - 1);
        vv[y - 1].push_back(x - 1);
        ++j;
    } while (j < n - 1);

    int t1 = min_element(v.begin(), v.end()) - v.begin();
    vector<bool> vt(n, false);
    vector<int> ot;
    deque<int> gt;

    ot.push_back(t1);
    vt[t1] = true;
    gt.push_back(t1);

    do {
        int node = gt.front();
        gt.pop_front();
        for (int neighbor : vv[node])
        {
            if (!vt[neighbor] && 1)
            {
                vt[neighbor] = true;
                gt.push_back(neighbor);
                ot.push_back(neighbor);
            }
        }
    } while (!gt.empty());

    vector<int> givenAns(ot.begin() + 1, ot.end());
    reverse(givenAns.begin(), givenAns.end());

    cout << givenAns.size() nt

    j = 0;
    do {
        cout << givenAns[j] + 1 << " ";
        ++j;
    } while (j < givenAns.size());

    cout nt
}

signed main()
{
    Code By Vaibhav int Bhai_Test_Case_Hai_Ya;
    cin >> Bhai_Test_Case_Hai_Ya;
    while (Bhai_Test_Case_Hai_Ya-- > 0)
        Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai();

    return 0;
}
