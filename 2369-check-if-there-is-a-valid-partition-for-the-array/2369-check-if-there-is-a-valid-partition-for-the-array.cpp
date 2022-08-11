class Solution {
public:
    bool solve(int i, vector<int>& nums, vector<int>& dp) {
        if (i == nums.size()) {
            return true;
        }
        if (dp[i] != -1) {
            return dp[i];
        }
        bool ok = false;
        if (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
            ok |= solve(i + 2, nums, dp);
        }
        if (i + 2 < nums.size()) {
            if (nums[i] == nums[i + 1] && nums[i + 1] == nums[i + 2]) {
                ok |= solve(i + 3, nums, dp);
            }
            if (nums[i + 1] - nums[i] == 1 && nums[i + 2] - nums[i] == 2) {
                ok |= solve(i + 3, nums, dp);
            }
        }
        dp[i] = ok;
        return dp[i];
    }
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        return solve(0, nums, dp);
    }
};