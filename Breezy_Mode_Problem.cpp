#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main()
{

    ios::sync_with_stdio(0);

    cin.tie(0), cout.tie(0);

    int N, Q;
    cin >> N >> Q;

    vector<int> A(N + 1);
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    vector<int> cnt(N + 1);

    long long ans = 0;

    for (int i = 1; i <= N; i++)
        ans += ++cnt[A[i]];

    while (Q--)
    {

        int P, X;
        cin >> P >> X;

        ans -= cnt[A[P]]--;
        A[P] = X;

        ans += ++cnt[A[P]];

        cout << ans << "\n";
    }

    return 0;
}