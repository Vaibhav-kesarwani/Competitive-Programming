class Solution {
    const int MOD = 1'000'000'007;

    long long pow(long long x, int n) {
        long long res = 1;
        for (; n; n /= 2) {
            if (n % 2) {
                res = res * x % MOD;
            }
            x = x * x % MOD;
        }
        return res;
    }

public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        if (multiplier == 1) { 
            return move(nums);
        }

        int n = nums.size();
        long long mx = ranges::max(nums);
        vector<pair<long long, int>> h(n);
        for (int i = 0; i < n; i++) {
            h[i] = {nums[i], i};
        }
        auto clone = h;

        int left = k;
        for (auto& [x, _] : h) {
            while (x < mx) {
                x *= multiplier;
                if (--left < 0) {
                    goto outer;
                }
            }
        }
        outer:;

        if (left < 0) {
            h = move(clone);
            ranges::make_heap(h, greater<>()); 
            while (k--) {
                ranges::pop_heap(h, greater<>());
                h.back().first *= multiplier;
                ranges::push_heap(h, greater<>());
            }
            for (auto& [x, j] : h) {
                nums[j] = x % MOD;
            }
            return move(nums);
        }

        k = left;
        long long pow1 = pow(multiplier, k / n);
        long long pow2 = pow1 * multiplier % MOD;
        ranges::nth_element(h, h.begin() + k % n);
        for (int i = 0; i < n; i++) {
            auto& [x, j] = h[i];
            nums[j] = x % MOD * (i < k % n ? pow2 : pow1) % MOD;
        }
        return move(nums);
    }
};