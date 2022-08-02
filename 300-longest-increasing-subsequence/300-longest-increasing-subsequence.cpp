class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(1, nums.front());
        for (auto& val : nums) {
            if (val > dp.back()) {
                dp.push_back(val);
            } else {
                *lower_bound(dp.begin(), dp.end(), val) = val;
            }
        }
        return dp.size();
    }
};