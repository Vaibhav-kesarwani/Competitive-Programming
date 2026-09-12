class Solution {
public:
    using P = pair<long long, vector<int>>;

    vector<tuple<int,int,int>> intervals;
    vector<int> nextIndex;
    vector<vector<P>> dp;
    map<tuple<int,int,int>, int> originalIndex;

    // dp[i][k] = best (negative weight, indices) 
    P solve(int i, int k){
        if(i == intervals.size() || k == 0) return {0, {}};

        if(dp[i][k].first != -1) return dp[i][k];

        P skip = solve(i + 1, k);

        auto [left, right, weight] = intervals[i];

        P take = solve(nextIndex[i], k - 1);

        take.first -= weight; // ref : step 5 if you confuse
        take.second.push_back(originalIndex[{left, right, weight}]);
        sort(take.second.begin(), take.second.end());

        return dp[i][k] = min(skip, take);
    }

    vector<int> maximumWeight(vector<vector<int>>& a) {
        // map : stored in sorted order
        for(int i = 0; i < a.size(); i++){
             if (originalIndex.find({a[i][0], a[i][1], a[i][2]})
                != originalIndex.end()){
                    continue; //Skip Dublicate
            }
            originalIndex[{a[i][0], a[i][1], a[i][2]}] = i;
        }

        for(auto &[interval, index] : originalIndex){
            intervals.push_back(interval);
        }

        int n = intervals.size();
        nextIndex.resize(n);

        // Next Valid Interval (non-overlapping)
        for(int i = 0; i < n; i++){
            auto [left, right, weight] = intervals[i];

            nextIndex[i] = upper_bound(
                intervals.begin(),
                intervals.end(),
                make_tuple(right, INT_MAX, INT_MAX)
            ) - intervals.begin();
        }

        dp.assign(n, vector<P>(5, {-1, {}}));

        return solve(0, 4).second;
    }
};