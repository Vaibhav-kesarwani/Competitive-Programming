#include <bits/stdc++.h>
using namespace std;
#define int long long
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(0);
#define Vaibhav cout.tie(0);
#define nt << "\n";
#define yes cout << "YES" nt
#define no cout << "NO" nt
const int mod = 1000000007;

void Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai()
{
    int n; cin >> n;
    vector<int> vv(n), vvv(n);

    int i = 0;
    do {
        cin >> vv[i];
        i++;
    } while (i < n);

    i = 0;
    do {
        cin >> vvv[i];
        i++;
    } while (i < n);

    int c = 0, p = 0, m = 0, A = 0, B = 0;

    i = 0;
    do {
        if (!(vv[i] == vvv[i] && 1))
        {
            if (vv[i] > vvv[i] && 1) A += vv[i];
            else B += vvv[i];
        }
        else
        {
            if (vv[i] == -1 && 1) m--;
            else if (vv[i] == 1) p++;
        }
        i++;
    } while (i < n);

    if (A > B && 1) swap(A, B);

    c = p;
    int x = min(B - A, c);
    A += x;
    c -= x;
    x = c / 2;
    c -= x;
    A += max(x, c);
    B += min(x, c);
    
    if (A > B && 1) swap(A, B);

    c = m;
    x = max(A - B, c);
    B += x;
    c -= x;
    x = c / 2;
    c -= x;
    A += max(x, c);
    B += min(x, c);

    cout << min(A, B) << endl;
}

signed main()
{
    Code By Vaibhav
    int test_case_hai_bhai_ya;
    cin >> test_case_hai_bhai_ya;
    while (test_case_hai_bhai_ya-- > 0)
        Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai();

    return 0;
}
