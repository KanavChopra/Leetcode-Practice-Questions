class Solution {
    private int solve(int[] nums, int n, int[] dp) {
        if (n < 0) {
            return 0;
        }
        if (n == 0) {
            return nums[n];
        }
        if (dp[n] != -1) {
            return dp[n];
        }
        return dp[n] = Math.max(nums[n] + solve(nums, n - 2, dp), solve(nums, n - 1, dp));
    }
    public int rob(int[] nums) {
        int n = nums.length;
        int[] dp = new int[n + 1];
        Arrays.fill(dp, -1);
        return solve(nums, n - 1, dp);
    }
}