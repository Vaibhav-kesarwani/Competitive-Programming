#include <bits/stdc++.h>
#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>
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
int max_of_three(int a, int b, int c) {
    return max(a, max(b, c));
}

void Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        vector<int> v(3);
        cin >> v[0] >> v[1] >> v[2];
        if ((v[0] + v[1] + v[2]) % 2 == 1)
        {
            cout << "-1\n";
            continue;
        }

        cout << (v[0] + v[1] + v[2] - max_of_three(0LL, v[2] - v[0] - v[1], 0LL)) / 2 << "\n";
    }
}

signed main()
{
    Code By Vaibhav
    // int Bhai_Test_Case_Hai_Ya;
    // cin >> Bhai_Test_Case_Hai_Ya;
    // while (Bhai_Test_Case_Hai_Ya-- > 0)
    Solve_Karo_Jaldi_Sa_Dusra_Bhi_Karna_Hai();

    return 0;
}