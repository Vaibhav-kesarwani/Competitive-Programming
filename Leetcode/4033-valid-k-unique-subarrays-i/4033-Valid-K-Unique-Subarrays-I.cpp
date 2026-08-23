class Solution {
public:
    vector<bool> validSubarrays(vector<int>& nums, int k, vector<vector<int>>& queries) {
        int n = nums.size();
        int q = queries.size();
        vector<int> vals = nums;

        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        vector<int> a(n);

        for (int i = 0; i < n; i++) {
            a[i] = lower_bound(vals.begin(), vals.end(), nums[i]) - vals.begin();
        }

        int block = max(1, (int)sqrt(n));
        vector<array<int, 3>> qs;

        for (int i = 0; i < q; i++) qs.push_back({queries[i][0], queries[i][1], i});

        sort(qs.begin(), qs.end(), [&](const auto &a, const auto &b) {
            int ba = a[0] / block, bb = b[0] / block;

            if (ba != bb) return ba < bb;
            if (ba & 1) return a[1] > b[1];

            return a[1] < b[1];
        });

        vector<int> fq(vals.size());
        int l = 0, r = -1;
        int d = 0, odd = 0;

        auto add = [&](int x) {
            if (fq[x] == 0) d++;
            if (fq[x] % 2 == 0) odd++;
            else odd--;

            fq[x]++;
        };

        auto remove = [&](int x) {
            if (fq[x] % 2 == 0) odd++;
            else odd--;

            fq[x]--;

            if (fq[x] == 0) d--;
        };

         vector<bool> ans(q, 0);

        for (auto [ql, qr, idx] : qs) {
            while (r < qr) {
                r++;
                add(a[r]);
            }

            while (r > qr) {
                remove(a[r]);
                r--;
            }

            while (l < ql) {
                remove(a[l]);
                l++;
            }

            while (l > ql) {
                l--;
                add(a[l]);
            }
            
            if (d == k and odd == 0) ans[idx] = 1;
        }

        return ans;
    }
};