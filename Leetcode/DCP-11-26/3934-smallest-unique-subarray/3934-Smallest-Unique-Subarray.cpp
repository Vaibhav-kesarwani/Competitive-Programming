class Solution {
public:
    using ll = long long;
    
    bool hasSubarray (vector<int>& nums, int len) {
        int n = nums.size();
        const ll BASE = 100001, MOD = 1000000007;
        unordered_map<ll, int> mp;

        ll hash = 0, po = 1;

        for (int i = 0; i < len; i++) {
            hash = (hash * BASE + nums[i]) % MOD;
            if (i < len - 1) po = (po * BASE) % MOD;
        }

        mp[hash]++;

        for (int i = len; i < n; i++) {
            hash = (hash - nums[i - len] * po % MOD + MOD) % MOD;
            hash = (hash * BASE + nums[i]) % MOD;

            mp[hash]++;
        }

        hash = 0;
        for (int i = 0; i < len; i++) {
            hash = (hash * BASE + nums[i]) % MOD;
        }

        if (mp[hash] == 1) return 1;

        for (int i = len; i < n; i++) {
            hash = (hash - nums[i - len] * po % MOD + MOD) % MOD;
            hash = (hash * BASE + nums[i]) % MOD;

            if (mp[hash] == 1) return 1;
        }

        return 0;
    }
    
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = 1, right = n, ans = n;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (hasSubarray(nums, mid)) {
                ans = mid;
                right = mid - 1;
            }
            else left = mid + 1;
        }

        return ans;
    }
};