class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();

        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }

        vector<vector<int>> dp(n, vector<int>(n, 0));

        vector<vector<int>> leftBest(n, vector<int>(n, 0));

        vector<vector<int>> rightBest(n, vector<int>(n, 0));

        vector<int> leftPtr(n);

        vector<int> rightPtr(n);

        for (int i = 0; i < n; ++i) {
            leftBest[i][i] = stoneValue[i];
            rightBest[i][i] = stoneValue[i];

            leftPtr[i] = i - 1;

            rightPtr[i] = i;
        }

        for (int len = 2; len <= n; ++len) {
            for (int l = 0; l + len <= n; ++l) {
                int r = l + len - 1;

                long long total = prefix[r + 1] - prefix[l];

                while (leftPtr[l] + 1 <= r - 1) {
                    int k = leftPtr[l] + 1;
                    long long leftSum = prefix[k + 1] - prefix[l];

                    if (2 * leftSum > total) {
                        break;
                    }

                    ++leftPtr[l];
                }

                while (rightPtr[l] <= r - 1) {
                    int k = rightPtr[l];
                    long long leftSum = prefix[k + 1] - prefix[l];

                    if (2 * leftSum >= total) {
                        break;
                    }

                    ++rightPtr[l];
                }

                int best = 0;

                if (leftPtr[l] >= l) {
                    best = leftBest[l][leftPtr[l]];
                }

                if (rightPtr[l] <= r - 1) {
                    best = max(best, rightBest[rightPtr[l] + 1][r]);
                }

                dp[l][r] = best;

                leftBest[l][r] = max(
                    leftBest[l][r - 1],
                    dp[l][r] + static_cast<int>(total)
                );

                rightBest[l][r] = max(
                    rightBest[l + 1][r],
                    dp[l][r] + static_cast<int>(total)
                );
            }
        }

        return dp[0][n - 1];
    }
};