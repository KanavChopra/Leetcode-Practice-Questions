class Solution {
public:
    int solve(vector<int> &a) {
        int n = a.size();
        if (n == 1) {
            return a[0];
        }
        vector<int> dp(n, 0);
        dp[0] = a[0];
        dp[1] = max(a[0], a[1]);
        for (int i = 2; i < n; ++i) {
            dp[i] = max(a[i] + dp[i - 2], dp[i - 1]);
        }
        return dp[n - 1];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        vector<int> first;
        vector<int> second;
        for (int i = 0; i < n; ++i) {
            if (i != 0) {
                second.push_back(nums[i]);
            }
            if (i != n - 1) {
                first.push_back(nums[i]);
            }
        }
        return max(solve(first), solve(second));
    }
};