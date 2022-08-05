class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        /* 
            Sorting is used to minimize the run time for iterating through the nums.
            Once we reach number greater than the target we are looking for, there's no need to search for the rest.
        */
        sort(nums.begin(), nums.end());
        // use unsigned long to prevent integer overflow
        vector<unsigned long> dp(target + 1, 0);
        // standing on the ground also count as one way.
        dp[0] = 1;
        for (int i = 1; i <= target; ++i){
            int ways = 0;
            for (int j = 0; j < nums.size(); ++j){
                int remain = i - nums[j];
                if (remain < 0) {
                    break;
                }
                // the way it can reach the point are always start from the smaller number
                ways += dp[remain];
            }
            dp[i] = ways;
        }
        return dp[target];
    }
};