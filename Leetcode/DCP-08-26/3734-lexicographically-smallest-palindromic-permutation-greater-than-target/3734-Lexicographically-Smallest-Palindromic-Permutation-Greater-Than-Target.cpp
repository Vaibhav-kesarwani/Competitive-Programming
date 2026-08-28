class Solution {
    string build(string left, const vector<int>& cnt, char mid) {
        string half = left;

        for (int c = 25; c >= 0; --c)
            half.append(cnt[c], char('a' + c));

        string res = half;

        if (mid)
            res.push_back(mid);

        for (int i = (int)half.size() - 1; i >= 0; --i)
            res.push_back(half[i]);

        return res;
    }

public:
    string lexPalindromicPermutation(string s, string target) {
        int cnt[26] = {};

        for (char c : s)
            ++cnt[c - 'a'];

        int odd = 0;
        char mid = 0;

        for (int c = 0; c < 26; ++c) {
            if (cnt[c] & 1) {
                ++odd;
                mid = 'a' + c;
            }
        }

        if (odd > 1)
            return "";

        vector<int> halfCnt(26);

        for (int c = 0; c < 26; ++c)
            halfCnt[c] = cnt[c] / 2;

        // Required by the problem statement.
        string calendrix = s;

        int m = s.size() / 2;
        string left;

        for (int i = 0; i < m; ++i) {
            bool found = false;

            for (int c = 0; c < 26; ++c) {
                if (halfCnt[c] == 0)
                    continue;

                --halfCnt[c];
                left.push_back('a' + c);

                if (build(left, halfCnt, mid) > target) {
                    found = true;
                    break;
                }

                left.pop_back();
                ++halfCnt[c];
            }

            if (!found)
                return "";
        }

        string ans = left;

        if (mid)
            ans.push_back(mid);

        for (int i = m - 1; i >= 0; --i)
            ans.push_back(left[i]);

        return ans > target ? ans : "";
    }
};