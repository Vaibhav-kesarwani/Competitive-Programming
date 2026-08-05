#include <bits/stdc++.h>
using namespace std;

static const long long NEG = -(1LL << 60);

struct SegTree {
    int n;
    vector<long long> t;

    SegTree(int sz) {
        n = 1;
        while (n < sz) n <<= 1;
        t.assign(2 * n, NEG);
    }

    void update(int pos, long long val) {
        pos += n - 1;
        t[pos] = val;
        for (pos >>= 1; pos; pos >>= 1)
            t[pos] = max(t[pos << 1], t[pos << 1 | 1]);
    }

    long long queryMax() {
        return t[1];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);

        for (int i = 0; i < N; i++) cin >> A[i];

        vector<long long> dp(N + 3, NEG);
        SegTree st(N + 3);

        dp[1] = 0;
        st.update(1, 0); // dp[1] + (1-1)

        for (int x : A) {
            long long best = st.queryMax();

            // Continue current segment
            long long old = dp[x];
            if (old != NEG) {
                dp[x] = NEG;
                st.update(x, NEG);

                if (old > dp[x + 1]) {
                    dp[x + 1] = old;
                    st.update(x + 1, old + x); // dp + (idx-1), idx=x+1
                }
            }

            // Start a new segment before current element
            if (x == 1) {
                if (best > dp[2]) {
                    dp[2] = best;
                    st.update(2, best + 1);
                }
            } else {
                if (best > dp[1]) {
                    dp[1] = best;
                    st.update(1, best);
                }
            }
        }

        cout << st.queryMax() << '\n';
    }

    return 0;
}