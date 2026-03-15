/*
vaibhav_404
*/

#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main () {
    int t; cin >> t;
    while (t-- > 0) {
        int n, k, p, m; cin >> n >> k >> p >> m; p--;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        deque<pair<int, bool>> dq;
        for (int i = 0; i < n; i++) {
            dq.push_back({a[i], (i == p)});
        }

        ll total{}, curr = m;

        while (1) {
            int pos = -1, miniVal = 1e9, miniIdx = -1;

            for (int i = 0; i < k; i++) {
                if (dq[i].second) pos = i;
                else {
                    if (dq[i].first < miniVal) {
                        miniVal = dq[i].first;
                        miniIdx = i;
                    }
                }
            }

            if (pos != -1) {
                if (curr >= dq[pos].first) {
                    curr -= dq[pos].first;
                    total++;

                    pair<int, bool> play = dq[pos];
                    dq.erase(dq.begin() + pos);
                    dq.push_back(play);
                }
                else break;
            }
            else {
                if (curr >= miniVal) {
                    curr -= miniVal;

                    pair<int, bool> play = dq[miniIdx];
                    dq.erase(dq.begin() + miniIdx);
                    dq.push_back(play);
                }
                else break;
            }

            if (total > m) break;
        }

        cout << total << endl;
    }

    return 0;
}